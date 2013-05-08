/********************************************************************************
** Form generated from reading UI file 'groupedit.ui'
**
** Created: Mon 24. Sep 14:16:08 2012
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPEDIT_H
#define UI_GROUPEDIT_H

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
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_GroupEdit
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QListWidget *listWidget;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QSpinBox *spinBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QDialogButtonBox *buttonBox;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *GroupEdit)
    {
        if (GroupEdit->objectName().isEmpty())
            GroupEdit->setObjectName(QString::fromUtf8("GroupEdit"));
        GroupEdit->resize(287, 300);
        gridLayout = new QGridLayout(GroupEdit);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(GroupEdit);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        listWidget = new QListWidget(groupBox);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy);
        listWidget->setLayoutMode(QListView::SinglePass);

        gridLayout_2->addWidget(listWidget, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 5, 3);

        label = new QLabel(GroupEdit);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 3, 1, 1);

        lineEdit = new QLineEdit(GroupEdit);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 1, 3, 1, 1);

        label_2 = new QLabel(GroupEdit);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 3, 1, 1);

        spinBox = new QSpinBox(GroupEdit);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        gridLayout->addWidget(spinBox, 3, 3, 1, 1);

        pushButton = new QPushButton(GroupEdit);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);
        pushButton->setMaximumSize(QSize(32, 16777215));

        gridLayout->addWidget(pushButton, 5, 0, 1, 1);

        pushButton_2 = new QPushButton(GroupEdit);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMaximumSize(QSize(32, 16777215));

        gridLayout->addWidget(pushButton_2, 5, 1, 1, 1);

        buttonBox = new QDialogButtonBox(GroupEdit);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 6, 0, 1, 4);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 4, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 5, 2, 1, 2);


        retranslateUi(GroupEdit);
        QObject::connect(buttonBox, SIGNAL(accepted()), GroupEdit, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), GroupEdit, SLOT(reject()));

        QMetaObject::connectSlotsByName(GroupEdit);
    } // setupUi

    void retranslateUi(QDialog *GroupEdit)
    {
        GroupEdit->setWindowTitle(QApplication::translate("GroupEdit", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("GroupEdit", "Groups List:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("GroupEdit", "Name:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("GroupEdit", "Tape:", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("GroupEdit", "+", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("GroupEdit", "-", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GroupEdit: public Ui_GroupEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPEDIT_H
