#include "basicgroupsmodel.h"

basicGroupsModel::basicGroupsModel(QObject *parent) :
    QAbstractTableModel(parent)
{

}

int basicGroupsModel::rowCount(const QModelIndex &parent) const
{
    return groups.count();
}

bool basicGroupsModel::setData( const QModelIndex & index, const QVariant & value, int role)
{
    if (index.isValid())
    {
        switch(index.column())
        {
            case 0:
                {
                    groups[index.row()]->id = value.toInt();
                    emit dataChanged(index, index);
                    //emit changed(index);
                    return true;
                }
            case 1:
                {
                    groups[index.row()]->tape = value.toInt();
                    emit dataChanged(index, index);
                    //emit changed(index);
                    return true;
                }
            case 2:
                {
                    groups[index.row()]->name = value.toString();
                    emit dataChanged(index, index);
                    //emit changed(index);
                    return true;
                }
            case 3:
                {
                    groups[index.row()]->visible = value.toBool();
                    emit dataChanged(index, index);
                    emit changed(index);
                    return true;
                }
            default: return false;
        }
    }
    return false;
}

void basicGroupsModel::setGroups(QList<GROUP*> _groups)
{
    groups = _groups;
}

QVariant basicGroupsModel::data ( const QModelIndex & index, int role ) const
{
    if (index.isValid())
    {
        switch(index.column())
        {
            case 0:
                {
                    if(role == Qt::DisplayRole)
                        return groups[index.row()]->id;
                    break;
                }
            case 1:
                {
                    if(role == Qt::EditRole || role == Qt::DisplayRole)
                        return groups[index.row()]->tape;
                    break;
                }
            case 2:
                {
                    if(role == Qt::DisplayRole || role == Qt::EditRole)
                    {
                        return groups[index.row()]->name;
                    }
                    break;
                }
            case 3:
                {
                    if(role == Qt::CheckStateRole)
                        return groups[index.row()]->visible ? Qt::Checked : Qt::Unchecked;
                    break;
                }
            default: return QVariant();
        }
    }
    return QVariant();
}

bool basicGroupsModel::insertRows ( int row, int count, const QModelIndex & parent)
{
    GROUP *group = new GROUP;
    group->id = 0;
    group->name = "";
    group->tape = 0;
    group->visible = true;

    beginInsertRows(QModelIndex(), row, row + count - 1);

    for (int i = 0; i < count; ++i)
    {
        groups.insert(row, group);
    }

    endInsertRows();
    //qDebug() << ("Row inserted");
    emit dataChanged(parent, parent);
    //emit changed();
    return true;
}

bool basicGroupsModel::removeRows(int row, int count, const QModelIndex & parent)
{
    Q_UNUSED(parent);
    if(row > groups.count())
        return false;
    if(row+count > groups.count())
    {
        count = groups.count() - row;
    }
    beginRemoveRows(QModelIndex(), row, row + count - 1);
    for(int i = 0;i < count; ++i)
    {
        groups.removeAt(row);
    }
    endRemoveRows();
    emit dataChanged(parent, parent);
    return true;
}

void basicGroupsModel::clear(const QModelIndex & parent)
{
    Q_UNUSED(parent);

    if(groups.count() > 0)
    {
        beginRemoveRows(QModelIndex(), 0, groups.count() - 1);
        groups.clear();
        endRemoveRows();
        emit dataChanged(parent, parent);
    }
}

void basicGroupsModel::appendRow(int tape, QString name)
{
    GROUP *group = new GROUP;
    group->id = groups.count();
    group->name = name;
    group->tape = tape;
    group->visible = true;

    beginInsertRows(QModelIndex(), groups.count(), groups.count());
    groups.append(group);
    endInsertRows();
}

QList<GROUP*> basicGroupsModel::getList()
{
    return groups;
}

 QVariant basicGroupsModel::headerData(int section, Qt::Orientation orientation, int role) const
 {
     if (role != Qt::DisplayRole)
         return QVariant();

     if (orientation == Qt::Horizontal) {
         switch (section) {
             case 0:
                 return tr("id");
                 break;

             case 1:
                 return tr("Tape");
                 break;

             case 2:
                 return tr("Name");

             case 3:
                 return tr("Vis");

             default:
                 return QVariant();
         }
     }
     return QVariant();
 }

Qt::ItemFlags basicGroupsModel::flags(const QModelIndex &index) const
 {
     Qt::ItemFlags defaultFlags = QAbstractTableModel::flags(index);

     if (index.isValid())
     {
         switch(index.column())
         {
             case 0:
                 return defaultFlags;
             case 3:
                 return defaultFlags | Qt::ItemIsUserCheckable;

             default:
                 return defaultFlags  | Qt::ItemIsEditable;
         }
     }
     return defaultFlags;
 }
