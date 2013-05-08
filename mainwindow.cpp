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
#include <QGenericMatrix>
#include <QFileOpenEvent>
#include <QUrl>
#include <QTabWidget>

#include "fnumber.h"
#include "qmath.h"
#include "orderby.h"
#include "newpart.h"
#include "basicsettings.h"
#include "dialogmoverotate.h"
#include "groupedit.h"
#include "basicgroupsdialog.h"
#include "addacldialog.h"
#include "changegroupdialog.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
//
    tabWidget = new QTabWidget;
    tabWidget->setTabsClosable(true);
    ui->gridLayout_5->addWidget(tabWidget,0,0,1,1,0);

    shortcutSelectAll = new QShortcut(QKeySequence(tr("Ctrl+A", "Select All")), this);
    connect(shortcutSelectAll, SIGNAL(activated()), this, SLOT(selectAll()));

    lbCount = new QLabel(tr("Count: 0"));
    statusBar()->addWidget(lbCount);

    lbSelected = new QLabel(tr("Selected: 0"));
    statusBar()->addWidget(lbSelected);
    lbCoords = new QLabel(tr("0:0"));
    statusBar()->addWidget(lbCoords);

    connect(tabWidget, SIGNAL(tabCloseRequested(int)), this, SLOT(tabClose(int)));
    connect(tabWidget, SIGNAL(currentChanged(int)),this, SLOT(tabChanged(int)));

    docWidget = 0;
    mapper = new QDataWidgetMapper(this);
    mapper2 = new QDataWidgetMapper(this);
    connect(ui->listView, SIGNAL(clicked(QModelIndex)), mapper, SLOT(setCurrentModelIndex(QModelIndex)));
    connect(ui->cbTape, SIGNAL(currentIndexChanged(int)), this, SLOT(setTape(int)));
    Settings *settings = Settings::Instance();
    settings->loadBasicGroups();
    settings->loadLastFiles();
    createActions();
    updateLastFilesMenu();

    createShortCuts();


    for (int i = 1; i < 25; ++i)
    {
        ui->cbTape->addItem(QString::number(i,10));
    }

 }

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createShortCuts()
{

    QShortcut *copy = new QShortcut(this);
    copy->setKey(Qt::CTRL + Qt::Key_C);
    connect(copy, SIGNAL(activated()), this, SLOT(copyElements()));

    QShortcut *paste = new QShortcut(this);
    paste->setKey(Qt::CTRL + Qt::Key_V);
    connect(paste, SIGNAL(activated()), this, SLOT(pasteElements()));
}

void MainWindow::createActions()
{
    for(int i = 0; i < MaxRecentFiles; i++)
    {
        recentFileActs[i] = new QAction(this);
        recentFileActs[i]->setVisible(false);
        connect(recentFileActs[i], SIGNAL(triggered()),
                this, SLOT(openRecentFile()));
    }

    ui->menu_File->addSeparator();
    for(int i = 0; i < MaxRecentFiles; i++)
    {
        ui->menu_File->addAction(recentFileActs[i]);
    }
    ui->menu_File->addSeparator();
}

void MainWindow::updateLastFilesMenu()
{
    Settings *settings = Settings::Instance();
    QStringList *lastFiles = settings->getLastFiles();

    int numRecentFiles = qMin(lastFiles->length(), (int)MaxRecentFiles);

    if(!lastFiles->isEmpty())
    {
        QFileInfo file;
        for(int i = 0; i < lastFiles->count(); i++)
        {
            file.setFile(lastFiles->at(i));
            QString text = tr("&%1 %2").arg(i + 1).arg(file.fileName());
            recentFileActs[i]->setText(text);
            recentFileActs[i]->setData(file.absoluteFilePath());
            recentFileActs[i]->setToolTip(file.absoluteFilePath());
            recentFileActs[i]->setVisible(true);
        }
        for (int j = numRecentFiles; j < MaxRecentFiles; ++j)
        {
            recentFileActs[j]->setVisible(false);
        }
    }
}

void MainWindow::setTape(int x)
{
    if(docWidget)
    {
        docWidget->setSelectedTape(x);
    }
}

