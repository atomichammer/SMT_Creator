/********************************************************************************
** Form generated from reading UI file 'fnumber.ui'
**
** Created: Fri Apr 5 17:50:21 2013
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FNUMBER_H
#define UI_FNUMBER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QRadioButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_FNumber
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *comboBox;
    QLabel *label_2;
    QRadioButton *rbSelected;
    QRadioButton *rbAll;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *FNumber)
    {
        if (FNumber->objectName().isEmpty())
            FNumber->setObjectName(QString::fromUtf8("FNumber"));
        FNumber->resize(178, 147);
        verticalLayout = new QVBoxLayout(FNumber);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(FNumber);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout->addWidget(comboBox, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        rbSelected = new QRadioButton(groupBox);
        rbSelected->setObjectName(QString::fromUtf8("rbSelected"));

        gridLayout->addWidget(rbSelected, 2, 1, 1, 1);

        rbAll = new QRadioButton(groupBox);
        rbAll->setObjectName(QString::fromUtf8("rbAll"));
        rbAll->setChecked(true);

        gridLayout->addWidget(rbAll, 2, 0, 1, 1);


        verticalLayout->addWidget(groupBox);

        buttonBox = new QDialogButtonBox(FNumber);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(FNumber);
        QObject::connect(buttonBox, SIGNAL(accepted()), FNumber, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), FNumber, SLOT(reject()));

        QMetaObject::connectSlotsByName(FNumber);
    } // setupUi

    void retranslateUi(QDialog *FNumber)
    {
        FNumber->setWindowTitle(QApplication::translate("FNumber", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("FNumber", "Filename", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("FNumber", "Number:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("FNumber", "Filename:", 0, QApplication::UnicodeUTF8));
        rbSelected->setText(QApplication::translate("FNumber", "Selected", 0, QApplication::UnicodeUTF8));
        rbAll->setText(QApplication::translate("FNumber", "All", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FNumber: public Ui_FNumber {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FNUMBER_H
