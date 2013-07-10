#include "elements.h"
#include <QFile>
#include <QDebug>
#include <QDataStream>
#include <QMessageBox>
#include <QGenericMatrix>
#include "myelem.h"
#include "csvreader.h"
#include "csvimport.h"
#include "qmath.h"


Elements::Elements(QObject *parent) :
    QObject(parent)
{
    settings = Settings::Instance();
    footprints = new QStringList;
    groupsModel = new GroupsModel();
    connect(groupsModel, SIGNAL(changed(QModelIndex)), this, SLOT(hideGroupElements(QModelIndex)));
    divisor = 1;
}

bool Elements::loadBinaryFile(QString &fileName)
{
    QFile file(fileName);


    if(!file.open(QIODevice::ReadOnly))
    {

    } else {

        QList<quint32> dataList;
        QByteArray str;
        unsigned char c;
        quint32 q;
        QDataStream s(&file);
        s.setByteOrder(QDataStream::LittleEndian);

        //kinda magic number
        for(int i=0;i<16; i++)
        {
            s >> c;
            str.append(c);
        }
        str.chop(2);
        if(str != "QingSKY_SMTRUN")
        {
            //Incorrect file format;
            return false;
        }

        //file is correct
        //reading dwords
        while(true)
        {
            s >> q;
            dataList.append(q);
            if (s.atEnd())
                break;
        }
        file.close();

        ELEMENT elem;

        int k = 0;

        for(int i = 0; i<dataList.length();i++)
        {
            if(dataList.at(i) == 0xbbbbbb11){
                i++;
                elem.tape = dataList.at(i++);
                elem.designator = QString::number(elem.tape, 10) + "_" + QString::number(chips.count(), 10);

                //grouping elements by footprint
                if(footprints->contains("Group_" + QString::number(elem.tape+1, 10)))
                {
                    elem.group_id = footprints->indexOf("Group_" + QString::number(elem.tape+1, 10));
                } else
                {
                    GROUP *footprint = new GROUP;
                    elem.group_id = k;
                    footprint->id = k;
                    footprint->tape = elem.tape+1;
                    footprint->name = "Group_" + QString::number(elem.tape+1, 10);
                    footprint->visible = true;
                    groups.append(footprint);
                    footprints->append("Group_" + QString::number(elem.tape+1, 10));
                    k++;
                }

                unsigned int coord = dataList.at(i++);
                elem.coord_x = coord;
                coord = dataList.at(i++);
                elem.coord_y = coord;
                elem.angle = dataList.at(i++);
                if(elem.angle > 180) elem.angle -=360;
                if(elem.angle < -180) elem.angle +=360;

                addChip(elem.designator, elem.coord_x, elem.coord_y, elem.angle, elem.group_id);

            }
        }
    }
    groupsModel->setGroups(groups);
    return true;
}

void Elements::updateColors()
{
    Settings *settings = Settings::Instance();
    for(int i = 0; i < chips.count(); i++)
    {
        int guid = chips[i]->getGroupID();
        int tape = groupsModel->getTapeByID(guid);
        Q_ASSERT(tape < 25);
        chips[i]->setColor(settings->getColors().at(tape));
    }
}

void Elements::fillGroups()
{
    for(int i = 0; i < footprints->count(); i++)
    {
        GROUP *footprint = new GROUP;
        footprint->id = i;
        footprint->tape = i + 1;
        footprint->name = footprints->at(i);
        footprint->visible = true;
        groups.append(footprint);
    }
    groupsModel->setGroups(groups);
}

void Elements::findMatchGroups()
{
    //GROUP *group;
    QModelIndex index;
    QString name;
    QList<ACL> basicGroups = settings->getGroupsACL();

    for (int i = 0; i < groupsModel->rowCount(QModelIndex()); ++i)
    {
        index = groupsModel->index(i, 2, QModelIndex());
        name = groupsModel->data(index, Qt::DisplayRole).toString();
        for (int j = 0; j < basicGroups.count(); ++j)
        {
            if(name == basicGroups.at(j).name)
            {
                int tape = basicGroups.at(j).tape;
                index = groupsModel->index(i, 1, QModelIndex());
                groupsModel->setData(index, tape, Qt::DisplayRole);
            }
        }
    }
}

