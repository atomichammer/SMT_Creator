#include "documentwidget.h"

#include <QFileInfo>
#include <QVBoxLayout>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <QtSvg/QSvgGenerator>
#include "fnumber.h"
#include "qmath.h"
#include "savetobinary.h"

DocumentWidget::DocumentWidget(QWidget *parent, QString filename) :
    QWidget(parent)
{
    QFileInfo *info = new QFileInfo(filename);
    //Settings *settings = Settings::Instance();

    elem = new Elements();
    divisor = 60;

    if(info->suffix() == "qgn")
    {
        elem->loadBinaryFile(filename);
    } else if (info->suffix() == "csv")
    {
        elem->loadCSVFile(filename);
        findMatchGroups();
    }

    view = new MyGView();
    scene = new QGraphicsScene();
    view->setScene(scene);
    connect(scene, SIGNAL(selectionChanged()), this, SLOT(countSelectedItems()));
    connect(view, SIGNAL(mousePos(QPointF)), this, SLOT(acceptCoords(QPointF)));

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(view);

    this->setLayout(layout);

    elem->getVisibleChips();

    updateScene();

    changed = FALSE;
    proxy = new FilterProxyModel;
    proxy->setSourceModel(elem->getGroupsModel());
    connect(getGroupsModel(), SIGNAL(dataChanged(QModelIndex,QModelIndex)), proxy, SLOT(invalidate()));
    elem->updateColors();
}

void DocumentWidget::drawBorders()
{
    Settings *settings = Settings::Instance();
    //whole field
    QPen pen(QColor("black"));
    QGraphicsRectItem *bg = scene->addRect(0, 0, settings->getMaxX()/divisor, settings->getMaxY()/divisor, pen );
    //zero based field
    pen.setColor(QColor("red"));
    QGraphicsRectItem *bg2 = scene->addRect((settings->getMaxX()-settings->getZeroX())/divisor, settings->getZeroY()/divisor, (settings->getZeroX())/divisor, (settings->getMaxY()-settings->getZeroY())/divisor, pen );
    bg->setFlag(QGraphicsItem::ItemIsSelectable, false);
    bg2->setFlag(QGraphicsItem::ItemIsSelectable, false);
}

void DocumentWidget::updateScene()
{
    drawBorders();
    for( int i = 0; i< elem->chips.count(); i++)
    {
        scene->addItem(elem->chips.at(i));
    }
}

void DocumentWidget::addChip(Chip *chip)
{
    elem->addChip(chip);
    scene->addItem(chip);
    changed = true;
}

void DocumentWidget::sortByX()
{
    elem->sortByX();
    changed = true;
}

void DocumentWidget::sortByY()
{
    elem->sortByY();
    changed = true;
}

void DocumentWidget::sortByTape()
{
    elem->sortByTape();
    changed = true;
}

void DocumentWidget::setSelectedTape(int tape)
{
    for(int i=0;i<selectedCount(); i++)
    {
        Chip *chip = dynamic_cast<Chip*>(scene->selectedItems()[i]);
        chip->setTape(tape-1);
    }
    //rescanGroups();
    changed = true;
}

void DocumentWidget::setSelectedGroup(uint id)
{
    for(int i=0;i<selectedCount(); i++)
    {
        Chip *chip = dynamic_cast<Chip*>(scene->selectedItems()[i]);
        chip->setGroupID(id);
    }
    //rescanGroups();
    elem->updateColors();
    changed = true;
}

void DocumentWidget::selectAll()
{
    Chip *chip;
    for (int i = 0; i< elem->itemsCount(); i++)
    {
        chip = static_cast<Chip*>(elem->chips.at(i));
        chip->setSelected(true);
    }
}

