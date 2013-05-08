#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "QFileDialog"
#include "QFile"
#include "QDataStream"
#include "QList"
#include "QGraphicsView"
#include "QGraphicsItem"
#include "QGraphicsScene"
#include <QtAlgorithms>
#include <QMessageBox>
#include <csvreader.h>
#include <csvimport.h>
#include "myelem.h"
#include "fnumber.h"
#include "qmath.h"

// c 13 po 8

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    stepsPerMm = ui->sbStepsPerMm->value();
    zeroX = ui->sbZeroX->value();
    zeroY = ui->sbZeroY->value();
    createScene();

    shortcutSelectAll = new QShortcut(QKeySequence(tr("Ctrl+A", "Select All")), this);
    connect(shortcutSelectAll, SIGNAL(activated()), this, SLOT(selectAll()));
    previousDot = 0;

    importCSV = new QAction("Import CSV", this);
    connect(importCSV, SIGNAL(triggered()), this, SLOT(on_pbLoadSMT_clicked()));
    importSMT = new QAction("Import SMT", this);
    connect(importSMT, SIGNAL(triggered()), this, SLOT(on_pushButton_clicked()));
    saveSMT = new QAction("Save SMT", this);
    connect(saveSMT, SIGNAL(triggered()), this, SLOT(save()));
    ui->mainToolBar->addAction(importCSV);
    ui->mainToolBar->addAction(importSMT);
    ui->mainToolBar->addAction(saveSMT);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Select Coords File"),
                "",
                tr("Data (*.qgn)"));
    if (!fileName.isEmpty())
            loadFile(fileName);
}

void MainWindow::loadFile(const QString &fileName)
{
    QFile file(fileName);

    if(!file.open(QIODevice::ReadOnly))
    {
        statusBar()->showMessage(tr("Unable to open file!"), 5000);
    } else {
        statusBar()->showMessage(tr("File Opened!"), 5000);
        QList<quint32> dataList;
        QByteArray str;
        unsigned char c;
        quint32 q;
        QDataStream s(&file);
        s.setByteOrder(QDataStream::LittleEndian);

        for(int i=0;i<16; i++)
        {
            s >> c;
            str.append(c);
        }

        while(true)
        {
            s >> q;
            dataList.append(q);
            if (s.atEnd())
                break;
        }
        file.close();
        //QString t = QString(str);
        ui->lbTotalParts->setText(QString::number(dataList.at(11), 10));

        ELEMENT elem;

        elements.clear();
        footprints.clear();
        ui->lwGroups->clear();
        int k = 0;

        for(int i = 0; i<dataList.length();i++)
        {
            if(dataList.at(i) == 0xbbbbbb11){
                i++;
                elem.tape = dataList.at(i++);
                elem.designator = QString::number(elem.tape, 10) + "_" + QString::number(i, 10);

                //grouping elements by footprint
                if(footprints.contains("Group_" + QString::number(elem.tape+1, 10)))
                {
                    //
                } else
                {
                    footprints.append("Group_" + QString::number(elem.tape+1, 10));
                    k++;
                }

                elem.group_id = k-1;

                unsigned int coord = dataList.at(i++);
                elem.coord_x = coord;
                coord = dataList.at(i++);
                elem.coord_y = coord;
                elem.angle = dataList.at(i++);
                if(elem.angle > 180) elem.angle -=360;
                if(elem.angle < -180) elem.angle +=360;

                elem.dot = new QGraphicsRectItem(-2, -4, 4, 8);
                elem.dot->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);
                elem.dot->setAcceptsHoverEvents(true);
                elem.dot->setPos((maxX - elem.coord_x)/60, (elem.coord_y)/60);

                elem.dot->setBrush(QColor("red"));
                elem.dot->setData(0, elements.length());
                elem.dot->setRotation(elem.angle);

                elem.selected = false;
                elem.deleted = false;
                elements.append(elem);

            }
        }
        ui->lwGroups->addItems(footprints);

        ui->sbCurrentPart->setMaximum(dataList.at(11));
    }

}

