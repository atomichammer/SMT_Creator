/********************************************************************************
** Form generated from reading UI file 'newpart.ui'
**
** Created: Wed 8. May 13:18:32 2013
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
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Newpart
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
    QSpacerItem *horizontalSpacer;
    QLineEdit *leTape;
    QLabel *label_6;

    void setupUi(QDialog *Newpart)
    {
        if (Newpart->objectName().isEmpty())
            Newpart->setObjectName(QString::fromUtf8("Newpart"));
        Newpart->resize(185, 208);
        Newpart->setMinimumSize(QSize(185, 208));
        Newpart->setMaximumSize(QSize(185, 208));
        gridLayout = new QGridLayout(Newpart);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        buttonBox = new QDialogButtonBox(Newpart);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 1, 1, 1);

        groupBox = new QGroupBox(Newpart);
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

        gridLayout_2->addWidget(leName, 4, 1, 1, 2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 2, 1, 1);

        leTape = new QLineEdit(groupBox);
        leTape->setObjectName(QString::fromUtf8("leTape"));
        leTape->setReadOnly(true);

        gridLayout_2->addWidget(leTape, 2, 2, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 1, 2, 1, 1);


        gridLayout->addWidget(groupBox, 0, 1, 1, 1);


        retranslateUi(Newpart);
        QObject::connect(buttonBox, SIGNAL(accepted()), Newpart, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Newpart, SLOT(reject()));

        QMetaObject::connectSlotsByName(Newpart);
    } // setupUi

    void retranslateUi(QDialog *Newpart)
    {
        Newpart->setWindowTitle(QApplication::translate("Newpart", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Newpart", "Element", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Newpart", "X", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Newpart", "Y", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Newpart", "Group", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Newpart", "Angle", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Newpart", "Name", 0, QApplication::UnicodeUTF8));
        leName->setText(QApplication::translate("Newpart", "R0", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Newpart", "Tape", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Newpart: public Ui_Newpart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWPART_H