void Elements::hideGroupElements(QModelIndex index)
{
    QModelIndex idx = groupsModel->index(index.row(), 0, QModelIndex());
    int guid = groupsModel->data(idx, Qt::DisplayRole).toInt();
    idx = groupsModel->index(index.row(), 3, QModelIndex());
    bool visible;
    int x = groupsModel->data(idx, Qt::CheckStateRole).toInt();

    switch(x)
    {
        case Qt::Checked:
        {
            visible = true;
            break;
        }
        case Qt::PartiallyChecked:
        {
            visible = true;
            break;
        }
        case Qt::Unchecked:
        {
            visible = false;
            break;
        }
        default: visible = false;
    }

    for(int i = 0; i < chips.count(); i++)
    {
        Chip *chip = chips[i];
        if(chip->getGroupID() == guid)
        {
            if(chip->isVisible() && !visible)
            {
                chip->setVisible(visible);
                visibleChips.removeOne(chip);
            }
            if(!chip->isVisible() && visible)
            {
                chip->setVisible(visible);
                visibleChips.append(chip);
            }
        }
    }

}

float Elements::prepareNum(QString s)
{
    s.chop(2);
    float f = s.toFloat();
    if(f < 0) f = f*(-1);
    return f;
}

void Elements::loadCSVFile(QString &filename)
{

    if (!filename.isEmpty())
    {
        CsvReader *csv = new CsvReader(0,filename); //
        if (csv->Open()){
            str = csv->CSVRead();

            CSVImport *dialog = new CSVImport();
            dialog->setData(str);

            if(dialog->exec() == QDialog::Accepted)
            {
                list = dialog->getList();

                delete dialog;

                loadCSVElements();
                //num = calcNumElements();
            }
        }
    }
}

void Elements::loadCSVElements()
{
    ELEMENT elem;
    QString fp;

    footprints->clear();

    if(str.length() > 0){
        for (int i=1;i<str.length();i++)
        {
            //if less than we expect advance to next element
            if(str.at(i).length() < 5) continue;
            //if contains empty fields advance to next element
            if(str.at(i).at(list.at(0)) == "" ||
                str.at(i).at(list.at(1)) == "" ||
                str.at(i).at(list.at(2)) == "" ||
                str.at(i).at(list.at(3)) == "" ||
                str.at(i).at(list.at(4)) == "")  continue;

            //grouping elements by footprint
            fp = str.at(i).at(list.at(4));
            if(footprints->contains(fp, Qt::CaseInsensitive))
            {
                int guid = footprints->indexOf(QRegExp(fp ,Qt::CaseInsensitive, QRegExp::FixedString));
                Q_ASSERT(guid >= 0);
                elem.group_id = guid;
            } else{
                GROUP *footprint = new GROUP;
                elem.group_id = footprints->length();
                footprint->id = elem.group_id;
                elem.tape = elem.group_id + 1; //tape shouldn't be 0;
                footprint->tape = elem.tape;
                footprint->name = fp;
                footprint->visible = true;
                groups.append(footprint);
                footprints->append(fp);
            }

            elem.designator = str.at(i).at(list.at(0));

            unsigned int coord = prepareNum(str.at(i).at(list.at(1))) * settings->getStepsPerMM();
//            if(coord > settings->getZeroX()) continue;
//            elem.coord_x = settings->getZeroX() - coord;

            elem.coord_x = coord;
            coord = settings->getZeroY() + prepareNum(str.at(i).at(list.at(2))) * settings->getStepsPerMM();
//            if(coord > settings->getMaxY()) continue;
            elem.coord_y = coord;
            elem.angle = (str.at(i).at(list.at(3))).toDouble() - 90;
            if(elem.angle > 180) elem.angle -=360;
            if(elem.angle < -180) elem.angle +=360;

            addChip(elem.designator, elem.coord_x, elem.coord_y, elem.angle, elem.group_id);
        }
    }
    groupsModel->setGroups(groups);
}

