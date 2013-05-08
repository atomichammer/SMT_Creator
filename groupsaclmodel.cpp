#include "groupsaclmodel.h"
#include <QColor>


GroupsACLModel::GroupsACLModel(QObject *parent) :
    QAbstractTableModel(parent)
{

}

void GroupsACLModel::setGroupsACLList(const QList<ACL> &list)
{
    groupsACL = list;
}

QList<ACL> *GroupsACLModel::getGroupsACLList()
{
    return &groupsACL;
}

QStringList *GroupsACLModel::getNames()
{
    names.clear();
    for (int i = 0; i < groupsACL.count(); ++i)
    {
        names.append(groupsACL.at(i).name);
    }
    return &names;
}

int GroupsACLModel::rowCount(const QModelIndex &parent) const
{
    return groupsACL.count();
}

int GroupsACLModel::columnCount(const QModelIndex &parent) const
{
    return 2;
}

bool GroupsACLModel::setData( const QModelIndex & index, const QVariant & value, int role)
{
    if (index.isValid())
    {
        switch(index.column())
        {
            case 0:
                {
                    groupsACL[index.row()].name = value.toString();
                    emit dataChanged(index, index);
                    //emit changed(index);
                    return true;
                }
            case 1:
                {
                    groupsACL[index.row()].tape = value.toInt();
                    emit dataChanged(index, index);
                    //emit changed(index);
                    return true;
                }
            default: return false;
        }
    }
    return false;
}

bool GroupsACLModel::removeRow(int row, const QModelIndex &parent)
{
    if(row >= groupsACL.count())
        return false;

    beginRemoveRows(QModelIndex(), row, row);

        groupsACL.removeAt(row);

    endRemoveRows();
    emit dataChanged(parent, parent);
    return true;
}

QVariant GroupsACLModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    switch(index.column())
    {
    case 0:
    {
        if(role == Qt::DisplayRole)
        {
            return groupsACL.at(index.row()).name;
            break;
        }
        if(role == Qt::ForegroundRole)
        {
            return QVariant(QColor(Qt::darkGreen));
            break;
        }
        break;
    }
    case 1:
    {
        if(role == Qt::DisplayRole || role == Qt::EditRole)
        {
            return groupsACL.at(index.row()).tape;
        }
        break;
    }
    default: return QVariant();
    }
    return QVariant();
}

QVariant GroupsACLModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section) {
            case 0:
                return tr("Name");
                break;

            case 1:
                return tr("Tape");
                break;

            default:
                return QVariant();
        }
    }
    return QVariant();
}

Qt::ItemFlags GroupsACLModel::flags(const QModelIndex &index) const
 {
     Qt::ItemFlags defaultFlags = QAbstractTableModel::flags(index);

     if (index.isValid())
     {
         switch(index.column())
         {
             case 1:
                 return defaultFlags | Qt::ItemIsEditable;

             default:
                 return defaultFlags;
         }
     }
     return defaultFlags;
 }
