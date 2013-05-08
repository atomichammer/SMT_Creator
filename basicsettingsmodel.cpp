#include "basicsettingsmodel.h"

BasicSettingsModel::BasicSettingsModel(QObject *parent) :
    QAbstractTableModel(parent)
{
}

int BasicSettingsModel::rowCount(const QModelIndex &parent) const
{
    return list.count();
}

bool BasicSettingsModel::setData( const QModelIndex & index, const QVariant & value, int role)
{
    if (index.isValid())
    {
        switch(index.column())
        {
            case 0:
                {
                    list[index.row()].number = value.toInt();
                    emit dataChanged(index, index);
                    emit changed();
                    return true;
                }
            case 1:
                {
                    list[index.row()].shifterX = value.toULongLong();
                    emit dataChanged(index, index);
                    emit changed();
                    return true;
                }
            case 2:
                {
                    list[index.row()].shifterY = value.toULongLong();
                    emit dataChanged(index, index);
                    emit changed();
                    return true;
                }
            case 3:
                {
                    list[index.row()].pickerX = value.toULongLong();
                    emit dataChanged(index, index);
                    emit changed();
                    return true;
                }
            case 4:
                {
                    list[index.row()].pickerY = value.toULongLong();
                    emit dataChanged(index, index);
                    emit changed();
                    return true;
                }
            case 5:
                {
                    list[index.row()].shiftLength = value.toULongLong();
                    emit dataChanged(index, index);
                    emit changed();
                    return true;
                }
            case 6:
                {
                    list[index.row()].someValue = value.toULongLong();
                    emit dataChanged(index, index);
                    emit changed();
                    return true;
                }
            default: return false;
        }
    }
    return false;
}

QVariant BasicSettingsModel::data ( const QModelIndex & index, int role ) const
{
    if (index.isValid())
    {
        switch(index.column())
        {
            case 0:
                {
                    if(role == Qt::DisplayRole)
                        return list[index.row()].number;
                    break;
                }
            case 1:
                {
                    if(role == Qt::DisplayRole || role == Qt::EditRole)
                        return list[index.row()].shifterX;
                    break;
                }
            case 2:
                {
                    if(role == Qt::DisplayRole || role == Qt::EditRole)
                        return list[index.row()].shifterY;
                    break;
                }
            case 3:
                {
                    if(role == Qt::DisplayRole || role == Qt::EditRole)
                        return list[index.row()].pickerX;
                    break;
                }
            case 4:
                {
                    if(role == Qt::DisplayRole || role == Qt::EditRole)
                        return list[index.row()].pickerY;
                    break;
                }
            case 5:
                {
                    if(role == Qt::DisplayRole || role == Qt::EditRole)
                        return list[index.row()].shiftLength;
                    break;
                }
            case 6:
                {
                    if(role == Qt::DisplayRole || role == Qt::EditRole)
                        return list[index.row()].someValue;
                    break;
                }

            default: return QVariant();
        }
    }
    return QVariant();
}

bool BasicSettingsModel::insertRows ( int row, int count, const QModelIndex & parent)
{
    CELL cell;
    cell.number = 0;
    cell.pickerX = 0;
    cell.pickerY = 0;
    cell.shifterX = 0;
    cell.shifterY = 0;
    cell.shiftLength = 0;
    cell.someValue = 0;

    beginInsertRows(QModelIndex(), row, row + count - 1);

    for (int i = 0; i < count; ++i)
    {
        list.insert(row, cell);
    }

    endInsertRows();
    //qDebug() << ("Row inserted");
    emit dataChanged(parent, parent);
    emit changed();
    return true;
}

bool BasicSettingsModel::removeRows(int row, int count, const QModelIndex & parent)
{
    Q_UNUSED(parent);
    if(row > list.count())
        return false;
    if(row+count > list.count())
    {
        count = list.count() - row;
    }
    beginRemoveRows(QModelIndex(), row, row + count - 1);
    for(int i=0;i<count;++i)
    {
        list.removeAt(row);
    }
    endRemoveRows();
    emit dataChanged(parent, parent);
    return true;
}

void BasicSettingsModel::clear(const QModelIndex & parent)
{
    Q_UNUSED(parent);

    if(list.count() > 0)
    {
        beginRemoveRows(QModelIndex(), 0, list.count() - 1);
        list.clear();
        endRemoveRows();
        emit dataChanged(parent, parent);
    }
}

void BasicSettingsModel::appendRow()
{
    insertRows(list.count(), 1, QModelIndex());
}

QList<CELL> BasicSettingsModel::getList()
{
    return list;
}

 QVariant BasicSettingsModel::headerData(int section, Qt::Orientation orientation, int role) const
 {
     if (role != Qt::DisplayRole)
         return QVariant();

     if (orientation == Qt::Horizontal) {
         switch (section) {
             case 0:
                 return tr("Num");

             case 1:
                 return tr("ShifterX");

             case 2:
                 return tr("ShifterY");

             case 3:
                 return tr("PickerX");

             case 4:
                 return tr("PickerY");

             case 5:
                 return tr("ShiftLength");

             case 6:
                 return tr("SomeValue");

             default:
                 return QVariant();
         }
     }
     return QVariant();
 }

Qt::ItemFlags BasicSettingsModel::flags(const QModelIndex &index) const
 {
     Qt::ItemFlags defaultFlags = QAbstractTableModel::flags(index);

     if (index.isValid())
     {
         switch(index.column())
         {
             case 0:
                 return defaultFlags;

             default:
                 return defaultFlags  | Qt::ItemIsEditable;
         }
     }
     return defaultFlags;
 }