bool MainWindow::openFile(QString extension)
{
    QString filename;
    Settings *settings = Settings::Instance();
    QStringList *lastFiles = settings->getLastFiles();

    QString path;
    if(lastFiles->isEmpty())
    {
        path = "";
    }
    else
    {
        QFileInfo fileInfo;
        fileInfo.setFile(lastFiles->at(0));
        path = fileInfo.absolutePath();
    }

    filename = QFileDialog::getOpenFileName(this, tr("Select Coords File"),
                path,
                tr("Data (*.%1)").arg(extension));

    if (!filename.isEmpty())
    {

        lastFiles->prepend(filename);
        if(lastFiles->length() > 5)
        {
            lastFiles->removeLast();
        }
        updateLastFilesMenu();
        loadFile(filename);
        return true;
    }
    return false;
}

void MainWindow::openRecentFile()
{
    QAction *action = qobject_cast<QAction *>(sender());
    if (action)
        loadFile(action->data().toString());
}

void MainWindow::loadFile(const QString &filename)
{
    QFile file(filename);

    if(!file.open(QIODevice::ReadOnly))
    {
        statusBar()->showMessage(tr("Unable to open file!"), 5000);
    } else {
        DocumentWidget * newDocWidget;
        newDocWidget = new DocumentWidget(this, filename);
        connect(newDocWidget, SIGNAL(selectionChanged(Chip *)), this, SLOT(loadElement(Chip *)));
        connect(newDocWidget, SIGNAL(selectionChanged(int)), this, SLOT(selectionChanged(int)));
        connect(newDocWidget, SIGNAL(mousePos(QPoint)), this, SLOT(acceptCoords(QPoint)));

        QFileInfo *info = new QFileInfo(filename);

        tabWidget->setCurrentIndex(tabWidget->addTab(newDocWidget, info->fileName()));
        docWidget = newDocWidget;

        delete info;
    }

}

void MainWindow::loadElement(Chip *chip)
{

    ui->sbCoordX->setValue( chip->getCoordX() );
    ui->sbCoordY->setValue( chip->getCoordY() );

    int id = chip->getGroupID();
    int tape = docWidget->getGroupsModel()->getTapeByID(id);

    ui->cbTape->setCurrentIndex(tape-1);
    ui->sbAngle->setValue(chip->rotation());
    ui->lbDesignator->setText( QString( "%1" ).arg( chip->getDesignator() ) );
}

void MainWindow::on_sbZeroX_valueChanged(int val)
{
    Settings *settings = Settings::Instance();
    settings->setZeroX(val);
}

void MainWindow::on_sbZeroY_valueChanged(int val)
{
    Settings *settings = Settings::Instance();
    settings->setZeroY(val);
}

void MainWindow::on_pbSet_clicked()
{
//    moving coordinates
    if(docWidget)
    {
        signed int newValX = ui->sbCoordX->value();
        signed int newValY = ui->sbCoordY->value();
        if(ui->rbMulti->isChecked() && static_cast<DocumentWidget*>(tabWidget->currentWidget())->selectedCount() == 1)
        {
            docWidget->moveMultiply(newValX, newValY);
        }
        if(ui->rbSingle->isChecked() && static_cast<DocumentWidget*>(tabWidget->currentWidget())->selectedCount() == 1)
        {
            docWidget->moveSingle(newValX, newValY);
        }
    }
}

void MainWindow::rotate(double angle)
{
    if(docWidget)
    {
        docWidget->rotateSelected(angle);
    }
}

void MainWindow::on_pbSetGroupTape_clicked()
{
    if(docWidget)
    {
        docWidget->setSelectedTape(ui->sbGroupTape->value());
    }
}

void MainWindow::selectAll()
{
    if(docWidget)
    {
        docWidget->selectAll();
    }
}

void MainWindow::on_pbSub90_clicked()
{
    if(docWidget)
    {
        docWidget->rotateSelectedPersonal(-90);
    }
}

void MainWindow::on_pbAdd90_clicked()
{
    if(docWidget)
    {
        docWidget->rotateSelectedPersonal(90);
    }
}

void MainWindow::on_pbRotateAll_clicked()
{
    if(docWidget)
    {
        rotate(90);
    }
}

void MainWindow::on_actionImport_SMT_triggered()
{
    if(openFile("qgn"))
    {
        ui->slPos->setMaximum(docWidget->count());
    }
}

void MainWindow::on_actionImport_CSV_triggered()
{
    if(openFile("csv"))
    {
        ui->slPos->setMaximum(docWidget->count());
    }
}

