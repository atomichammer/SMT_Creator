#include "fnumber.h"
#include "ui_fnumber.h"

FNumber::FNumber(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FNumber)
{
    ui->setupUi(this);
    for(int i=1;i<17;i++){
        ui->comboBox->addItem(QString::number(i,10));
    }
}

FNumber::~FNumber()
{
    delete ui;
}

void FNumber::accept()
{
    num = ui->comboBox->currentIndex();
    selected = ui->rbSelected->isChecked();
    done(Accepted);
}

void FNumber::on_comboBox_currentIndexChanged(int index)
{
    QString name = QString("usrsmt%1.qgn").arg(QString::number(index + 1).rightJustified(2, QChar('0')));
    ui->label_2->setText(name);
}
