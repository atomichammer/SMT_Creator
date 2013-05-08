/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed 8. May 13:18:31 2013
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionImport_SMT;
    QAction *actionImport_CSV;
    QAction *actionSave_SMT;
    QAction *actionSort_By;
    QAction *actionAddPart;
    QAction *actionBasicSettings;
    QAction *actionFlipH;
    QAction *actionFlipV;
    QAction *actionDeleteSelected;
    QAction *actionMove_and_Rotate;
    QAction *actionShow_Groups_Dialog;
    QAction *actionBasicGroupsDialog;
    QAction *actionChangeGroup;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout_5;
    QSlider *slPos;
    QSpacerItem *verticalSpacer_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *Info;
    QGridLayout *gridLayout;
    QLabel *lbDesignator2;
    QLabel *label_4;
    QPushButton *pbSet;
    QLabel *label_5;
    QLabel *lbDesignator;
    QSpinBox *sbCoordX;
    QSpinBox *sbCoordY;
    QLabel *label_3;
    QLabel *label_2;
    QRadioButton *rbMulti;
    QRadioButton *rbSingle;
    QSpinBox *sbAngle;
    QComboBox *cbTape;
    QGroupBox *Groups;
    QGridLayout *gridLayout_4;
    QPushButton *pbSetGroupTape;
    QPushButton *pbRemoveGroup;
    QPushButton *pbRestore;
    QPushButton *pbSub90;
    QPushButton *pbAdd90;
    QPushButton *pbRotate;
    QSpinBox *sbRotateAngle;
    QListView *listView;
    QSpinBox *sbGroupTape;
    QPushButton *pbRotSel;
    QGroupBox *BasicSettings;
    QGridLayout *gridLayout_3;
    QLabel *label_6;
    QLabel *label_8;
    QSpinBox *sbZeroX;
    QSpinBox *sbZeroY;
    QSpinBox *sbStepsPerMm;
    QLabel *label_9;
    QSpacerItem *verticalSpacer;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QMenu *menu_Edit;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(880, 597);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionImport_SMT = new QAction(MainWindow);
        actionImport_SMT->setObjectName(QString::fromUtf8("actionImport_SMT"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/icons/System-Binary-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionImport_SMT->setIcon(icon1);
        actionImport_CSV = new QAction(MainWindow);
        actionImport_CSV->setObjectName(QString::fromUtf8("actionImport_CSV"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/icons/csv_file.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionImport_CSV->setIcon(icon2);
        actionSave_SMT = new QAction(MainWindow);
        actionSave_SMT->setObjectName(QString::fromUtf8("actionSave_SMT"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/icons/filesave.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_SMT->setIcon(icon3);
        actionSort_By = new QAction(MainWindow);
        actionSort_By->setObjectName(QString::fromUtf8("actionSort_By"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/icons/sort-ascending-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSort_By->setIcon(icon4);
        actionAddPart = new QAction(MainWindow);
        actionAddPart->setObjectName(QString::fromUtf8("actionAddPart"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/icons/edit_add.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAddPart->setIcon(icon5);
        actionBasicSettings = new QAction(MainWindow);
        actionBasicSettings->setObjectName(QString::fromUtf8("actionBasicSettings"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/icons/gear.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBasicSettings->setIcon(icon6);
        actionFlipH = new QAction(MainWindow);
        actionFlipH->setObjectName(QString::fromUtf8("actionFlipH"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icons/icons/Actions-object-flip-horizontal-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFlipH->setIcon(icon7);
        actionFlipV = new QAction(MainWindow);
        actionFlipV->setObjectName(QString::fromUtf8("actionFlipV"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/icons/icons/Actions-object-flip-vertical-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFlipV->setIcon(icon8);
        actionDeleteSelected = new QAction(MainWindow);
        actionDeleteSelected->setObjectName(QString::fromUtf8("actionDeleteSelected"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/icons/icons/edit_remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDeleteSelected->setIcon(icon9);
        actionMove_and_Rotate = new QAction(MainWindow);
        actionMove_and_Rotate->setObjectName(QString::fromUtf8("actionMove_and_Rotate"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/icons/icons/designet.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMove_and_Rotate->setIcon(icon10);
        actionShow_Groups_Dialog = new QAction(MainWindow);
        actionShow_Groups_Dialog->setObjectName(QString::fromUtf8("actionShow_Groups_Dialog"));
        actionBasicGroupsDialog = new QAction(MainWindow);
        actionBasicGroupsDialog->setObjectName(QString::fromUtf8("actionBasicGroupsDialog"));
        actionChangeGroup = new QAction(MainWindow);
        actionChangeGroup->setObjectName(QString::fromUtf8("actionChangeGroup"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        slPos = new QSlider(centralWidget);
        slPos->setObjectName(QString::fromUtf8("slPos"));
        slPos->setOrientation(Qt::Vertical);

        gridLayout_5->addWidget(slPos, 0, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_2, 0, 0, 1, 1);

        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setMinimumSize(QSize(190, 0));
        scrollArea->setFrameShadow(QFrame::Raised);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 396, 678));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        Info = new QGroupBox(scrollAreaWidgetContents);
        Info->setObjectName(QString::fromUtf8("Info"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Info->sizePolicy().hasHeightForWidth());
        Info->setSizePolicy(sizePolicy1);
        Info->setMaximumSize(QSize(160, 16777215));
        gridLayout = new QGridLayout(Info);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lbDesignator2 = new QLabel(Info);
        lbDesignator2->setObjectName(QString::fromUtf8("lbDesignator2"));

        gridLayout->addWidget(lbDesignator2, 1, 1, 1, 1);

        label_4 = new QLabel(Info);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 4, 1, 1, 1);

        pbSet = new QPushButton(Info);
        pbSet->setObjectName(QString::fromUtf8("pbSet"));

        gridLayout->addWidget(pbSet, 8, 2, 1, 1);

        label_5 = new QLabel(Info);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 5, 1, 1, 1);

        lbDesignator = new QLabel(Info);
        lbDesignator->setObjectName(QString::fromUtf8("lbDesignator"));

        gridLayout->addWidget(lbDesignator, 1, 2, 1, 1);

        sbCoordX = new QSpinBox(Info);
        sbCoordX->setObjectName(QString::fromUtf8("sbCoordX"));
        sbCoordX->setMaximum(75000);

        gridLayout->addWidget(sbCoordX, 6, 2, 1, 1);

        sbCoordY = new QSpinBox(Info);
        sbCoordY->setObjectName(QString::fromUtf8("sbCoordY"));
        sbCoordY->setMaximum(75000);

        gridLayout->addWidget(sbCoordY, 7, 2, 1, 1);

        label_3 = new QLabel(Info);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 7, 1, 1, 1);

        label_2 = new QLabel(Info);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 6, 1, 1, 1);

        rbMulti = new QRadioButton(Info);
        rbMulti->setObjectName(QString::fromUtf8("rbMulti"));
        rbMulti->setChecked(true);

        gridLayout->addWidget(rbMulti, 8, 1, 1, 1);

        rbSingle = new QRadioButton(Info);
        rbSingle->setObjectName(QString::fromUtf8("rbSingle"));

        gridLayout->addWidget(rbSingle, 9, 1, 1, 1);

        sbAngle = new QSpinBox(Info);
        sbAngle->setObjectName(QString::fromUtf8("sbAngle"));
        sbAngle->setMinimum(-180);
        sbAngle->setMaximum(180);

        gridLayout->addWidget(sbAngle, 5, 2, 1, 1);

        cbTape = new QComboBox(Info);
        cbTape->setObjectName(QString::fromUtf8("cbTape"));

        gridLayout->addWidget(cbTape, 4, 2, 1, 1);


        verticalLayout_2->addWidget(Info);

        Groups = new QGroupBox(scrollAreaWidgetContents);
        Groups->setObjectName(QString::fromUtf8("Groups"));
        sizePolicy1.setHeightForWidth(Groups->sizePolicy().hasHeightForWidth());
        Groups->setSizePolicy(sizePolicy1);
        Groups->setMaximumSize(QSize(160, 16777215));
        gridLayout_4 = new QGridLayout(Groups);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        pbSetGroupTape = new QPushButton(Groups);
        pbSetGroupTape->setObjectName(QString::fromUtf8("pbSetGroupTape"));

        gridLayout_4->addWidget(pbSetGroupTape, 3, 1, 1, 1);

        pbRemoveGroup = new QPushButton(Groups);
        pbRemoveGroup->setObjectName(QString::fromUtf8("pbRemoveGroup"));

        gridLayout_4->addWidget(pbRemoveGroup, 4, 0, 1, 1);

        pbRestore = new QPushButton(Groups);
        pbRestore->setObjectName(QString::fromUtf8("pbRestore"));

        gridLayout_4->addWidget(pbRestore, 4, 1, 1, 1);

        pbSub90 = new QPushButton(Groups);
        pbSub90->setObjectName(QString::fromUtf8("pbSub90"));

        gridLayout_4->addWidget(pbSub90, 5, 0, 1, 1);

        pbAdd90 = new QPushButton(Groups);
        pbAdd90->setObjectName(QString::fromUtf8("pbAdd90"));

        gridLayout_4->addWidget(pbAdd90, 5, 1, 1, 1);

        pbRotate = new QPushButton(Groups);
        pbRotate->setObjectName(QString::fromUtf8("pbRotate"));

        gridLayout_4->addWidget(pbRotate, 6, 0, 1, 1);

        sbRotateAngle = new QSpinBox(Groups);
        sbRotateAngle->setObjectName(QString::fromUtf8("sbRotateAngle"));
        sbRotateAngle->setMinimum(-360);
        sbRotateAngle->setMaximum(360);
        sbRotateAngle->setValue(0);

        gridLayout_4->addWidget(sbRotateAngle, 6, 1, 1, 1);

        listView = new QListView(Groups);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setMinimumSize(QSize(0, 150));
        listView->setEditTriggers(QAbstractItemView::NoEditTriggers);

        gridLayout_4->addWidget(listView, 2, 0, 1, 2);

        sbGroupTape = new QSpinBox(Groups);
        sbGroupTape->setObjectName(QString::fromUtf8("sbGroupTape"));

        gridLayout_4->addWidget(sbGroupTape, 3, 0, 1, 1);

        pbRotSel = new QPushButton(Groups);
        pbRotSel->setObjectName(QString::fromUtf8("pbRotSel"));

        gridLayout_4->addWidget(pbRotSel, 7, 0, 1, 2);


        verticalLayout_2->addWidget(Groups);

        BasicSettings = new QGroupBox(scrollAreaWidgetContents);
        BasicSettings->setObjectName(QString::fromUtf8("BasicSettings"));
        sizePolicy1.setHeightForWidth(BasicSettings->sizePolicy().hasHeightForWidth());
        BasicSettings->setSizePolicy(sizePolicy1);
        BasicSettings->setMinimumSize(QSize(0, 0));
        BasicSettings->setMaximumSize(QSize(160, 16777215));
        gridLayout_3 = new QGridLayout(BasicSettings);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_6 = new QLabel(BasicSettings);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_3->addWidget(label_6, 1, 0, 1, 1);

        label_8 = new QLabel(BasicSettings);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_3->addWidget(label_8, 2, 0, 1, 1);

        sbZeroX = new QSpinBox(BasicSettings);
        sbZeroX->setObjectName(QString::fromUtf8("sbZeroX"));
        sbZeroX->setMaximum(75000);
        sbZeroX->setValue(61635);

        gridLayout_3->addWidget(sbZeroX, 1, 1, 1, 1);

        sbZeroY = new QSpinBox(BasicSettings);
        sbZeroY->setObjectName(QString::fromUtf8("sbZeroY"));
        sbZeroY->setMaximum(70000);
        sbZeroY->setValue(1838);

        gridLayout_3->addWidget(sbZeroY, 2, 1, 1, 1);

        sbStepsPerMm = new QSpinBox(BasicSettings);
        sbStepsPerMm->setObjectName(QString::fromUtf8("sbStepsPerMm"));
        sbStepsPerMm->setMinimum(1);
        sbStepsPerMm->setMaximum(200);
        sbStepsPerMm->setValue(197);

        gridLayout_3->addWidget(sbStepsPerMm, 3, 1, 1, 1);

        label_9 = new QLabel(BasicSettings);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_3->addWidget(label_9, 3, 0, 1, 1);


        verticalLayout_2->addWidget(BasicSettings);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_5->addWidget(scrollArea, 0, 2, 1, 1);


        horizontalLayout->addLayout(gridLayout_5);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 880, 18));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QString::fromUtf8("menu_File"));
        menu_Edit = new QMenu(menuBar);
        menu_Edit->setObjectName(QString::fromUtf8("menu_Edit"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu_File->menuAction());
        menuBar->addAction(menu_Edit->menuAction());
        menu_File->addAction(actionImport_SMT);
        menu_File->addAction(actionImport_CSV);
        menu_File->addSeparator();
        menu_File->addAction(actionSave_SMT);
        menu_File->addSeparator();
        menu_File->addAction(actionBasicSettings);
        menu_File->addSeparator();
        menu_Edit->addAction(actionSort_By);
        menu_Edit->addAction(actionAddPart);
        menu_Edit->addAction(actionDeleteSelected);
        menu_Edit->addSeparator();
        menu_Edit->addAction(actionFlipH);
        menu_Edit->addAction(actionFlipV);
        menu_Edit->addSeparator();
        menu_Edit->addAction(actionMove_and_Rotate);
        menu_Edit->addAction(actionChangeGroup);
        mainToolBar->addAction(actionImport_SMT);
        mainToolBar->addAction(actionImport_CSV);
        mainToolBar->addAction(actionSave_SMT);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionSort_By);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionAddPart);
        mainToolBar->addAction(actionDeleteSelected);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionFlipH);
        mainToolBar->addAction(actionFlipV);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionMove_and_Rotate);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionBasicSettings);
        mainToolBar->addAction(actionShow_Groups_Dialog);
        mainToolBar->addAction(actionBasicGroupsDialog);
        mainToolBar->addAction(actionChangeGroup);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionImport_SMT->setText(QApplication::translate("MainWindow", "Import SMT", 0, QApplication::UnicodeUTF8));
        actionImport_CSV->setText(QApplication::translate("MainWindow", "Import CSV", 0, QApplication::UnicodeUTF8));
        actionSave_SMT->setText(QApplication::translate("MainWindow", "Save SMT", 0, QApplication::UnicodeUTF8));
        actionSort_By->setText(QApplication::translate("MainWindow", "Sort By", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionSort_By->setToolTip(QApplication::translate("MainWindow", "Sort place order", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionAddPart->setText(QApplication::translate("MainWindow", "Add Element", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionAddPart->setToolTip(QApplication::translate("MainWindow", "Add Element", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionAddPart->setShortcut(QApplication::translate("MainWindow", "Ctrl+=", 0, QApplication::UnicodeUTF8));
        actionBasicSettings->setText(QApplication::translate("MainWindow", "Basic Settings", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionBasicSettings->setToolTip(QApplication::translate("MainWindow", "Basic Settings", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionFlipH->setText(QApplication::translate("MainWindow", "Mirror Horizontally", 0, QApplication::UnicodeUTF8));
        actionFlipV->setText(QApplication::translate("MainWindow", "Mirror Vertically", 0, QApplication::UnicodeUTF8));
        actionDeleteSelected->setText(QApplication::translate("MainWindow", "Delete Selected Chips", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionDeleteSelected->setToolTip(QApplication::translate("MainWindow", "Deletes Selected Items", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionDeleteSelected->setShortcut(QApplication::translate("MainWindow", "Del", 0, QApplication::UnicodeUTF8));
        actionMove_and_Rotate->setText(QApplication::translate("MainWindow", "Move and Rotate", 0, QApplication::UnicodeUTF8));
        actionShow_Groups_Dialog->setText(QApplication::translate("MainWindow", "Show Groups Dialog", 0, QApplication::UnicodeUTF8));
        actionBasicGroupsDialog->setText(QApplication::translate("MainWindow", "Show Basic Groups Dialog", 0, QApplication::UnicodeUTF8));
        actionChangeGroup->setText(QApplication::translate("MainWindow", "ChangeGroup", 0, QApplication::UnicodeUTF8));
        actionChangeGroup->setShortcut(QApplication::translate("MainWindow", "Ctrl+G", 0, QApplication::UnicodeUTF8));
        Info->setTitle(QApplication::translate("MainWindow", "Info", 0, QApplication::UnicodeUTF8));
        lbDesignator2->setText(QApplication::translate("MainWindow", "Name:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Tape:", 0, QApplication::UnicodeUTF8));
        pbSet->setText(QApplication::translate("MainWindow", "Set", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Angle:", 0, QApplication::UnicodeUTF8));
        lbDesignator->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "Y", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "X", 0, QApplication::UnicodeUTF8));
        rbMulti->setText(QApplication::translate("MainWindow", "Multi", 0, QApplication::UnicodeUTF8));
        rbSingle->setText(QApplication::translate("MainWindow", "Single", 0, QApplication::UnicodeUTF8));
        Groups->setTitle(QApplication::translate("MainWindow", "Groups", 0, QApplication::UnicodeUTF8));
        pbSetGroupTape->setText(QApplication::translate("MainWindow", "Set Tape", 0, QApplication::UnicodeUTF8));
        pbRemoveGroup->setText(QApplication::translate("MainWindow", "Remove", 0, QApplication::UnicodeUTF8));
        pbRestore->setText(QApplication::translate("MainWindow", "Restore", 0, QApplication::UnicodeUTF8));
        pbSub90->setText(QApplication::translate("MainWindow", "-90", 0, QApplication::UnicodeUTF8));
        pbAdd90->setText(QApplication::translate("MainWindow", "+90", 0, QApplication::UnicodeUTF8));
        pbRotate->setText(QApplication::translate("MainWindow", "Rotate", 0, QApplication::UnicodeUTF8));
        pbRotSel->setText(QApplication::translate("MainWindow", "Rotate Selected", 0, QApplication::UnicodeUTF8));
        BasicSettings->setTitle(QApplication::translate("MainWindow", "Basic Settings", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "X", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "Y", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "Steps per mm:", 0, QApplication::UnicodeUTF8));
        menu_File->setTitle(QApplication::translate("MainWindow", "&File", 0, QApplication::UnicodeUTF8));
        menu_Edit->setTitle(QApplication::translate("MainWindow", "&Edit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
