/********************************************************************************
** Form generated from reading UI file 'basicsettings.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BASICSETTINGS_H
#define UI_BASICSETTINGS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BasicSettings
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QSpinBox *sb1;
    QLabel *label_2;
    QSpinBox *sb2;
    QLabel *label_3;
    QSpinBox *sb3;
    QLabel *label_4;
    QSpinBox *sb4;
    QLabel *label_5;
    QSpinBox *sb5;
    QLabel *label_6;
    QSpinBox *sb6;
    QLabel *label_7;
    QSpinBox *sb7;
    QLabel *label_8;
    QSpinBox *sb8;
    QLabel *label_9;
    QSpinBox *sb9;
    QLabel *label_10;
    QSpinBox *sb10;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QPushButton *pbShifterX;
    QPushButton *pbShifterY;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_4;
    QPushButton *pbPickerY;
    QPushButton *pbPickerX;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QTableView *tableView;
    QLabel *label_11;
    QSpinBox *sbStep;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *BasicSettings)
    {
        if (BasicSettings->objectName().isEmpty())
            BasicSettings->setObjectName(QString::fromUtf8("BasicSettings"));
        BasicSettings->resize(610, 528);
        gridLayout = new QGridLayout(BasicSettings);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_2 = new QGroupBox(BasicSettings);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        sb1 = new QSpinBox(groupBox_2);
        sb1->setObjectName(QString::fromUtf8("sb1"));
        sb1->setMaximum(1000000);

        verticalLayout_2->addWidget(sb1);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        sb2 = new QSpinBox(groupBox_2);
        sb2->setObjectName(QString::fromUtf8("sb2"));
        sb2->setMaximum(1000000);

        verticalLayout_2->addWidget(sb2);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        sb3 = new QSpinBox(groupBox_2);
        sb3->setObjectName(QString::fromUtf8("sb3"));
        sb3->setMaximum(1000000);

        verticalLayout_2->addWidget(sb3);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_2->addWidget(label_4);

        sb4 = new QSpinBox(groupBox_2);
        sb4->setObjectName(QString::fromUtf8("sb4"));
        sb4->setMaximum(1000000);

        verticalLayout_2->addWidget(sb4);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_2->addWidget(label_5);

        sb5 = new QSpinBox(groupBox_2);
        sb5->setObjectName(QString::fromUtf8("sb5"));
        sb5->setMaximum(1000000);

        verticalLayout_2->addWidget(sb5);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_2->addWidget(label_6);

        sb6 = new QSpinBox(groupBox_2);
        sb6->setObjectName(QString::fromUtf8("sb6"));
        sb6->setMaximum(1000000);

        verticalLayout_2->addWidget(sb6);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_2->addWidget(label_7);

        sb7 = new QSpinBox(groupBox_2);
        sb7->setObjectName(QString::fromUtf8("sb7"));
        sb7->setMaximum(1000000);

        verticalLayout_2->addWidget(sb7);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_2->addWidget(label_8);

        sb8 = new QSpinBox(groupBox_2);
        sb8->setObjectName(QString::fromUtf8("sb8"));
        sb8->setMaximum(1000000);

        verticalLayout_2->addWidget(sb8);

        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout_2->addWidget(label_9);

        sb9 = new QSpinBox(groupBox_2);
        sb9->setObjectName(QString::fromUtf8("sb9"));
        sb9->setMaximum(1000000);

        verticalLayout_2->addWidget(sb9);

        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout_2->addWidget(label_10);

        sb10 = new QSpinBox(groupBox_2);
        sb10->setObjectName(QString::fromUtf8("sb10"));
        sb10->setMaximum(1000000);

        verticalLayout_2->addWidget(sb10);


        gridLayout->addWidget(groupBox_2, 0, 0, 4, 1);

        groupBox_3 = new QGroupBox(BasicSettings);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy);
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        pbShifterX = new QPushButton(groupBox_3);
        pbShifterX->setObjectName(QString::fromUtf8("pbShifterX"));

        gridLayout_3->addWidget(pbShifterX, 1, 0, 1, 1);

        pbShifterY = new QPushButton(groupBox_3);
        pbShifterY->setObjectName(QString::fromUtf8("pbShifterY"));

        gridLayout_3->addWidget(pbShifterY, 2, 0, 1, 1);


        gridLayout->addWidget(groupBox_3, 0, 2, 3, 1);

        groupBox_4 = new QGroupBox(BasicSettings);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        sizePolicy.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy);
        gridLayout_4 = new QGridLayout(groupBox_4);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        pbPickerY = new QPushButton(groupBox_4);
        pbPickerY->setObjectName(QString::fromUtf8("pbPickerY"));

        gridLayout_4->addWidget(pbPickerY, 1, 0, 1, 1);

        pbPickerX = new QPushButton(groupBox_4);
        pbPickerX->setObjectName(QString::fromUtf8("pbPickerX"));

        gridLayout_4->addWidget(pbPickerX, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox_4, 0, 3, 3, 1);

        groupBox = new QGroupBox(BasicSettings);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        tableView = new QTableView(groupBox);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(1);
        sizePolicy2.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(tableView, 3, 0, 2, 6);


        gridLayout->addWidget(groupBox, 3, 2, 1, 4);

        label_11 = new QLabel(BasicSettings);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout->addWidget(label_11, 0, 4, 1, 1);

        sbStep = new QSpinBox(BasicSettings);
        sbStep->setObjectName(QString::fromUtf8("sbStep"));
        sbStep->setMaximum(2000);
        sbStep->setValue(1000);

        gridLayout->addWidget(sbStep, 1, 4, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 5, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 4, 1, 1);


        retranslateUi(BasicSettings);

        QMetaObject::connectSlotsByName(BasicSettings);
    } // setupUi

    void retranslateUi(QDialog *BasicSettings)
    {
        BasicSettings->setWindowTitle(QApplication::translate("BasicSettings", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("BasicSettings", "Parameter Set 1", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BasicSettings", "Parameter 1", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("BasicSettings", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("BasicSettings", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("BasicSettings", "Picks up at:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("BasicSettings", "Puts down at:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("BasicSettings", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("BasicSettings", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("BasicSettings", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("BasicSettings", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("BasicSettings", "TextLabel", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("BasicSettings", "Shifter", 0, QApplication::UnicodeUTF8));
        pbShifterX->setText(QApplication::translate("BasicSettings", "Set X Equal", 0, QApplication::UnicodeUTF8));
        pbShifterY->setText(QApplication::translate("BasicSettings", "Set Y With Step", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("BasicSettings", "Picker", 0, QApplication::UnicodeUTF8));
        pbPickerY->setText(QApplication::translate("BasicSettings", "Set Y With Step", 0, QApplication::UnicodeUTF8));
        pbPickerX->setText(QApplication::translate("BasicSettings", "Set X Equal", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("BasicSettings", "Parameter Set 2", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("BasicSettings", "Step:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BasicSettings: public Ui_BasicSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BASICSETTINGS_H
