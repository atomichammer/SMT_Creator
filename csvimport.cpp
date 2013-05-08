#include "csvimport.h"
#include "ui_csvimport.h"
#include <QDebug>

CSVImport::CSVImport(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CSVImport)
{
    ui->setupUi(this);
}

CSVImport::~CSVImport()
{
    delete ui;
}


void CSVImport::setData(QList<QStringList> _data)
{
    data = _data;
    ui->cbImportPartName->addItems(data.at(0));
    ui->cbImportPartName->setCurrentIndex(0);

    ui->cbImportGroupBy->addItems(data.at(0));
    ui->cbImportGroupBy->setCurrentIndex(10);

    ui->cbImportXPos->addItems(data.at(0));
    ui->cbImportXPos->setCurrentIndex(2);

    ui->cbImportYPos->addItems(data.at(0));
    ui->cbImportYPos->setCurrentIndex(3);

    ui->cbImportAngle->addItems(data.at(0));
    ui->cbImportAngle->setCurrentIndex(9);
}

void CSVImport::accept()
{
    list.append(ui->cbImportPartName->currentIndex());
    list.append(ui->cbImportXPos->currentIndex());
    list.append(ui->cbImportYPos->currentIndex());
    list.append(ui->cbImportAngle->currentIndex());
    list.append(ui->cbImportGroupBy->currentIndex());
    done(Accepted);
}
