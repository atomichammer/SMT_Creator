/********************************************************************************
** Form generated from reading UI file 'csvimport.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CSVIMPORT_H
#define UI_CSVIMPORT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_CSVImport
{
public:
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QComboBox *cbImportPartName;
    QTableWidget *tableWidget;
    QCheckBox *cbIgnoreFirstString;
    QComboBox *cbImportAngle;
    QComboBox *cbImportXPos;
    QComboBox *cbImportYPos;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QComboBox *cbImportGroupBy;
    QLabel *label_6;

    void setupUi(QDialog *CSVImport)
    {
        if (CSVImport->objectName().isEmpty())
            CSVImport->setObjectName(QString::fromUtf8("CSVImport"));
        CSVImport->resize(522, 350);
        gridLayout = new QGridLayout(CSVImport);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        buttonBox = new QDialogButtonBox(CSVImport);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);

        groupBox = new QGroupBox(CSVImport);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        cbImportPartName = new QComboBox(groupBox);
        cbImportPartName->setObjectName(QString::fromUtf8("cbImportPartName"));

        gridLayout_2->addWidget(cbImportPartName, 1, 0, 1, 1);

        tableWidget = new QTableWidget(groupBox);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        gridLayout_2->addWidget(tableWidget, 3, 0, 1, 5);

        cbIgnoreFirstString = new QCheckBox(groupBox);
        cbIgnoreFirstString->setObjectName(QString::fromUtf8("cbIgnoreFirstString"));

        gridLayout_2->addWidget(cbIgnoreFirstString, 4, 0, 1, 1);

        cbImportAngle = new QComboBox(groupBox);
        cbImportAngle->setObjectName(QString::fromUtf8("cbImportAngle"));

        gridLayout_2->addWidget(cbImportAngle, 1, 4, 1, 1);

        cbImportXPos = new QComboBox(groupBox);
        cbImportXPos->setObjectName(QString::fromUtf8("cbImportXPos"));

        gridLayout_2->addWidget(cbImportXPos, 1, 2, 1, 1);

        cbImportYPos = new QComboBox(groupBox);
        cbImportYPos->setObjectName(QString::fromUtf8("cbImportYPos"));

        gridLayout_2->addWidget(cbImportYPos, 1, 3, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 0, 2, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 0, 3, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 0, 4, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 2, 0, 1, 1);

        cbImportGroupBy = new QComboBox(groupBox);
        cbImportGroupBy->setObjectName(QString::fromUtf8("cbImportGroupBy"));

        gridLayout_2->addWidget(cbImportGroupBy, 1, 1, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 0, 1, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);


        retranslateUi(CSVImport);
        QObject::connect(buttonBox, SIGNAL(accepted()), CSVImport, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CSVImport, SLOT(reject()));

        QMetaObject::connectSlotsByName(CSVImport);
    } // setupUi

    void retranslateUi(QDialog *CSVImport)
    {
        CSVImport->setWindowTitle(QApplication::translate("CSVImport", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("CSVImport", "Select columns to import", 0, QApplication::UnicodeUTF8));
        cbIgnoreFirstString->setText(QApplication::translate("CSVImport", "Ignore First String", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CSVImport", "Part Name", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("CSVImport", "X Position", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("CSVImport", "Y Position", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("CSVImport", "Angle", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("CSVImport", "Imported file:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("CSVImport", "Group By", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CSVImport: public Ui_CSVImport {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CSVIMPORT_H