void Elements::addChip(QString designator, quint32 x, quint32 y, int angle, int groupID)
{
    Chip *chip = new Chip(x, y, designator, angle);
    chip->setGroupID(groupID);
    chip->setCoordX(x);
    chip->setCoordY(y);
    chips.append(chip);
}

QList<Chip *> Elements::getVisibleChips()
{
    visibleChips.clear();
    for(int i = 0; i < chips.count(); i++)
    {
        if(chips.at(i)->isVisible())
        {
            visibleChips.append(chips[i]);
        }
    }
    return visibleChips;
}

QList<Chip *> Elements::getSelectedChips()
{
    QList<Chip*> list;
    for(int i = 0; i < chips.count(); i++)
    {
        if(chips.at(i)->isVisible() && chips.at(i)->isSelected())
        {
            list.append(chips[i]);
        }
    }
    return list;
}

void Elements::removeChipFromVisible(Chip *chip)
{
    visibleChips.removeOne(chip);

}

void Elements::addChip(Chip *chip)
{
    chips.append(chip);
}

void Elements::moveMultiply(qint32 deltaX, qint32 deltaY)
{
    for(int i=0; i<chips.length(); i++)
    {
        chips[i]->setCoordX(chips[i]->getCoordX() - deltaX);
        chips[i]->setCoordY(chips[i]->getCoordY() - deltaY);
    }

    //update settings
//    Settings *settings = Settings::Instance();
//    qDebug() << "ZeroX:" << deltaX;
//    qDebug() << "Was: " << settings->getZeroX();
//    settings->setZeroX(settings->getZeroX() + deltaX);
//    qDebug() << "Now: " << settings->getZeroX();

//    qDebug() << "ZeroY:" << deltaY;
//    qDebug() << "Was: " << settings->getZeroY();
//    settings->setZeroY(settings->getZeroY() + deltaY);
//    qDebug() << "Now: " << settings->getZeroY();
//    delete settings;
}

void Elements::moveSingle(quint32 newValX, quint32 newValY, int i)
{
    chips[i]->setCoordX(newValX);
    chips[i]->setCoordY(newValY);
}

void Elements::makeRotate(double rx1, double ry1, double rx2, double ry2, double ix1, double iy1, double ix2, double iy2)
{
    //Settings *settings = Settings::Instance();
    const float Pi = 3.14159;

    if(ix1 > ix2)
    {
        int c = ix2; ix2 = ix1; ix1 = c;
        c = iy2; iy2 = iy1; iy1 = c;
    }


    double a1 = atan2( ix2 - ix1, iy2 - iy1 );
    double a2 = atan2( rx2 - rx1, ry2 - ry1 );
    double a = a2 - a1;
    //double a = 0.0;



    QGenericMatrix<3,3,double> T;
    QGenericMatrix<3,3,double> S;
    QGenericMatrix<3,3,double> R;

    T.fill(0);

    T(0,0) = 1;
    T(0,2) = -ix1;

    T(1,1) = 1;
    T(1,2) = -iy1;

    T(2,2) = 1;

    S.fill(0);

    S(0,0) = 1;
    S(0,2) = rx1;

    S(1,1) = 1;
    S(1,2) = ry1;

    S(2,2) = 1;

    R.fill(0);

    R(0,0) = cos(a);
    R(0,1) = sin(a);

    R(1,0) = -sin(a);
    R(1,1) = cos(a);

    R(2,2) = 1;

    QGenericMatrix<3,3,double> M;

    M = S*R*T;

    QGenericMatrix<1,3,double> coords;
    QGenericMatrix<1,3,double> result;
    coords.fill(0);
    coords(2,0) = 1;
    int angle = a*180/Pi;
    signed int sign = 1;
    if(angle<0) sign = -1; angle = abs(angle);

    Chip *chip;
    for(int i=0;i<chips.count();i++)
    {
        chip = chips[i];
        coords(0,0) = chip->getCoordX();
        coords(1,0) = chip->getCoordY();

        result.fill(0);
        result = M*coords;

        //qDebug() << result;

        chip->setCoordX(result(0,0));
        chip->setCoordY(result(1,0));

        chip->setRotation(chip->rotation() + angle*sign);
        if(chip->rotation() > 180) chip->setRotation(chip->rotation() - 360);
        if(chip->rotation() < -180) chip->setRotation(chip->rotation() + 360);
    }

}

