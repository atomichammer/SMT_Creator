#include "orderby.h"
#include "ui_orderby.h"

OrderBy::OrderBy(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OrderBy)
{
    ui->setupUi(this);
}

OrderBy::~OrderBy()
{
    delete ui;
}

void OrderBy::accept()
{
    num = 0;
    if(ui->rbXCoord->isChecked())
        num = 0;
    else if (ui->rbYCoord->isChecked())
        num = 1;
    else if (ui->rbTape->isChecked())
        num = 2;
    done(Accepted);
}
