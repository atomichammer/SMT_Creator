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

void DialogMoveRotate::setFirstXCoord(quint32 x)
{
    ui->sbFirstX->setValue(x);
}

void DialogMoveRotate::setFirstYCoord(quint32 y)
{
    ui->sbFirstY->setValue(y);
}

void DialogMoveRotate::setSecondXCoord(quint32 x)
{
    ui->sbSecondX->setValue(x);
}

void DialogMoveRotate::setSecondYCoord(quint32 y)
{
    ui->sbSecondY->setValue(y);
}
