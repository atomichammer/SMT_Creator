#include "basicgroupsdialog.h"
#include "ui_basicgroupsdialog.h"

BasicGroupsDialog::BasicGroupsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BasicGroupsDialog)
{
    ui->setupUi(this);
}

BasicGroupsDialog::~BasicGroupsDialog()
{
    delete ui;
}

void BasicGroupsDialog::setModel(GroupsModel *model)
{
    basicGroups = model;
    ui->tvBasicGroups->setModel(model);
    ui->tvBasicGroups->resizeColumnsToContents();
}

void BasicGroupsDialog::addGroup()
{
    basicGroups->appendRow(1, tr("NewGroup"));
    ui->tvBasicGroups->resizeColumnsToContents();
}

void BasicGroupsDialog::removeGroup()
{
    QModelIndex index = ui->tvBasicGroups->currentIndex();
    if(index.isValid())
    {
        basicGroups->removeRow(index.row(), QModelIndex());
    }
}

void BasicGroupsDialog::on_pbAddGroup_clicked()
{
    addGroup();
}

void BasicGroupsDialog::on_pbRemoveGroup_clicked()
{
    removeGroup();
}
