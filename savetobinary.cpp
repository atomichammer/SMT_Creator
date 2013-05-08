#include "savetobinary.h"

#include <QFile>
#include <QMessageBox>
#include <QDebug>

SaveToBinary::SaveToBinary(QObject *parent) :
    QObject(parent)
{

}

bool SaveToBinary::saveToBinary(QString fileName, int num, bool selectedOnly, QList<Chip *> *chips, GroupsModel *groupsModel)
{
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly))
    {
        return false;
    }

    QString jobname = QString("QingSKY_SMTRUN%1").arg(QString::number(num, 16));

    QList<quint32> fileData;

    for(int i=0; i<5; i++)
    {
        fileData.append(0xFFFFFFFF);
    }

    fileData.append(0x00000001);
    fileData.append(0x00000001);
    fileData.append(0xFFFFFFFF);
    fileData.append(0xFFFFFFFF);
    fileData.append(0xFFFFFFFF);
    fileData.append(0xFFFFFFFF);

    fileData.append(chips->count());

    for(int i=0; i<5; i++)
    {
        fileData.append(0xFFFFFFFF);
    }

    int tape = 0;
    QModelIndex index;

    for(int i = 0;i < chips->count(); i++)
    {
        Chip *chip = chips->at(i);

        if((selectedOnly && !chip->isSelected()) || !chip->isVisible()) continue;

        fileData.append(0xFFFFFFFF);
        fileData.append(0xFFFFFFFF);
        fileData.append(0xFFFFFFFF);
        fileData.append(0xBBBBBB11);

        index = groupsModel->index(chip->getGroupID(), 1);
        tape = groupsModel->data(index, Qt::DisplayRole).toInt() - 1;

        //fileData.append(chip->getTape());
        fileData.append(tape);
        fileData.append(chip->getCoordX());
        fileData.append(chip->getCoordY());
        fileData.append(chip->rotation());
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

    file.close();

    return true;
}
