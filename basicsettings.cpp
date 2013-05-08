#include "basicsettings.h"
#include "ui_basicsettings.h"
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>

BasicSettings::BasicSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BasicSettings)
{
    ui->setupUi(this);
    model = new BasicSettingsModel();
    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
    fileOpen();
}

BasicSettings::~BasicSettings()
{
    delete ui;
}


void BasicSettings::fileOpen()
{
        QString fileName = QFileDialog::getOpenFileName(this, tr("Select Coords File"),
                    "",
                    tr("Data (*.qgn)"));
        if (!fileName.isEmpty())
                loadFile(fileName);
}

void BasicSettings::loadFile(const QString &fileName)
{
    QFile file(fileName);

    if(!file.open(QIODevice::ReadOnly))
    {
        return;
    } else {

        QList<quint32> dataList;
        QByteArray str;
        unsigned char c;
        quint32 q;
        QDataStream s(&file);
        s.setByteOrder(QDataStream::LittleEndian);

        for(int i=0;i<16; i++)
        {
            s >> c;
            str.append(c);
        }

        while(true)
        {
            s >> q;
            dataList.append(q);
            if (s.atEnd())
                break;
        }
        file.close();

        ui->sb1->setValue(dataList.at(4));
        ui->sb2->setValue(dataList.at(5));
        ui->sb3->setValue(dataList.at(6));
        ui->sb4->setValue(dataList.at(20));
        ui->sb5->setValue(dataList.at(21));
        ui->sb6->setValue(dataList.at(22));
        ui->sb7->setValue(dataList.at(28));
        ui->sb8->setValue(dataList.at(29));
        ui->sb9->setValue(dataList.at(30));
        ui->sb10->setValue(dataList.at(31));

        uchar k = 0;
        model->appendRow();
        for(int i = 48; i<dataList.length();i++)
        {
            if(k == 7){
                k = 0;
                i += 5;
                model->appendRow();
            }
            QModelIndex index;
            index = model->index(model->rowCount(QModelIndex())-1, k);
            model->setData(index, dataList.at(i), Qt::DisplayRole);
            k++;
            //qDebug() << dataList.at(i);
        }
    }
}

void BasicSettings::on_pbPickerX_clicked()
{
    QModelIndex index;
    index = model->index(0, 3);
    quint32 x = model->data(index).toULongLong();

    for(int i=1;i<model->rowCount(); i++)
    {
        index = model->index(i, 3);
        model->setData(index, x, Qt::DisplayRole);
    }
}

void BasicSettings::on_pbShifterX_clicked()
{
    QModelIndex index;
    index = model->index(0, 1);
    quint32 x = model->data(index).toULongLong();

    for(int i=1;i<model->rowCount(); i++)
    {
        index = model->index(i, 1);
        model->setData(index, x, Qt::DisplayRole);
    }
}

void BasicSettings::on_pbPickerY_clicked()
{
    QModelIndex index;
    index = model->index(0, 4);
    quint32 y = model->data(index).toULongLong();
    quint32 delta = ui->sbStep->value();

    for(int i=1;i<model->rowCount(); i++)
    {
        y += delta;
        index = model->index(i, 4);
        model->setData(index, y, Qt::DisplayRole);
    }
}

void BasicSettings::on_pbShifterY_clicked()
{
    QModelIndex index;
    index = model->index(0, 2);
    quint32 y = model->data(index).toULongLong();
    quint32 delta = ui->sbStep->value();

    for(int i=1;i<model->rowCount(); i++)
    {
        y += delta;
        index = model->index(i, 2);
        model->setData(index, y, Qt::DisplayRole);
    }
}

void BasicSettings::closeEvent(QCloseEvent *event)
{
    QMessageBox msgBox;
    msgBox.setText("The document has been modified.");
    msgBox.setInformativeText("Do you want to save your changes?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();

    switch (ret) {
      case QMessageBox::Save:
          saveFile();
          break;
      case QMessageBox::Discard:
          return;
          break;
      case QMessageBox::Cancel:
          event->ignore();
          break;
      default:
          // should never be reached
          return;
          break;
    }
}

void BasicSettings::saveFile()
{
    QFileDialog *dialog = new QFileDialog();
    dialog->setDefaultSuffix("qgn");
    QString name = QString("qsybasic.qgn");
    QString fileName = dialog->getSaveFileName(this, tr("Save File"),
                        name,
                        tr("Data(*.qgn)"));
    if (fileName.isEmpty())
            return;

    delete dialog;

    QFile file(fileName);
    if (!file.open(QFile::WriteOnly))
    {
        QMessageBox::warning(this, tr("Application"),
        tr("Cannot write file %1:\n%2.")
        .arg(fileName)
        .arg(file.errorString()));
        return;
    }

    QApplication::setOverrideCursor(Qt::WaitCursor);

    QString jobname = QString("QingSKY_BASIC_0");

    QList<quint32> fileData;

    fileData.append(0xFFFFFFFF);
    fileData.append(0xFFFFFFFF);
    fileData.append(0xFFFFFFFF);
    fileData.append(0xFFFFFFFF);

    fileData.append(ui->sb1->value());
    fileData.append(ui->sb2->value());
    fileData.append(ui->sb3->value());

    for(int i = 0; i < 13; i++)
    {
        fileData.append(0xFFFFFFFF);
    }

    fileData.append(ui->sb4->value());
    fileData.append(ui->sb5->value());
    fileData.append(ui->sb6->value());

    fileData.append(0xFFFFFFFF);
    fileData.append(0xFFFFFFFF);
    fileData.append(0xFFFFFFFF);
    fileData.append(0xFFFFFFFF);
    fileData.append(0xFFFFFFFF);

    fileData.append(ui->sb7->value());
    fileData.append(ui->sb8->value());
    fileData.append(ui->sb9->value());
    fileData.append(ui->sb10->value());

    for(int i = 0; i < 11; i++)
    {
        fileData.append(0xFFFFFFFF);
    }

    QModelIndex index;

    for(int i = 0; i < model->rowCount(); i++)
    {
        fileData.append(0xFFFFFFFF);
        fileData.append(0xFFFFFFFF);
        fileData.append(0xFFFFFFFF);
        fileData.append(0xFFFFFFFF);
        fileData.append(0xFFFFFFFF);
        for(int j = 0; j < 7; j++)
        {
            index = model->index(i, j);
            fileData.append(model->data(index).toULongLong());
        }
    }

    QByteArray ba;
    ba.append(jobname);
    ba.append(QChar(0));

    for(int i=0;i<fileData.length();i++)
    {
        //little endian
        ba.append(QChar(fileData.at(i) & 0x000000FF));
        ba.append(QChar((fileData.at(i) & 0x0000FF00) >> 8));
        ba.append(QChar((fileData.at(i) & 0x00FF0000) >> 16));
        ba.append(QChar((fileData.at(i) & 0xFF000000) >> 24));
    }

    file.write(ba);

    QApplication::restoreOverrideCursor();
    file.close();

    return;
}
