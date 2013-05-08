/********************************************************************************
** Form generated from reading UI file 'dialogmoverotate.ui'
**
** Created: Fri Apr 5 17:50:21 2013
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGMOVEROTATE_H
#define UI_DIALOGMOVEROTATE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogMoveRotate
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QSpinBox *sbFirstX;
    QSpinBox *sbFirstY;
    QSpinBox *sbSecondY;
    QSpinBox *sbSecondX;
    QLabel *label;
    QLabel *label_7;
    QLabel *label_10;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogMoveRotate)
    {
        if (DialogMoveRotate->objectName().isEmpty())
            DialogMoveRotate->setObjectName(QString::fromUtf8("DialogMoveRotate"));
        DialogMoveRotate->resize(178, 246);
        DialogMoveRotate->setMinimumSize(QSize(178, 246));
        DialogMoveRotate->setMaximumSize(QSize(178, 246));
        verticalLayout = new QVBoxLayout(DialogMoveRotate);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox_2 = new QGroupBox(DialogMoveRotate);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMaximumSize(QSize(160, 16777215));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        sbFirstX = new QSpinBox(groupBox_2);
        sbFirstX->setObjectName(QString::fromUtf8("sbFirstX"));
        sbFirstX->setMaximum(75000);
        sbFirstX->setValue(35168);

        gridLayout_2->addWidget(sbFirstX, 2, 0, 1, 1);

        sbFirstY = new QSpinBox(groupBox_2);
        sbFirstY->setObjectName(QString::fromUtf8("sbFirstY"));
        sbFirstY->setMaximum(75000);
        sbFirstY->setValue(2512);

        gridLayout_2->addWidget(sbFirstY, 2, 1, 1, 1);

        sbSecondY = new QSpinBox(groupBox_2);
        sbSecondY->setObjectName(QString::fromUtf8("sbSecondY"));
        sbSecondY->setMaximum(75000);
        sbSecondY->setValue(13104);

        gridLayout_2->addWidget(sbSecondY, 3, 1, 1, 1);

        sbSecondX = new QSpinBox(groupBox_2);
        sbSecondX->setObjectName(QString::fromUtf8("sbSecondX"));
        sbSecondX->setMaximum(75000);
        sbSecondX->setValue(60968);

        gridLayout_2->addWidget(sbSecondX, 3, 0, 1, 1);

        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 1, 0, 1, 1);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_2->addWidget(label_7, 1, 1, 1, 1);

        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setWordWrap(true);

        gridLayout_2->addWidget(label_10, 0, 0, 1, 2);


        verticalLayout->addWidget(groupBox_2);

        buttonBox = new QDialogButtonBox(DialogMoveRotate);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DialogMoveRotate);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogMoveRotate, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogMoveRotate, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogMoveRotate);
    } // setupUi

    void retranslateUi(QDialog *DialogMoveRotate)
    {
        DialogMoveRotate->setWindowTitle(QApplication::translate("DialogMoveRotate", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("DialogMoveRotate", "\320\237\320\265\321\200\320\265\320\275\320\276\321\201 \320\270 \320\277\320\276\320\262\320\276\321\200\320\276\321\202", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DialogMoveRotate", "x", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("DialogMoveRotate", "y", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("DialogMoveRotate", "\320\235\321\203\320\266\320\275\320\276 \320\262\321\213\320\261\321\200\320\260\321\202\321\214 \320\264\320\262\320\265 \320\264\320\270\320\260\320\263\320\276\320\275\320\260\320\273\321\214\320\275\320\276 \320\277\321\200\320\276\321\202\320\270\320\262\320\276\320\277\320\276\320\273\320\276\320\266\320\275\321\213\320\265 \320\267\320\260\320\277\321\207\320\260\321\201\321\202\320\270 (\320\277\321\200\320\260\320\262\321\203\321\216 \320\262\320\265\321\200\321\205\320\275\321\216\321\216 \320\270 \320\273\320\265\320\262\321\203\321\216 \320\275\320\270\320\266\320\275\321\216\321\216) \320\270 \320\262\320\262\320\265\321\201\321\202\320\270 \320\270\321\205 \321\200\320\265\320\260\320\273\321\214\320\275\321\213\320\265 \320\272\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\321\213. ", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogMoveRotate: public Ui_DialogMoveRotate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGMOVEROTATE_H
