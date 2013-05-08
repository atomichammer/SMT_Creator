#include "dialogmoverotate.h"
#include "ui_dialogmoverotate.h"

DialogMoveRotate::DialogMoveRotate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogMoveRotate)
{
    ui->setupUi(this);
}

DialogMoveRotate::~DialogMoveRotate()
{
    delete ui;
}

quint32 DialogMoveRotate::getFirstXCoord()
{
    return ui->sbFirstX->value();
}

quint32 DialogMoveRotate::getFirstYCoord()
{
    return ui->sbFirstY->value();
}

quint32 DialogMoveRotate::getSecondXCoord()
{
    return ui->sbSecondX->value();
}

quint32 DialogMoveRotate::getSecondYCoord()
{
    return ui->sbSecondY->value();
}
