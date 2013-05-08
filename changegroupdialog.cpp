#include "changegroupdialog.h"
#include "ui_changegroupdialog.h"

#include <QDebug>
#include "settings.h"

ChangeGroupDialog::ChangeGroupDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangeGroupDialog)
{
    ui->setupUi(this);

    Settings *settings = Settings::Instance();
    for(int i = 0; i < 24; i++) {
        QListWidgetItem *item = new QListWidgetItem();
        item->setBackgroundColor(settings->getColors().at(i));
        item->setText(QString::number(i));
        ui->listWidget->addItem(item);
    }
}

ChangeGroupDialog::~ChangeGroupDialog()
{
    delete ui;
}

void ChangeGroupDialog::setModel(GroupsModel *model)
{
    ui->tvGroups->setModel(model);
    ui->tvGroups->hideColumn(0);
    ui->tvGroups->hideColumn(3);
    ui->tvGroups->resizeColumnsToContents();
}

void ChangeGroupDialog::addNewGroup()
{
    QString groupname = ui->lineEdit->text();
    int tape = ui->spinBox->value();
    qDebug() << "New group: " + groupname + " = " + tape;
    GroupsModel *model = (GroupsModel*)ui->tvGroups->model();
    model->appendRow(tape, groupname);
}

void ChangeGroupDialog::on_pbAdd_clicked()
{
    addNewGroup();
}

QModelIndex ChangeGroupDialog::getSelectedIndex()
{
    return ui->tvGroups->currentIndex();
}