void DocumentWidget::findMatchGroups()
{
    QModelIndex index;
    QString name;
    Settings *settings = Settings::Instance();
    QList<ACL> basicGroups = settings->getGroupsACL();
    GroupsModel *groupsModel = getGroupsModel();
    bool match = false;

    for (int i = 0; i < groupsModel->rowCount(QModelIndex()); ++i)
    {

        index = groupsModel->index(i, 2, QModelIndex());
        name = groupsModel->data(index, Qt::DisplayRole).toString().toLower();
        match = false;
        for (int j = 0; j < basicGroups.count(); ++j)
        {
            if(name == basicGroups.at(j).name.toLower())
            {
                int tape = basicGroups.at(j).tape;
                index = groupsModel->index(i, 1, QModelIndex());
                groupsModel->setData(index, tape, Qt::DisplayRole);
                match = true;
                break;
            }
        }

        if (match == true) continue;

        for (int j = 0; j < settings->getGroupsRejectList()->count(); ++j)
        {
            if(name == settings->getGroupsRejectList()->at(j).toLower())
            {
                //set visible to false
                index = groupsModel->index(i, 3, QModelIndex());
                groupsModel->setData(index, false, Qt::DisplayRole);
                //set tape to 0
                index = groupsModel->index(i, 1, QModelIndex());
                groupsModel->setData(index, 0, Qt::DisplayRole);
                match = true;
                break;
            }
        }
        if (match == true ) continue;
        //if no match - set tape to 0
        index = groupsModel->index(i, 1, QModelIndex());
        groupsModel->setData(index, 0, Qt::DisplayRole);
    }
}

void DocumentWidget::selectByGroup(QModelIndex index)
{
    QModelIndex indexSource = proxy->mapToSource(index);
    indexSource = getGroupsModel()->index(indexSource.row(), 0, QModelIndex());
    int groupID = getGroupsModel()->data(indexSource, Qt::DisplayRole).toInt();
    Chip *chip;
    scene->clearSelection();
    for(int i=0;i<elem->itemsCount(); i++)
    {
        chip = static_cast<Chip*>(elem->chips.at(i));
        if(chip->getGroupID() == groupID)
            chip->setSelected(true);
    }
}

void DocumentWidget::deleteSelected()
{
    Chip *chip;
    while(!scene->selectedItems().isEmpty())
    {
        chip = static_cast<Chip*>(scene->selectedItems().takeFirst());
        chip->hide();
        elem->removeChipFromVisible(chip);
        changed = true;
    }

    //rescanGroups();
}

void DocumentWidget::rescanGroups()
{
/*
    Chip *chip;
    groups.clear();
    for(int i = 0; i < elem->itemsCount(); i++)
    {
        chip = static_cast<Chip*>(elem->chips.at(i));
        if(!groups.contains(chip->getTape()))
            groups.append(chip->getTape());
    }
    emit groupsChanged(groups);
//    emit groupsChanged(elem->getGroupsModel());
*/
}

GroupsModel* DocumentWidget::getGroupsModel()
{
    return elem->getGroupsModel();
}

FilterProxyModel* DocumentWidget::getProxyModel()
{
    return proxy;
}

void DocumentWidget::moveSingle(quint32 newValX, quint32 newValY)
{
    if(!scene->selectedItems().isEmpty())
    {
        Chip * chip;
        for(int i = 0; i < scene->selectedItems().count(); i++)
        {
            chip = static_cast<Chip*>(scene->selectedItems().at(i));
            chip->setCoordX(newValX);
            chip->setCoordY(newValY);
        }
        changed = true;
    }
}

void DocumentWidget::moveMultiply(quint32 newValX, quint32 newValY)
{
    qint64 deltaX;
    qint64 deltaY;
    Chip *chip = static_cast<Chip*>(scene->selectedItems().first());

    deltaX = chip->getCoordX() - newValX;
    deltaY = chip->getCoordY() - newValY;
    elem->moveMultiply(deltaX, deltaY);
    changed = true;
}

void DocumentWidget::makeRotate(double rx1, double ry1, double rx2, double ry2)
{
    double ix1 = dynamic_cast<Chip*>(scene->selectedItems().at(0))->getCoordX();
    double iy1 = dynamic_cast<Chip*>(scene->selectedItems().at(0))->getCoordY();
    double ix2 = dynamic_cast<Chip*>(scene->selectedItems().at(1))->getCoordX();
    double iy2 = dynamic_cast<Chip*>(scene->selectedItems().at(1))->getCoordY();
    elem->makeRotate( rx1,  ry1,  rx2,  ry2,  ix1,  iy1,  ix2,  iy2);

    changed = true;
}

DocumentWidget::~DocumentWidget()
{
    scene->clear();
    delete scene;
    delete view;
    delete elem;
    destroy();
}

