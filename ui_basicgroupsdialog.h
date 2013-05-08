/********************************************************************************
** Form generated from reading UI file 'basicgroupsdialog.ui'
**
** Created: Fri Apr 5 17:50:21 2013
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BASICGROUPSDIALOG_H
#define UI_BASICGROUPSDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BasicGroupsDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QTableView *tvBasicGroups;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QPushButton *pbAddGroup;
    QPushButton *pbRemoveGroup;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *BasicGroupsDialog)
    {
        if (BasicGroupsDialog->objectName().isEmpty())
            BasicGroupsDialog->setObjectName(QString::fromUtf8("BasicGroupsDialog"));
        BasicGroupsDialog->resize(367, 300);
        horizontalLayout = new QHBoxLayout(BasicGroupsDialog);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tvBasicGroups = new QTableView(BasicGroupsDialog);
        tvBasicGroups->setObjectName(QString::fromUtf8("tvBasicGroups"));
        tvBasicGroups->setSelectionMode(QAbstractItemView::SingleSelection);
        tvBasicGroups->setSelectionBehavior(QAbstractItemView::SelectRows);

        horizontalLayout->addWidget(tvBasicGroups);

        frame = new QFrame(BasicGroupsDialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pbAddGroup = new QPushButton(frame);
        pbAddGroup->setObjectName(QString::fromUtf8("pbAddGroup"));

        verticalLayout->addWidget(pbAddGroup);

        pbRemoveGroup = new QPushButton(frame);
        pbRemoveGroup->setObjectName(QString::fromUtf8("pbRemoveGroup"));

        verticalLayout->addWidget(pbRemoveGroup);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(frame);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy);
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(false);

        verticalLayout->addWidget(buttonBox);


        horizontalLayout->addWidget(frame);


        retranslateUi(BasicGroupsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), BasicGroupsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), BasicGroupsDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(BasicGroupsDialog);
    } // setupUi

    void retranslateUi(QDialog *BasicGroupsDialog)
    {
        BasicGroupsDialog->setWindowTitle(QApplication::translate("BasicGroupsDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        pbAddGroup->setText(QApplication::translate("BasicGroupsDialog", "Add", 0, QApplication::UnicodeUTF8));
        pbRemoveGroup->setText(QApplication::translate("BasicGroupsDialog", "Remove", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BasicGroupsDialog: public Ui_BasicGroupsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BASICGROUPSDIALOG_H