void MainWindow::loadElement(unsigned int num)
{
    if(num < elements.length()){
        ui->sbCurrentPart->setValue(num);
        ui->sbCoordX->setValue(elements.at(num).coord_x);

        ui->sbCoordY->setValue(elements.at(num).coord_y);

        ui->sbTape->setValue(elements.at(num).tape + 1);
        ui->sbAngle->setValue(elements.at(num).angle);
        ui->lbDesignator->setText(QString("Current %1").arg(elements.at(num).designator));
    }
}

void MainWindow::on_pushButton_clicked()
{
    openFile();
    drawDots();
}

void MainWindow::on_sbCurrentPart_valueChanged(int num )
{
    loadElement(num);
}

void MainWindow::createScene()
{
    scene = new QGraphicsScene(QRectF(0,0,1280,1024));
    scene->setBackgroundBrush(QBrush(QColor("black")));
    scene2 = new QGraphicsScene(QRectF(0,0,0,0));
    scene2->setBackgroundBrush(QBrush(QColor("black")));

    view = new MyGView();
    view->setMouseTracking(true);
    view->setScene(scene);
    view->setDragMode(QGraphicsView::RubberBandDrag);
    ui->tab->layout()->addWidget(view);
    view->show();
    ui->graphicsView->setScene(scene2);

    connect(view,SIGNAL(emitCoords(QPoint, int)), this, SLOT(acceptCoords(QPoint, int)));
    connect(view, SIGNAL(mousePos(QPoint)), this, SLOT(updateCoords(QPoint)));
    connect(view, SIGNAL(emitKey(int)), this, SLOT(viewKeyPress(int)));
}

void MainWindow::viewKeyPress(int key)
{
    if (key == Qt::Key_Delete){

        deleteDot();
        int num = calcNumElements();
        ui->sbCurrentPart->setMaximum(num);
        ui->lbTotalParts->setText(QString::number(num,10));
    }
}

void MainWindow::deleteDot()
{
    ELEMENT *elem;

    for(int i=0; i<elements.length(); i++)
    {
        elem = &elements[i];
        if(elem->selected && !elem->deleted)
        {
            scene->removeItem(elem->dot);
            elem->selected = false;
            elem->deleted = true;

        }
    }
}

void MainWindow::drawDots()
{
    qDeleteAll(scene->items());
    for(int i=0;i<elements.length();i++)
    {
        if(!elements.at(i).deleted)
            scene->addItem(elements.at(i).dot);
    }
    view->show();

    drawAxis();
}

void MainWindow::drawAxis()
{
    //y-lines
    QPen pen(QColor("white"));
    scene->addLine(maxX/60, zeroY/60, maxX/60, maxY/60, pen);
    scene->addLine((maxX - zeroX)/60, zeroY/60, (maxX - zeroX)/60, maxY/60, pen);
    //x-lines
    scene->addLine((maxX - zeroX)/60, zeroY/60, maxX/60, zeroY/60, pen);
    scene->addLine((maxX - zeroX)/60, (maxY - zeroY)/60, maxX/60, (maxY - zeroY)/60, pen);
    //scene->addRect((maxX - zeroX)/60, zeroY/60, zeroX/60, (maxY - zeroY)/60 );

}

void MainWindow::updateCoords(QPoint point)
{
    this->statusBar()->showMessage(QString("%1:%2").arg(point.x()).arg(point.y()));
}

void MainWindow::acceptCoords(QPoint point, int mod)
{
    if(mod != Qt::ControlModifier)
    {
        //deselecting previous elements
        for(int i=0;i<elements.length(); i++)
        {
            if(!elements.at(i).selected || elements.at(i).deleted) continue;
            //change previous color to red
            elements.at(i).dot->setBrush(QColor("red"));
            elements[i].selected = false;
        }
    }

    if (QGraphicsItem *item = view->itemAt(point))
    {
        //get new dot index
        previousDot = ((QGraphicsRectItem*)item)->data(0).toInt();
        elements[previousDot].selected = !elements[previousDot].selected;
        QColor color;
        if(elements[previousDot].selected)
            color = QColor("green");
        else
            color = QColor("red");

        ((QGraphicsRectItem*)item)->setBrush(QBrush(color));
        loadElement(previousDot);

        /*
        for(int i=0; i<elements.length();i++)
        {
            if(elements.at(i).dot->data(0).toInt() == previousDot)
            {
                elements[i].selected = true;
                qDebug() << "id = " << i << " was selected";
                qDebug() << "deleted = " << elements[i].deleted;
                qDebug() << "prevDot = " << previousDot;
                //load element data to spinboxes
                loadElement(i);
                break;
            }
        }
        */
    }
}

