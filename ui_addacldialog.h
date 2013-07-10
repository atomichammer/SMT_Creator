/********************************************************************************
** Form generated from reading UI file 'addacldialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDACLDIALOG_H
#define UI_ADDACLDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QListView>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableView>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddACLDialog
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QToolButton *pbAddToRejectList;
    QToolButton *pbRemoveFromRejectList;
    QToolButton *pbAddToAcceptList;
    QToolButton *pbRemoveFromAcceptList;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QListWidget *lwRejectList;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QListView *lvFootprints;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_2;
    QTableView *tvAcceptedFootprints;

    void setupUi(QDialog *AddACLDialog)
    {
        if (AddACLDialog->objectName().isEmpty())
            AddACLDialog->setObjectName(QString::fromUtf8("AddACLDialog"));
        AddACLDialog->resize(556, 296);
        gridLayout = new QGridLayout(AddACLDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 3, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 3, 1, 1);

        frame = new QFrame(AddACLDialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Sunken);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        gridLayout->addWidget(frame, 5, 0, 1, 6);

        pbAddToRejectList = new QToolButton(AddACLDialog);
        pbAddToRejectList->setObjectName(QString::fromUtf8("pbAddToRejectList"));
        pbAddToRejectList->setMinimumSize(QSize(32, 32));

        gridLayout->addWidget(pbAddToRejectList, 1, 1, 1, 1);

        pbRemoveFromRejectList = new QToolButton(AddACLDialog);
        pbRemoveFromRejectList->setObjectName(QString::fromUtf8("pbRemoveFromRejectList"));
        pbRemoveFromRejectList->setMinimumSize(QSize(32, 32));

        gridLayout->addWidget(pbRemoveFromRejectList, 2, 1, 1, 1);

        pbAddToAcceptList = new QToolButton(AddACLDialog);
        pbAddToAcceptList->setObjectName(QString::fromUtf8("pbAddToAcceptList"));
        pbAddToAcceptList->setMinimumSize(QSize(32, 32));

        gridLayout->addWidget(pbAddToAcceptList, 1, 3, 1, 1);

        pbRemoveFromAcceptList = new QToolButton(AddACLDialog);
        pbRemoveFromAcceptList->setObjectName(QString::fromUtf8("pbRemoveFromAcceptList"));
        pbRemoveFromAcceptList->setMinimumSize(QSize(32, 32));

        gridLayout->addWidget(pbRemoveFromAcceptList, 2, 3, 1, 1);

        groupBox = new QGroupBox(AddACLDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(150, 0));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lwRejectList = new QListWidget(groupBox);
        lwRejectList->setObjectName(QString::fromUtf8("lwRejectList"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lwRejectList->sizePolicy().hasHeightForWidth());
        lwRejectList->setSizePolicy(sizePolicy1);
        QPalette palette;
        QBrush brush(QColor(127, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        QBrush brush1(QColor(113, 112, 110, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        lwRejectList->setPalette(palette);

        verticalLayout->addWidget(lwRejectList);


        gridLayout->addWidget(groupBox, 0, 0, 4, 1);

        groupBox_2 = new QGroupBox(AddACLDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        groupBox_2->setMinimumSize(QSize(150, 0));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lvFootprints = new QListView(groupBox_2);
        lvFootprints->setObjectName(QString::fromUtf8("lvFootprints"));
        sizePolicy1.setHeightForWidth(lvFootprints->sizePolicy().hasHeightForWidth());
        lvFootprints->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(lvFootprints);


        gridLayout->addWidget(groupBox_2, 0, 2, 4, 1);

        groupBox_3 = new QGroupBox(AddACLDialog);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        sizePolicy.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy);
        groupBox_3->setMinimumSize(QSize(150, 0));
        horizontalLayout_2 = new QHBoxLayout(groupBox_3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        tvAcceptedFootprints = new QTableView(groupBox_3);
        tvAcceptedFootprints->setObjectName(QString::fromUtf8("tvAcceptedFootprints"));
        sizePolicy1.setHeightForWidth(tvAcceptedFootprints->sizePolicy().hasHeightForWidth());
        tvAcceptedFootprints->setSizePolicy(sizePolicy1);
        tvAcceptedFootprints->setSelectionMode(QAbstractItemView::SingleSelection);
        tvAcceptedFootprints->setSelectionBehavior(QAbstractItemView::SelectRows);

        horizontalLayout_2->addWidget(tvAcceptedFootprints);


        gridLayout->addWidget(groupBox_3, 0, 4, 4, 2);


        retranslateUi(AddACLDialog);
        QObject::connect(pushButton, SIGNAL(clicked()), AddACLDialog, SLOT(accept()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), AddACLDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddACLDialog);
    } // setupUi

    void retranslateUi(QDialog *AddACLDialog)
    {
        AddACLDialog->setWindowTitle(QApplication::translate("AddACLDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("AddACLDialog", "Ok", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("AddACLDialog", "Cancel", 0, QApplication::UnicodeUTF8));
        pbAddToRejectList->setText(QApplication::translate("AddACLDialog", "<", 0, QApplication::UnicodeUTF8));
        pbRemoveFromRejectList->setText(QApplication::translate("AddACLDialog", ">", 0, QApplication::UnicodeUTF8));
        pbAddToAcceptList->setText(QApplication::translate("AddACLDialog", ">", 0, QApplication::UnicodeUTF8));
        pbRemoveFromAcceptList->setText(QApplication::translate("AddACLDialog", "<", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("AddACLDialog", "Black List", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("AddACLDialog", "Not Assigned", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("AddACLDialog", "White List", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AddACLDialog: public Ui_AddACLDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDACLDIALOG_H
