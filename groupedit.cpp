#include "groupedit.h"
#include "ui_groupedit.h"
#include <QDebug>

GroupEdit::GroupEdit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GroupEdit)
{
    ui->setupUi(this);
}

GroupEdit::~GroupEdit()
{
    delete ui;
}

void GroupEdit::setModel(QAbstractTableModel *model)
{
    ui->tvGroups->setModel(model);
    ui->tvGroups->resizeColumnsToContents();
}
