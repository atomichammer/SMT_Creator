/********************************************************************************
** Form generated from reading UI file 'groupedit.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
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
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QTableView>

QT_BEGIN_NAMESPACE

class Ui_GroupEdit
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QTableView *tvGroups;

    void setupUi(QDialog *GroupEdit)
    {
        if (GroupEdit->objectName().isEmpty())
            GroupEdit->setObjectName(QString::fromUtf8("GroupEdit"));
        GroupEdit->resize(296, 300);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GroupEdit->sizePolicy().hasHeightForWidth());
        GroupEdit->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(GroupEdit);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(GroupEdit);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        tvGroups = new QTableView(groupBox);
        tvGroups->setObjectName(QString::fromUtf8("tvGroups"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tvGroups->sizePolicy().hasHeightForWidth());
        tvGroups->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(tvGroups, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 2, 2);


        retranslateUi(GroupEdit);

        QMetaObject::connectSlotsByName(GroupEdit);
    } // setupUi

    void retranslateUi(QDialog *GroupEdit)
    {
        GroupEdit->setWindowTitle(QApplication::translate("GroupEdit", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("GroupEdit", "List of imported groups", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GroupEdit: public Ui_GroupEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPEDIT_H