void Elements::testRotate(double angle)
{
    Settings *settings = Settings::Instance();
    const float Pi = 3.14159;
    double a = angle*Pi/180;
    Chip *chip;
    qint64 _maxX = 0;
    qint64 _minX = settings->getMaxX();
    qint64 _maxY = 0;
    qint64 _minY = settings->getMaxY();


    //determining bounding rect
    for(int i = 0; i < chips.count(); i++)
    {
        chip = chips[i];
        if(chip->getCoordX() > _maxX) _maxX = chip->getCoordX();
        if(chip->getCoordX() < _minX) _minX = chip->getCoordX();
        if(chip->getCoordY() > _maxY) _maxY = chip->getCoordY();
        if(chip->getCoordY() < _minY) _minY = chip->getCoordY();
    }

    int deltaY = (_maxY - _minY) / 2 + _minY;
    int deltaX = (_maxX - _minX) / 2 + _minX;



    QGenericMatrix<3,3,double> T1;
    QGenericMatrix<3,3,double> T2;
    QGenericMatrix<3,3,double> R;

//  Move Matrix
    T1.fill(0);

    T1(0,0) = 1;
    T1(0,2) = -deltaX;//-56100;

    T1(1,1) = 1;
    T1(1,2) = -deltaY;//-8542;

    T1(2,2) = 1;

    //  Move Matrix
    T2.fill(0);

    T2(0,0) = 1;
    T2(0,2) = deltaX;//56100;

    T2(1,1) = 1;
    T2(1,2) = deltaY;//8542;

    T2(2,2) = 1;

//  Rotate matrix
    R.fill(0);

    R(0,0) = cos(a);
    R(0,1) = sin(a);

    R(1,0) = -sin(a);
    R(1,1) = cos(a);

    R(2,2) = 1;

    QGenericMatrix<1,3,double> coords;
    QGenericMatrix<1,3,double> result;
    coords.fill(0);
    coords(2,0) = 1;

    signed int sign = 1;
    if(angle<0)
    {
        sign = -1;
        angle = abs(angle);
    }

    for(int i=0;i<chips.count();i++)
    {
        chip = chips[i];
        coords(0,0) = chip->getCoordX();
        coords(1,0) = chip->getCoordY();

        result.fill(0);
        result = T1*coords;
        result = R*result;
        result = T2*result;

        chip->setCoordX(result(0,0));
        chip->setCoordY(result(1,0));

        //qDebug() << chip->getCoordX() << " : " << chip->getCoordY();

        chip->setRotation(chip->rotation() + angle*sign);
        if(chip->rotation() > 180) chip->setRotation(chip->rotation() - 360);
        if(chip->rotation() < -180) chip->setRotation(chip->rotation() + 360);
    }
}

void Elements::rotateSelected(int angle)
{
    QList<Chip *> selectedChips = getSelectedChips();
    Chip *chip;
    qDebug() << "Rotate: " << selectedChips.count() << " Angle" << angle;
    for(int i=0;i<selectedChips.count();i++)
    {
        chip = selectedChips[i];
        chip->setRotation(angle);
        if(chip->rotation() > 180) chip->setRotation(chip->rotation() - 360);
        if(chip->rotation() < -180) chip->setRotation(chip->rotation() + 360);
    }
}