void DocumentWidget::countSelectedItems()
{
    emit selectionChanged(scene->selectedItems().count());
    if(!scene->selectedItems().isEmpty())
    {
        emit selectionChanged(static_cast<Chip*>(scene->selectedItems().first()));
    }
}

void DocumentWidget::rotateSelected(int angle)
{
    elem->rotateSelected(angle);
}

QList<Chip*> DocumentWidget::getSelectedElements()
{
    return elem->getSelectedChips();
}

void DocumentWidget::pasteElements(QList<Chip *> *pasteBuffer)
{
    for(int i = 0; i < pasteBuffer->length(); i++)
    {
        Chip *orig = pasteBuffer->at(i);
        Chip *chip = new Chip(0, 0, orig->getDesignator(), orig->rotation());
        chip->setCoordX(orig->getCoordX());
        chip->setCoordY(orig->getCoordY());
        chip->setGroupID(orig->getGroupID());
        addChip(chip);
    }
    elem->updateColors();
}

bool DocumentWidget::save()
{
    FNumber *numdialog = new FNumber(this);

    if(numdialog->exec() == QDialog::Accepted)
    {
        QFileDialog *dialog = new QFileDialog();
        dialog->setDefaultSuffix("qgn");
        int num = numdialog->getNum();
        QString name = QString("usrsmt%1.qgn").arg(QString::number(num + 1).rightJustified(2, QChar('0')));
        QString fileName = dialog->getSaveFileName(this, tr("Save File"),
                            name,
                            tr("Data(*.qgn)"));
        if (fileName.isEmpty())
                return false;

        delete dialog;
        saveToBinary(fileName, num, numdialog->selectedOnly());
        delete numdialog;
        changed = false;
        return true;
    }
    return false;
}

bool DocumentWidget::saveToBinary(QString fileName, int num, bool selectedOnly)
{
    QList<Chip *> list;

    for(int i=0;i<elem->chips.count(); i++)
    {
        Chip *chip = elem->chips.at(i);

        if((selectedOnly && !chip->isSelected()) || !chip->isVisible()) continue;

        list.append(chip);
    }

    if(!SaveToBinary::saveToBinary(fileName, num, selectedOnly, &list, elem->getGroupsModel()))
    {
                QMessageBox::warning(this, tr("Application"),
                tr("Cannot write file"));
                return false;
    }
    return true;
}

bool DocumentWidget::saveToSVG()
{
    QFileDialog *dialog = new QFileDialog();
    dialog->setDefaultSuffix("svg");
    QString fileName = dialog->getSaveFileName(this, tr("Save File"),
                                               "noname",
                                                tr("Data(*.svg)"));
    if (fileName.isEmpty())
            return false;

    delete dialog;

    QSvgGenerator svgGen;

    svgGen.setFileName( fileName );
//    int res = (1250 * 25.4) / 380.7;
    float x = 197/(float)divisor;
    float y = 25.4;
    int res = x * y;
    svgGen.setSize(QSize(75000/divisor, 75000/divisor));
    svgGen.setViewBox(QRect(0, 0, 75000/divisor, 75000/divisor));
    svgGen.setTitle(tr("SVG Generator Example Drawing"));
    svgGen.setDescription(tr("An SVG drawing created by the SVG Generator "
                                "Example provided with Qt."));
    svgGen.setResolution(res);
    qDebug() << "Resolution: " << svgGen.resolution();

    QPainter painter( &svgGen );
    scene->render( &painter );
}

//bool DocumentWidget::saveToBinary(QString fileName, int num, bool selectedOnly)
//{
//    QFile file(fileName);
//    if (!file.open(QFile::WriteOnly))
//    {
//        QMessageBox::warning(this, tr("Application"),
//                             tr("Cannot write file %1:\n%2.")
//                             .arg(fileName)
//                             .arg(file.errorString()));
//        return false;
//    }

//    //QString num = ;
//    QString jobname = QString("QingSKY_SMTRUN%1").arg(QString::number(num, 16));

//    QList<quint32> fileData;

//    for(int i=0; i<5; i++)
//    {
//        fileData.append(0xFFFFFFFF);
//    }