void MainWindow::on_actionSave_SMT_triggered()
{
    if(docWidget)
    {
        docWidget->save();
    }
}

void MainWindow::on_actionSort_By_triggered()
{
    if(docWidget)
    {
        OrderBy *dialog = new OrderBy(this);

        if(dialog->exec() == QDialog::Accepted)
        {
            switch(dialog->getNum()){
                case 0 : docWidget->sortByX(); break;
                case 1 : docWidget->sortByY(); break;
                case 2 : docWidget->sortByTape(); break;
            }
        }
        delete dialog;
    }
}

void MainWindow::on_actionAddPart_activated()
{
    if(docWidget)
    {
        Newpart *dialog = new Newpart(this);
        dialog->setModel(docWidget->getGroupsModel());

        if(dialog->exec() == QDialog::Accepted)
        {
            Chip *item = new Chip(0,0, dialog->getName(), dialog->getAngle());
            item->setCoordX(dialog->getXCoord());
            item->setCoordY(dialog->getYCoord());
            item->setGroupID(dialog->getGroupID());
            docWidget->addChip(item);
        }
        delete dialog;
    }
}

void MainWindow::on_actionBasicSettings_triggered()
{
    BasicSettings *dialog = new BasicSettings(this);

    if(dialog->exec() == QDialog::Accepted)
    {

    }
    delete dialog;
}

void MainWindow::on_actionFlipH_triggered()
{
    if(docWidget)
    {
        docWidget->flipH();
    }
}

void MainWindow::on_actionFlipV_triggered()
{
    if(docWidget)
    {
        docWidget->flipV();
    }
}

void MainWindow::selectionChanged(int count)
{
    lbSelected->setText(tr("Selected: %1").arg(count));
}

void MainWindow::handleMessage(const QString& message)
{
    enum Action {
    Nothing,
    Open
    } action;

    action = Nothing;
    QString filename = message;

    if (!message.isEmpty())
    {
        loadFile(filename);
        emit needToShow();
    }

    if (action == Nothing) {
        emit needToShow();
        return;
    }
}

