/********************************************************************************
** Form generated from reading UI file 'newpart.ui'
**
** Created: Mon 24. Sep 14:16:08 2012
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWPART_H
#define UI_NEWPART_H

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
#include <QtGui/QLineEdit>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_newpart
{
public:
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QSpinBox *sbXCoord;
    QLabel *label_2;
    QSpinBox *sbYCoord;
    QLabel *label_3;
    QComboBox *cbGroup;
    QLabel *label_4;
    QSpinBox *sbAngle;
    QLabel *label_5;
    QLineEdit *leName;

    void setupUi(QDialog *newpart)
    {
        if (newpart->objectName().isEmpty())
            newpart->setObjectName(QString::fromUtf8("newpart"));
        newpart->resize(178, 208);
        newpart->setMaximumSize(QSize(178, 208));
        gridLayout = new QGridLayout(newpart);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        buttonBox = new QDialogButtonBox(newpart);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 1, 1, 1);

        groupBox = new QGroupBox(newpart);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        sbXCoord = new QSpinBox(groupBox);
        sbXCoord->setObjectName(QString::fromUtf8("sbXCoord"));
        sbXCoord->setMaximum(70000);

        gridLayout_2->addWidget(sbXCoord, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        sbYCoord = new QSpinBox(groupBox);
        sbYCoord->setObjectName(QString::fromUtf8("sbYCoord"));
        sbYCoord->setMaximum(70000);

        gridLayout_2->addWidget(sbYCoord, 1, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        cbGroup = new QComboBox(groupBox);
        cbGroup->setObjectName(QString::fromUtf8("cbGroup"));

        gridLayout_2->addWidget(cbGroup, 2, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 3, 0, 1, 1);

        sbAngle = new QSpinBox(groupBox);
        sbAngle->setObjectName(QString::fromUtf8("sbAngle"));
        sbAngle->setMinimum(-180);
        sbAngle->setMaximum(180);

        gridLayout_2->addWidget(sbAngle, 3, 1, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 4, 0, 1, 1);

        leName = new QLineEdit(groupBox);
        leName->setObjectName(QString::fromUtf8("leName"));
        leName->setMaxLength(5);

        gridLayout_2->addWidget(leName, 4, 1, 1, 1);


        gridLayout->addWidget(groupBox, 0, 1, 1, 1);


        retranslateUi(newpart);
        QObject::connect(buttonBox, SIGNAL(accepted()), newpart, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), newpart, SLOT(reject()));

        QMetaObject::connectSlotsByName(newpart);
    } // setupUi

    void retranslateUi(QDialog *newpart)
    {
        newpart->setWindowTitle(QApplication::translate("newpart", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("newpart", "Element", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("newpart", "X", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("newpart", "Y", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("newpart", "Group", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("newpart", "Angle", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("newpart", "Name", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Newpart: public Ui_newpart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWPART_H
