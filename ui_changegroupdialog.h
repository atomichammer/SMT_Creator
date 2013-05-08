/********************************************************************************
** Form generated from reading UI file 'changegroupdialog.ui'
**
** Created: Wed 8. May 13:18:32 2013
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEGROUPDIALOG_H
#define UI_CHANGEGROUPDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTableView>

QT_BEGIN_NAMESPACE

class Ui_ChangeGroupDialog
{
public:
    QGridLayout *gridLayout;
    QTableView *tvGroups;
    QLabel *label;
    QLineEdit *lineEdit;
    QSpinBox *spinBox;
    QDialogButtonBox *buttonBox;
    QLabel *label_2;
    QPushButton *pbAdd;
    QListWidget *listWidget;

    void setupUi(QDialog *ChangeGroupDialog)
    {
        if (ChangeGroupDialog->objectName().isEmpty())
            ChangeGroupDialog->setObjectName(QString::fromUtf8("ChangeGroupDialog"));
        ChangeGroupDialog->resize(212, 300);
        gridLayout = new QGridLayout(ChangeGroupDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tvGroups = new QTableView(ChangeGroupDialog);
        tvGroups->setObjectName(QString::fromUtf8("tvGroups"));
        tvGroups->setSelectionMode(QAbstractItemView::SingleSelection);
        tvGroups->setSelectionBehavior(QAbstractItemView::SelectRows);

        gridLayout->addWidget(tvGroups, 0, 0, 1, 3);

        label = new QLabel(ChangeGroupDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        lineEdit = new QLineEdit(ChangeGroupDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMaxLength(10);

        gridLayout->addWidget(lineEdit, 2, 0, 1, 1);

        spinBox = new QSpinBox(ChangeGroupDialog);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMinimum(1);
        spinBox->setMaximum(24);

        gridLayout->addWidget(spinBox, 2, 1, 1, 1);

        buttonBox = new QDialogButtonBox(ChangeGroupDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 3, 0, 1, 2);

        label_2 = new QLabel(ChangeGroupDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 1, 1, 1);

        pbAdd = new QPushButton(ChangeGroupDialog);
        pbAdd->setObjectName(QString::fromUtf8("pbAdd"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(28);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pbAdd->sizePolicy().hasHeightForWidth());
        pbAdd->setSizePolicy(sizePolicy);
        pbAdd->setMaximumSize(QSize(28, 16777215));

        gridLayout->addWidget(pbAdd, 2, 2, 1, 1);

        listWidget = new QListWidget(ChangeGroupDialog);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        gridLayout->addWidget(listWidget, 0, 3, 1, 1);


        retranslateUi(ChangeGroupDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ChangeGroupDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ChangeGroupDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ChangeGroupDialog);
    } // setupUi

    void retranslateUi(QDialog *ChangeGroupDialog)
    {
        ChangeGroupDialog->setWindowTitle(QApplication::translate("ChangeGroupDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ChangeGroupDialog", "Name:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ChangeGroupDialog", "Tape:", 0, QApplication::UnicodeUTF8));
        pbAdd->setText(QApplication::translate("ChangeGroupDialog", "+", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ChangeGroupDialog: public Ui_ChangeGroupDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEGROUPDIALOG_H