void MainWindow::on_sbZeroX_valueChanged(int val)
{
    zeroX = val;
    loadElement(ui->sbCurrentPart->value());
}

void MainWindow::on_sbZeroY_valueChanged(int val)
{
    zeroY = val;
    loadElement(ui->sbCurrentPart->value());
}

void MainWindow::on_sbStepsPerMm_valueChanged(int val)
{
    stepsPerMm = val;
    loadElement(ui->sbCurrentPart->value());
}

void MainWindow::on_pbLoadSMT_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Select Coords File"),
                "",
                tr("Data (*.csv)"));
    if (!fileName.isEmpty())
    {
        CsvReader *csv = new CsvReader(0,fileName); //
        if (csv->Open()){
            str = csv->CSVRead();

            CSVImport *dialog = new CSVImport(this);
            dialog->setData(str);

            if(dialog->exec() == QDialog::Accepted)
            {
                list = dialog->getList();

                delete dialog;

                fillElements();
                int num = calcNumElements();
                ui->sbCurrentPart->setMaximum(num);
                ui->lbTotalParts->setText(QString::number(num,10));
            }
        }
    }
}

void MainWindow::fillElements()
{
    ELEMENT elem;
    QString fp;

    elements.clear();
    footprints.clear();
    ui->lwGroups->clear();

    if(str.length() > 0){
        for (int i=1;i<str.length();i++)
        {
            //if less than we expect advance to next element
            if(str.at(i).length() < 4) continue;
            //if contains empty fields advance to next element
            if(str.at(i).at(list.at(0)) == "" ||
                str.at(i).at(list.at(1)) == "" ||
                str.at(i).at(list.at(2)) == "" ||
                str.at(i).at(list.at(3)) == "" ||
                str.at(i).at(list.at(4)) == "")  continue;

            //grouping elements by footprint
            fp = str.at(i).at(list.at(4));
            if(footprints.contains(fp)){
               elem.tape = footprints.indexOf(fp);
            } else{
                elem.tape = footprints.length();
                footprints.append(fp);
            }

            elem.group_id = elem.tape;
            elem.designator = str.at(i).at(list.at(0));

            unsigned int coord = prepareNum(str.at(i).at(list.at(1))) * stepsPerMm;
            if(coord > zeroX) continue;
            elem.coord_x = zeroX - coord;
            coord = zeroY + prepareNum(str.at(i).at(list.at(2))) * stepsPerMm;
            if(coord > maxY) continue;
            elem.coord_y = coord;
            elem.angle = (str.at(i).at(list.at(3))).toDouble();
            if(elem.angle > 180) elem.angle -=360;
            if(elem.angle < -180) elem.angle +=360;

            elem.dot = new QGraphicsRectItem(-2, -4, 4, 8);
            elem.dot->setPos((maxX -  elem.coord_x)/60, (zeroY + elem.coord_y)/60);

            elem.dot->setBrush(QColor("red"));
            elem.dot->setData(0, elements.length());
            elem.dot->setRotation(elem.angle);

            elem.selected = false;
            elem.deleted = false;
            elements.append(elem);

            QGraphicsItem *item = new Chip(QColor("red"), 0,0);
            item->setPos(QPointF((maxX -  elem.coord_x)/60, (zeroY + elem.coord_y)/60));
            item->setRotation(elem.angle);
            scene2->addItem(item);


        }
        ui->lwGroups->addItems(footprints);
        drawDots();
    }

}

float MainWindow::prepareNum(QString s)
{
    s.chop(2);
    float f = s.toFloat();
    if(f < 0) f = f*(-1);
    return f;
}


void MainWindow::on_sbCoordX_valueChanged(int newVal)
{
//
}

