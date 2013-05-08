/********************************************************************************
** Form generated from reading UI file 'orderby.ui'
**
** Created: Fri Apr 5 17:50:21 2013
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDERBY_H
#define UI_ORDERBY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QRadioButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_OrderBy
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *rbXCoord;
    QRadioButton *rbYCoord;
    QRadioButton *rbTape;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *OrderBy)
    {
        if (OrderBy->objectName().isEmpty())
            OrderBy->setObjectName(QString::fromUtf8("OrderBy"));
        OrderBy->resize(178, 150);
        OrderBy->setMaximumSize(QSize(178, 150));
        verticalLayout = new QVBoxLayout(OrderBy);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(OrderBy);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        rbXCoord = new QRadioButton(groupBox);
        rbXCoord->setObjectName(QString::fromUtf8("rbXCoord"));
        rbXCoord->setChecked(true);

        verticalLayout_2->addWidget(rbXCoord);

        rbYCoord = new QRadioButton(groupBox);
        rbYCoord->setObjectName(QString::fromUtf8("rbYCoord"));

        verticalLayout_2->addWidget(rbYCoord);

        rbTape = new QRadioButton(groupBox);
        rbTape->setObjectName(QString::fromUtf8("rbTape"));

        verticalLayout_2->addWidget(rbTape);


        verticalLayout->addWidget(groupBox);

        buttonBox = new QDialogButtonBox(OrderBy);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(OrderBy);
        QObject::connect(buttonBox, SIGNAL(accepted()), OrderBy, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), OrderBy, SLOT(reject()));

        QMetaObject::connectSlotsByName(OrderBy);
    } // setupUi

    void retranslateUi(QDialog *OrderBy)
    {
        OrderBy->setWindowTitle(QApplication::translate("OrderBy", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("OrderBy", "Order By", 0, QApplication::UnicodeUTF8));
        rbXCoord->setText(QApplication::translate("OrderBy", "X Coordinate", 0, QApplication::UnicodeUTF8));
        rbYCoord->setText(QApplication::translate("OrderBy", "Y Coordinate", 0, QApplication::UnicodeUTF8));
        rbTape->setText(QApplication::translate("OrderBy", "Tape", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class OrderBy: public Ui_OrderBy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDERBY_H