//    fileData.append(0x00000001);
//    fileData.append(0x00000001);
//    fileData.append(0xFFFFFFFF);
//    fileData.append(0xFFFFFFFF);
//    fileData.append(0xFFFFFFFF);
//    fileData.append(0xFFFFFFFF);

//    int itemsCount = 0;

//    if(selectedOnly)
//        itemsCount = scene->selectedItems().count();
//    else
//    {
//        for(int i = 0; i < elem->chips.count(); i++)
//        {
//            if(elem->chips.at(i)->isVisible()) itemsCount++;
//        }
//    }
//    fileData.append(itemsCount);

//    for(int i=0; i<5; i++)
//    {
//        fileData.append(0xFFFFFFFF);
//    }

//    int guid = 0;

//    for(int i=0;i<elem->chips.count(); i++)
//    {
//        Chip *chip = elem->chips.at(i);

//        if((selectedOnly && !chip->isSelected()) || !chip->isVisible()) continue;

//        fileData.append(0xFFFFFFFF);
//        fileData.append(0xFFFFFFFF);
//        fileData.append(0xFFFFFFFF);
//        fileData.append(0xBBBBBB11);
//        fileData.append(chip->getTape());
//        fileData.append(chip->getCoordX());
//        fileData.append(chip->getCoordY());
//        fileData.append(chip->rotation());
//    }

//    QByteArray ba;
//    ba.append(jobname);
//    ba.append(QChar(0));

//    for(int i=0;i<fileData.length();i++)
//    {
//        //little endian
//        ba.append(QChar(fileData.at(i) & 0x000000FF));
//        ba.append(QChar((fileData.at(i) & 0x0000FF00) >> 8));
//        ba.append(QChar((fileData.at(i) & 0x00FF0000) >> 16));
//        ba.append(QChar((fileData.at(i) & 0xFF000000) >> 24));
//    }

//    file.write(ba);

//    file.close();

//    return true;
//}

void DocumentWidget::flipH()
{
    elem->flipH();
    changed = true;
}

void DocumentWidget::flipV()
{
    elem->flipV();
    changed = true;
}

void DocumentWidget::rotateSelected(double angle)
{
    const float Pi = 3.14159;
    Chip *chip;
    QList<Chip*> chips = elem->getSelectedChips();
    int count = chips.count();
    //Settings *settings = Settings::Instance();

    for(int i = 0; i < count; i++)
    {
        chip = chips.at(i);
        quint32 x = chip->getCoordX();
        quint32 y = chip->getCoordY();
        signed int sign = 1;
        if(angle<0) sign = -1; angle = abs(angle);

        chip->setCoordX(abs( x*qCos(angle*Pi/180) + sign * y*qSin(angle*Pi/180) ));
        chip->setCoordY(abs( sign * x*qSin(angle*Pi/180) - y*qCos(angle*Pi/180) ));

        chip->setRotation(chip->rotation() + angle);
        if(chip->rotation() > 180) chip->setRotation(chip->rotation() - 360);
        if(chip->rotation() < -180) chip->setRotation(chip->rotation() + 360);
    }
    changed = true;
}

void DocumentWidget::rotateSelectedPersonal(int angle)
{
    Chip *chip;
    QList<Chip*> chips = elem->getSelectedChips();
    int count = chips.count();

    if(count <= 0)
    {
        QMessageBox::warning(this, tr("Application"),
        tr("No Elements Selected!"));
        return;
    }

    for(int i = 0; i < count; i++)
    {
        chip = chips.at(i);
        qreal ang = chip->rotation() + angle;
        if(ang > 180) ang -=360;
        if(ang < -180) ang +=360;

        chip->setRotation(ang);
    }
    changed = true;
}

void DocumentWidget::selectNLastItems(int n)
{
    Chip *chip;
    QList<Chip*> chips = elem->visibleChips;
    int count = chips.count();

    scene->clearSelection();

    for(int i = count-1; i >= n; i--)
    {
        chip = chips[i];
        chip->setSelected(true);
    }
}

void DocumentWidget::testRotate(double angle)
{
    elem->testRotate(angle);
    changed = true;

}

void DocumentWidget::acceptCoords(QPointF point)
{
    Settings *settings = Settings::Instance();

    emit mousePos(QPoint(round(settings->getMaxX() - point.x()*divisor), round(point.y()*divisor)));
}