void MainWindow::on_pbSet_clicked()
{
    //moving coordinates
    signed int newValX = ui->sbCoordX->value();
    signed int newValY = ui->sbCoordY->value();
    if(ui->rbMulti->isChecked())
    {
        signed int deltaX = (signed int)(elements.at(previousDot).coord_x) - newValX;
        signed int deltaY = (signed int)(elements.at(previousDot).coord_y) - newValY;
        for(int i=0; i<elements.length(); i++)
        {
            elements[i].coord_x -= deltaX;
            elements[i].coord_y -= deltaY;
            elements[i].dot->setPos((maxX -  elements[i].coord_x)/60, (zeroY + elements[i].coord_y)/60);
        }
    } else {
        elements[previousDot].coord_x = newValX;
        elements[previousDot].coord_x = newValY;
        elements[previousDot].dot->setPos((maxX -  newValX)/60, (zeroY + newValY)/60);
    }
    view->show();
}

bool MainWindow::save()
{
    FNumber *numdialog = new FNumber(this);

    if(numdialog->exec() == QDialog::Accepted)
    {

        QFileDialog *dialog = new QFileDialog();
        dialog->setDefaultSuffix("qgn");
        num = numdialog->getNum();
        QString name = QString("usrsmt%1.qgn").arg(QString::number(num + 1).rightJustified(2, QChar('0')));
        QString fileName = dialog->getSaveFileName(this, tr("Save File"),
                            name,
                            tr("Data(*.qgn)"));
        if (fileName.isEmpty())
                return false;
        delete numdialog;
        delete dialog;
        return saveToBinary(fileName);
    }
    return false;
}

bool MainWindow::saveToBinary(QString fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly))
    {
        QMessageBox::warning(this, tr("Application"),
        tr("Cannot write file %1:\n%2.")
        .arg(fileName)
        .arg(file.errorString()));
        return false;
    }


    QApplication::setOverrideCursor(Qt::WaitCursor);
    //QString num = ;
    QString jobname = QString("QingSKY_SMTRUN%1").arg(QString::number(num, 16));

    QList<quint32> fileData;

    for(int i=0; i<5; i++)
    {
        fileData.append(0xFFFFFFFF);
    }

    fileData.append(0x00000001);
    fileData.append(0x00000001);
    fileData.append(0xFFFFFFFF);
    fileData.append(0xFFFFFFFF);
    fileData.append(0xFFFFFFFF);
    fileData.append(0xFFFFFFFF);
    fileData.append(calcNumElements());
    for(int i=0; i<5; i++)
    {
        fileData.append(0xFFFFFFFF);
    }

    ELEMENT elem;
    for(int i=0;i<elements.length(); i++)
    {
        if(elements.at(i).deleted) continue;
        elem = elements.at(i);
        fileData.append(0xFFFFFFFF);
        fileData.append(0xFFFFFFFF);
        fileData.append(0xFFFFFFFF);
        fileData.append(0xBBBBBB11);
        fileData.append(elem.tape);
        fileData.append(elem.coord_x);
        fileData.append(elem.coord_y);
        fileData.append(elem.angle);
    }

    QByteArray ba;
    ba.append(jobname);
    ba.append(QChar(0));

    for(int i=0;i<fileData.length();i++)
    {
        //little endian
        ba.append(QChar(fileData.at(i) & 0x000000FF));
        ba.append(QChar((fileData.at(i) & 0x0000FF00) >> 8));
        ba.append(QChar((fileData.at(i) & 0x00FF0000) >> 16));
        ba.append(QChar((fileData.at(i) & 0xFF000000) >> 24));
    }

    //out << fileData;

    file.write(ba);

    QApplication::restoreOverrideCursor();
    file.close();

    return true;
}

void MainWindow::on_pushButton_2_clicked()
{
    save();
}

void MainWindow::on_lwGroups_clicked(QModelIndex index)
{
     QString k = index.data().toString();
     int id = footprints.indexOf(k);

     int tape;
     for(int i=0;i<elements.length(); i++)
     {
         if(elements[i].group_id == id){
             elements[i].dot->setBrush(QBrush(QColor("green")));
             elements[i].selected = true;
             tape = elements[i].tape + 1;
         } else {
             elements[i].selected = false;
             elements[i].dot->setBrush(QBrush(QColor("red")));
         }
     }
     ui->sbGroupTape->setValue(tape);
}