void Elements::flipH()
{
    Chip *chip;
    //Settings *settings = Settings::Instance();
    quint32 _maxX = 0;
    quint32 _minX = 75000;

    //determining bounding rect
    for(int i = 0; i < chips.count(); i++)
    {
        chip = chips[i];
        if(chip->getCoordX() > _maxX) _maxX = chip->getCoordX();
        if(chip->getCoordX() < _minX) _minX = chip->getCoordX();
    }

    quint32 deltaX = (_maxX - _minX);

    for(int i = 0; i < chips.count(); i++)
    {
        chip = chips[i];
        chip->setCoordX(_minX + deltaX - (chip->getCoordX() - _minX));
    }
}

void Elements::flipV()
{
    Chip *chip;
    //Settings *settings = Settings::Instance();
    quint32 _maxY = 0;
    quint32 _minY = 75000;

    //determining bounding rect
    for(int i = 0; i < chips.count(); i++)
    {
        chip = chips[i];
        if(chip->getCoordY() > _maxY) _maxY = chip->getCoordY();
        if(chip->getCoordY() < _minY) _minY = chip->getCoordY();
    }

    quint32 deltaY = (_maxY - _minY);

    for(int i = 0; i < chips.count(); i++)
    {
        chip = chips[i];
        chip->setCoordY(_minY + deltaY - (chip->getCoordY() - _minY));
    }
}

void Elements::sortByX()
{
    Chip *chip;
    int size = visibleChips.count();

    long j, k = size-1;
    long lb = 1, ub = size-1; // границы неотсортированной части массива

    do
    {
        // проход снизу вверх
        for( j=ub; j>0; j-- )
        {
            if ( visibleChips[j-1]->getCoordX() > visibleChips[j]->getCoordX() )
            {
                chip = visibleChips[j-1];
                visibleChips[j-1] = visibleChips[j];
                visibleChips[j] = chip;
                k = j;
            }
        }

        lb = k+1;

        // проход сверху вниз
        for (j=1; j<=ub; j++)
        {
            if ( visibleChips[j-1]->getCoordX() > visibleChips[j]->getCoordX() )
            {
                chip = visibleChips[j-1];
                visibleChips[j-1] = visibleChips[j];
                visibleChips[j] = chip;
                k = j;
            }
        }

        ub = k - 1;
    } while ( lb < ub );

}

void Elements::sortByY()
{
    Chip *chip;
    //getVisibleChips();

    int size = visibleChips.count();

    long j, k = size-1;
    long lb = 1, ub = size-1; // границы неотсортированной части массива

    do
    {
        // проход снизу вверх
        for( j=ub; j>0; j-- )
        {
            if ( visibleChips[j-1]->getCoordY() > visibleChips[j]->getCoordY() )
            {
                chip = visibleChips[j-1];
                visibleChips[j-1] = visibleChips[j];
                visibleChips[j] = chip;
                k = j;
            }
        }

        lb = k+1;

        // проход сверху вниз
        for (j=1; j<=ub; j++)
        {
            if ( visibleChips[j-1]->getCoordY() > visibleChips[j]->getCoordY() )
            {
                chip = visibleChips[j-1];
                visibleChips[j-1] = visibleChips[j];
                visibleChips[j] = chip;
                k = j;
            }
        }

        ub = k - 1;
    } while ( lb < ub );
}

void Elements::sortByTape()
{
    /*
    Chip *chip;
    //getVisibleChips();

    int size = visibleChips.count();

    long j, k = size-1;
    long lb = 1, ub = size-1; // границы неотсортированной части массива

    do
    {
        // проход снизу вверх
        for( j=ub; j>0; j-- )
        {
            if ( visibleChips[j-1]->getTape() > visibleChips[j]->getTape() )
            {
                chip = visibleChips[j-1];
                visibleChips[j-1] = visibleChips[j];
                visibleChips[j] = chip;
                k = j;
            }
        }

        lb = k+1;

        // проход сверху вниз
        for (j=1; j<=ub; j++)
        {
            if ( visibleChips[j-1]->getTape() > visibleChips[j]->getTape() )
            {
                chip = visibleChips[j-1];
                visibleChips[j-1] = visibleChips[j];
                visibleChips[j] = chip;
                k = j;
            }
        }

        ub = k - 1;
    } while ( lb < ub );
    */
}