bool MainWindow::tabClose(int index)
{
    if(tabWidget->count() > index)
    {
        tabWidget->setCurrentIndex(index);
        if (docWidget->hasChanged())
        {
                QMessageBox::StandardButton ret;
                ret = QMessageBox::warning(this, tr("Application"),
                                           tr("The document has been modified.\n"
                                           "Do you want to save your changes?"),
                                           QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
                switch(ret)
                {
                    case QMessageBox::Save :
                    {
                        if(docWidget->save())
                        {
                            //ui->lwGroups->clear();
                            tabWidget->removeTab(index);
                            return true;
                        }else
                        {
                            return false;
                        }
                    }
                    case QMessageBox::Cancel :
                    {
                        return false;
                    }
                    case QMessageBox::Discard :
                    {
                        //ui->lwGroups->clear();
                        tabWidget->removeTab(index);
                        return true;
                    }
                    default: return false;
                }
        }
        //ui->lwGroups->clear();
        tabWidget->removeTab(index);
        return true;
    }
    return false;
}

void MainWindow::tabChanged(int i)
{
    if(tabWidget->currentWidget())
    {
        docWidget = static_cast<DocumentWidget*>(tabWidget->currentWidget());
        lbCount->setText(tr("Count: %1").arg(docWidget->count()));
        lbSelected->setText(tr("Selected: %1").arg(docWidget->selectedCount()));
        ui->slPos->setValue(docWidget->selectedCount());
        ui->slPos->setMaximum(docWidget->count());

        ui->listView->setModel(docWidget->getProxyModel());
        ui->listView->setModelColumn(2);
        mapper->setModel(docWidget->getProxyModel());
        //mapper->addMapping(ui->spinBox, 1);

        //Settings *settings = Settings::Instance();

        //ui->cbTape->setModel(settings->getBasicGroups());
        //ui->cbTape->setModelColumn(1);

    }
}

void MainWindow::on_actionDeleteSelected_triggered()
{
    if(docWidget)
    {
        docWidget->deleteSelected();
    }
}

void MainWindow::on_slPos_valueChanged(int value)
{
    if(docWidget)
    {
        docWidget->selectNLastItems(value);
    }
}

void MainWindow::acceptCoords(QPoint point)
{
    lbCoords->setText(QString::number(point.x()) + " : " + QString::number(point.y()));
}

void MainWindow::on_pbRotate_clicked()
{
    if(docWidget)
    {
        docWidget->testRotate(ui->sbRotateAngle->value());
    }
}

void MainWindow::on_actionMove_and_Rotate_triggered()
{
    if(docWidget)
    {
        if(docWidget->selectedCount() == 2)
        {
            DialogMoveRotate *dialog = new DialogMoveRotate(this);

            if(dialog->exec() == QDialog::Accepted)
            {
                double rx1 = dialog->getFirstXCoord();
                double ry1 = dialog->getFirstYCoord();
                double rx2 = dialog->getSecondXCoord();
                double ry2 = dialog->getSecondYCoord();
                docWidget->makeRotate(rx1,  ry1,  rx2,  ry2);
            }
            delete dialog;
        }
        else
            QMessageBox::critical(this, tr("Error"), tr("Must select 2 items!"));
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
        if (maybeSave()) {
                event->accept();
        } else {
                event->ignore();
        }
}

bool MainWindow::maybeSave()
{
    int count = tabWidget->count();
    for(int i = 0; i < count; i++)
    {
        if(!tabClose(0))
        {
            return false;
        }
    }
    Settings *settings = Settings::Instance();
    settings->saveColors();
    settings->saveLastFiles();
    return true;
}

void MainWindow::on_pbRemoveGroup_clicked()
{
    QModelIndex idx;
    int row =  ui->listView->currentIndex().row();
    idx = ui->listView->model()->index(row, 3, QModelIndex());

    ui->listView->model()->setData(idx, false, Qt::DisplayRole);
    docWidget->deleteSelected();
}

void MainWindow::on_listView_clicked(const QModelIndex &index)
{
    if(docWidget)
    {
        docWidget->selectByGroup(index);
    }
}

void MainWindow::on_pbRestore_clicked()
{
    if(docWidget)
    {
        QModelIndex idx;
        int row =  ui->listView->currentIndex().row();
        idx = ui->listView->model()->index(row, 3, QModelIndex());
        ui->listView->model()->setData(idx, true, Qt::DisplayRole);
    }
}

void MainWindow::on_actionShow_Groups_Dialog_triggered()
{
    if(docWidget)
    {
        GroupEdit *dialog = new GroupEdit(this);
        dialog->setModel(docWidget->getGroupsModel());

        if(dialog->exec() == QDialog::Accepted)
        {

        }
        delete dialog;
    }
}

void MainWindow::on_actionBasicGroupsDialog_triggered()
{
    if(docWidget)
    {
        Settings *settings = Settings::Instance();
        AddACLDialog *dialog = new AddACLDialog(docWidget->getGroupsModel(), settings->getGroupsACLModel(), this);

        if(dialog->exec() == QDialog::Accepted)
        {
            settings->saveGroupsACL();
            settings->saveGroupsRejectList();
            docWidget->findMatchGroups();
        } else
        {
            settings->loadGroupsACL();
            settings->loadGroupsRejectList();
        }
        delete dialog;
    }
}

void MainWindow::on_pbRotSel_clicked()
{
    if(docWidget)
    {
        docWidget->rotateSelected(ui->sbRotateAngle->value());
    }
}

void MainWindow::on_actionChangeGroup_triggered()
{
    if(!docWidget)
        return;

    ChangeGroupDialog *dialog = new ChangeGroupDialog();
    dialog->setModel(docWidget->getGroupsModel());
    if(dialog->exec() == QDialog::Accepted)
    {
        QModelIndex index = dialog->getSelectedIndex();
        qDebug() << "Group changed";
        index = docWidget->getGroupsModel()->index(index.row(), 0, QModelIndex());
        int id = docWidget->getGroupsModel()->data(index, Qt::DisplayRole).toInt();
        docWidget->setSelectedGroup(id);
        int tape = docWidget->getGroupsModel()->getTapeByID(id);
        docWidget->setSelectedTape(tape);
    }
    delete dialog;
}

void MainWindow::copyElements()
{
    if(!docWidget)
        return;
    clipboard = docWidget->getSelectedElements();
    qDebug() << clipboard.length() << " elements copied";
}

void MainWindow::pasteElements()
{
    if(!docWidget)
        return;

    if (clipboard.isEmpty())
        return;

    docWidget->pasteElements(&clipboard);
    qDebug() << clipboard.length() << " elements pasted";
}