void MainWindow::rotate(int angle)
{
    const float Pi = 3.14159;
    for(int i=0;i<elements.length();i++)
    {
        quint32 x = elements[i].coord_x;
        quint32 y = elements[i].coord_y;


        elements[i].coord_x = x*qCos(angle*Pi/180) + y*qSin(angle*Pi/180);
        elements[i].coord_y = x*qSin(angle*Pi/180) - y*qCos(angle*Pi/180);

        elements[i].angle += angle;
        elements[i].dot->setPos((maxX -  elements[i].coord_x)/60, (zeroY + elements[i].coord_y)/60);
        elements[i].dot->setRotation(elements[i].angle);
    }
}

int MainWindow::calcNumElements()
{
    numOfElements = 0;
    ELEMENT elem;
    foreach(elem, elements){
        if(!elem.deleted) numOfElements++;
    }
    return numOfElements;
}

void MainWindow::removeGroup()
{

}

void MainWindow::restoreGroup()
{
    QString k = ui->lwGroups->currentIndex().data().toString();
    int id = footprints.indexOf(k);

    for(int i=0;i<elements.length(); i++)
    {
        if(elements[i].group_id == id){
            elements[i].dot->setBrush(QBrush(QColor("green")));
            elements[i].selected = true;
            elements[i].deleted = false;
            scene->addItem(elements[i].dot);
        } else {
            elements[i].selected = false;
            elements[i].dot->setBrush(QBrush(QColor("red")));
        }
    }
}

void MainWindow::on_pbSetGroupTape_clicked()
{
    setGroupTape(ui->lwGroups->currentRow(), ui->sbGroupTape->value());
}

void MainWindow::setGroupTape(int group_id, int tape)
{
    for(int i=0;i<elements.length(); i++)
    {
        if(elements[i].group_id == group_id)
        {
            elements[i].tape = tape - 1;
        }
    }
}

void MainWindow::setRotationAngle(int arg)
{
    /*
    for(int i=0;i<elements.length(); i++)
    {
        if(!elements[i].selected) continue;
        elements[i].angle += arg;

        if(elements[i].angle > 180) elements[i].angle -=360;
        if(elements[i].angle < -180) elements[i].angle +=360;
        elements[i].dot->setRotation(elements[i].angle);
    }
    */

    qDebug() << scene->items().count();
    for(int i=0;i<scene->items().count(); i++)
    {
        if(scene->items().at(i)->isSelected())
        {
            qreal ang = scene->items().at(i)->rotation();
            scene->items()[i]->setRotation(ang+arg);
        }
    }
}

void MainWindow::selectAll()
{
    for(int i=0;i<elements.length(); i++)
    {
        if(elements[i].deleted) continue;
        elements[i].selected = true;
        elements[i].dot->setBrush(QBrush(QColor("green")));
    }
}

void MainWindow::on_pbSub90_clicked()
{
    setRotationAngle(-90);
}

void MainWindow::on_pbAdd90_clicked()
{
    setRotationAngle(90);
}

void MainWindow::on_pbRemoveGroup_clicked()
{
    ui->lwGroups->currentItem()->setTextColor(QColor("grey"));
    deleteDot();
    int num = calcNumElements();
    ui->sbCurrentPart->setMaximum(num);
    ui->lbTotalParts->setText(QString::number(num,10));
}

void MainWindow::on_pbRestore_clicked()
{
    ui->lwGroups->currentItem()->setTextColor(QColor("black"));
    restoreGroup();
    int num = calcNumElements();
    ui->sbCurrentPart->setMaximum(num);
    ui->lbTotalParts->setText(QString::number(num,10));
}

void MainWindow::on_pbRotateAll_clicked()
{
    rotate(90);
}
/*
void View::setupMatrix()
{
    qreal scale = qPow(qreal(2), (zoomSlider->value() - 250) / qreal(50));

    QMatrix matrix;
    matrix.scale(scale, scale);
    matrix.rotate(rotateSlider->value());

    graphicsView->setMatrix(matrix);
    setResetButtonEnabled();
}
*/
