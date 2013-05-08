#include "ui_newpart.h"
#include "newpart.h"

#include <QDataWidgetMapper>

Newpart::Newpart(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Newpart)
{
    ui->setupUi(this);
}

Newpart::~Newpart()
{
    delete ui;
}

quint32 Newpart::getXCoord()
{
    return ui->sbXCoord->value();
}

quint32 Newpart::getYCoord()
{
    return ui->sbYCoord->value();
}

int Newpart::getAngle()
{
    return ui->sbAngle->value();
}

int Newpart::getGroup()
{
    return ui->cbGroup->currentIndex();
}

QString Newpart::getName()
{
    return ui->leName->text();
}

int Newpart::getGroupID()
{
    return ui->cbGroup->currentIndex();
}

/*
void Newpart::setGroups(QStringList list)
{
    ui->cbGroup->addItems(list);
}
*/
void Newpart::setModel(GroupsModel *model_)
{
    model = model_;
    ui->cbGroup->setModel(model);
    ui->cbGroup->setModelColumn(2);
    QDataWidgetMapper *mapper = new QDataWidgetMapper();
    mapper->setModel(model);
    mapper->addMapping(ui->leTape, 1);
    connect(ui->cbGroup, SIGNAL(currentIndexChanged(int)), mapper, SLOT(setCurrentIndex(int)));
}
