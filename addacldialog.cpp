#include "addacldialog.h"
#include "ui_addacldialog.h"
#include <QDebug>
#include "settings.h"


AddACLDialog::AddACLDialog(GroupsModel *_groupsModel, GroupsACLModel *_groupsACLModel, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddACLDialog)
{
    ui->setupUi(this);
    Settings *settings = Settings::Instance();
    ui->lwRejectList->insertItems(0, *settings->getGroupsRejectList());
    ACLFilter = new GroupsACLFilter(settings->getGroupsRejectList(), _groupsACLModel);

    groupsModel = _groupsModel;

    groupsACLModel = _groupsACLModel;
    ui->tvAcceptedFootprints->setModel(groupsACLModel);
    ui->tvAcceptedFootprints->resizeColumnsToContents();

    ACLFilter->setSourceModel(_groupsModel);
    ui->lvFootprints->setModel(ACLFilter);
    ui->lvFootprints->setModelColumn(2);
}

AddACLDialog::~AddACLDialog()
{
    delete ui;
}

void AddACLDialog::on_pbAddToRejectList_clicked()
{

    Settings *settings = Settings::Instance();
    QStringList *list = settings->getGroupsRejectList();

    QModelIndex index = ACLFilter->mapToSource(ui->lvFootprints->currentIndex());
    index = groupsModel->index(index.row(), 2, QModelIndex());
    QString name = groupsModel->data(index, Qt::DisplayRole).toString();

    if(!settings->getGroupsRejectList()->contains(name, Qt::CaseInsensitive))
    {
        list->append(name);
        ui->lwRejectList->insertItem(ui->lwRejectList->count(), name);
        settings->setGroupsRejectList(*list);
        groupsModel->resetModel();
    }
}

void AddACLDialog::on_pbRemoveFromRejectList_clicked()
{
    Settings *settings = Settings::Instance();
    QStringList *list = settings->getGroupsRejectList();
    list->removeOne(ui->lwRejectList->currentItem()->text());
    settings->setGroupsRejectList(*list);
    ui->lwRejectList->model()->removeRow(ui->lwRejectList->currentRow());
    groupsModel->resetModel();
}

void AddACLDialog::on_pbAddToAcceptList_clicked()
{
    ACL record;
    QList<ACL> *list = groupsACLModel->getGroupsACLList();

    QModelIndex index = ACLFilter->mapToSource(ui->lvFootprints->currentIndex());
    index = groupsModel->index(index.row(), 2, QModelIndex());
    record.name = groupsModel->data(index, Qt::DisplayRole).toString();
    index = groupsModel->index(index.row(), 1, QModelIndex());
    record.tape = groupsModel->data(index, Qt::DisplayRole).toInt();

    if(!groupsACLModel->getNames()->contains(record.name, Qt::CaseInsensitive))
    {
        list->append(record);
        groupsACLModel->resetModel();
        groupsModel->resetModel();
        ui->tvAcceptedFootprints->resizeColumnsToContents();
    }
}

void AddACLDialog::on_pbRemoveFromAcceptList_clicked()
{
    QModelIndex index = ui->tvAcceptedFootprints->currentIndex();

    if(index.isValid())
    {
        groupsACLModel->removeRow(index.row(), QModelIndex());
        groupsACLModel->resetModel();
        groupsModel->resetModel();
    }
}
