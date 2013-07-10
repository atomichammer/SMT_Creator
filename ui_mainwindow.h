/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
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
    QAction *actionSaveToSVG;
    QAction *actionRotateC90;
    QAction *actionRotateC270;
    QAction *actionActionRotateAll90;
    QAction *actionRotateAll270;
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
    QLabel *lbTape;
    QLabel *lbAngle;
    QGroupBox *Groups;
    QGridLayout *gridLayout_4;
    QPushButton *pbRemoveGroup;
    QListView *listView;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QMenu *menu_Edit;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;
    QToolBar *toolBar_2;

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
        icon10.addFile(QString::fromUtf8(":/icons/icons/Actions-transform-rotate-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMove_and_Rotate->setIcon(icon10);
        actionShow_Groups_Dialog = new QAction(MainWindow);
        actionShow_Groups_Dialog->setObjectName(QString::fromUtf8("actionShow_Groups_Dialog"));
        actionBasicGroupsDialog = new QAction(MainWindow);
        actionBasicGroupsDialog->setObjectName(QString::fromUtf8("actionBasicGroupsDialog"));
        actionChangeGroup = new QAction(MainWindow);
        actionChangeGroup->setObjectName(QString::fromUtf8("actionChangeGroup"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/icons/icons/Video-Reel-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionChangeGroup->setIcon(icon11);
        actionSaveToSVG = new QAction(MainWindow);
        actionSaveToSVG->setObjectName(QString::fromUtf8("actionSaveToSVG"));
        actionRotateC90 = new QAction(MainWindow);
        actionRotateC90->setObjectName(QString::fromUtf8("actionRotateC90"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/icons/icons/transform-rotate-90-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRotateC90->setIcon(icon12);
        actionRotateC270 = new QAction(MainWindow);
        actionRotateC270->setObjectName(QString::fromUtf8("actionRotateC270"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/icons/icons/transform-rotate-270-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRotateC270->setIcon(icon13);
        actionActionRotateAll90 = new QAction(MainWindow);
        actionActionRotateAll90->setObjectName(QString::fromUtf8("actionActionRotateAll90"));
        actionActionRotateAll90->setIcon(icon12);
        actionRotateAll270 = new QAction(MainWindow);
        actionRotateAll270->setObjectName(QString::fromUtf8("actionRotateAll270"));
        actionRotateAll270->setIcon(icon13);
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
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 412, 500));
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
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        lbDesignator2->setFont(font);

        gridLayout->addWidget(lbDesignator2, 1, 1, 1, 1);

        label_4 = new QLabel(Info);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 4, 1, 1, 1);

        pbSet = new QPushButton(Info);
        pbSet->setObjectName(QString::fromUtf8("pbSet"));

        gridLayout->addWidget(pbSet, 8, 2, 1, 1);

        label_5 = new QLabel(Info);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

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
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 7, 1, 1, 1);

        label_2 = new QLabel(Info);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 6, 1, 1, 1);

        rbMulti = new QRadioButton(Info);
        rbMulti->setObjectName(QString::fromUtf8("rbMulti"));
        rbMulti->setChecked(true);

        gridLayout->addWidget(rbMulti, 8, 1, 1, 1);

        rbSingle = new QRadioButton(Info);
        rbSingle->setObjectName(QString::fromUtf8("rbSingle"));

        gridLayout->addWidget(rbSingle, 9, 1, 1, 1);

        lbTape = new QLabel(Info);
        lbTape->setObjectName(QString::fromUtf8("lbTape"));

        gridLayout->addWidget(lbTape, 4, 2, 1, 1);

        lbAngle = new QLabel(Info);
        lbAngle->setObjectName(QString::fromUtf8("lbAngle"));

        gridLayout->addWidget(lbAngle, 5, 2, 1, 1);


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
        pbRemoveGroup = new QPushButton(Groups);
        pbRemoveGroup->setObjectName(QString::fromUtf8("pbRemoveGroup"));

        gridLayout_4->addWidget(pbRemoveGroup, 3, 0, 1, 1);

        listView = new QListView(Groups);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setMinimumSize(QSize(0, 150));
        listView->setEditTriggers(QAbstractItemView::NoEditTriggers);

        gridLayout_4->addWidget(listView, 2, 0, 1, 2);


        verticalLayout_2->addWidget(Groups);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_5->addWidget(scrollArea, 0, 2, 1, 1);


        horizontalLayout->addLayout(gridLayout_5);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 880, 21));
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
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        toolBar_2 = new QToolBar(MainWindow);
        toolBar_2->setObjectName(QString::fromUtf8("toolBar_2"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_2);

        menuBar->addAction(menu_File->menuAction());
        menuBar->addAction(menu_Edit->menuAction());
        menu_File->addAction(actionImport_SMT);
        menu_File->addAction(actionImport_CSV);
        menu_File->addSeparator();
        menu_File->addAction(actionSave_SMT);
        menu_File->addAction(actionSaveToSVG);
        menu_File->addSeparator();
        menu_File->addAction(actionBasicSettings);
        menu_File->addSeparator();
        menu_Edit->addAction(actionAddPart);
        menu_Edit->addAction(actionDeleteSelected);
        menu_Edit->addAction(actionRotateC90);
        menu_Edit->addAction(actionRotateC270);
        menu_Edit->addAction(actionChangeGroup);
        menu_Edit->addSeparator();
        menu_Edit->addAction(actionActionRotateAll90);
        menu_Edit->addAction(actionRotateAll270);
        menu_Edit->addAction(actionSort_By);
        menu_Edit->addAction(actionFlipH);
        menu_Edit->addAction(actionFlipV);
        menu_Edit->addAction(actionMove_and_Rotate);
        menu_Edit->addSeparator();
        menu_Edit->addAction(actionShow_Groups_Dialog);
        menu_Edit->addAction(actionBasicGroupsDialog);
        mainToolBar->addAction(actionImport_SMT);
        mainToolBar->addAction(actionImport_CSV);
        mainToolBar->addAction(actionSave_SMT);
        toolBar->addAction(actionSort_By);
        toolBar->addAction(actionRotateAll270);
        toolBar->addAction(actionActionRotateAll90);
        toolBar->addAction(actionFlipH);
        toolBar->addAction(actionFlipV);
        toolBar->addAction(actionMove_and_Rotate);
        toolBar_2->addAction(actionAddPart);
        toolBar_2->addAction(actionDeleteSelected);
        toolBar_2->addAction(actionRotateC270);
        toolBar_2->addAction(actionRotateC90);
        toolBar_2->addAction(actionChangeGroup);

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
        actionSaveToSVG->setText(QApplication::translate("MainWindow", "Save To SVG", 0, QApplication::UnicodeUTF8));
        actionRotateC90->setText(QApplication::translate("MainWindow", "Rotate Selected By 90", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionRotateC90->setToolTip(QApplication::translate("MainWindow", "Rotate Selected Items By 90 Degrees", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionRotateC270->setText(QApplication::translate("MainWindow", "Rotate Selected By 270", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionRotateC270->setToolTip(QApplication::translate("MainWindow", "Rotates Selected Items By 270 Degrees", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionActionRotateAll90->setText(QApplication::translate("MainWindow", "Rotate All By 90", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionActionRotateAll90->setToolTip(QApplication::translate("MainWindow", "Rotates Whole Board By 90 Degrees", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionRotateAll270->setText(QApplication::translate("MainWindow", "Rotate All By 270", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionRotateAll270->setToolTip(QApplication::translate("MainWindow", "Rotates Whole Board By 270 Degrees", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
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
        lbTape->setText(QString());
        lbAngle->setText(QString());
        Groups->setTitle(QApplication::translate("MainWindow", "Groups", 0, QApplication::UnicodeUTF8));
        pbRemoveGroup->setText(QApplication::translate("MainWindow", "Remove", 0, QApplication::UnicodeUTF8));
        menu_File->setTitle(QApplication::translate("MainWindow", "&File", 0, QApplication::UnicodeUTF8));
        menu_Edit->setTitle(QApplication::translate("MainWindow", "&Edit", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
        toolBar_2->setWindowTitle(QApplication::translate("MainWindow", "toolBar_2", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
