#include "groupsmodel.h"
#include <QDebug>
#include <QColor>
#include "settings.h"

GroupsModel::GroupsModel(QObject *parent) :
    QAbstractTableModel(parent)
{
}

int GroupsModel::rowCount(const QModelIndex &parent) const
{
    return groups.count();
}

bool GroupsModel::setData( const QModelIndex & index, const QVariant & value, int role)
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

void GroupsModel::setGroups(QList<GROUP*> _groups)
{
    groups = _groups;
}

QVariant GroupsModel::data ( const QModelIndex & index, int role ) const
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

bool GroupsModel::insertRows ( int row, int count, const QModelIndex & parent)
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

bool GroupsModel::removeRows(int row, int count, const QModelIndex & parent)
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

void GroupsModel::clear(const QModelIndex & parent)
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

void GroupsModel::appendRow(int tape, QString name)
{
    GROUP *group = new GROUP;
    if(!groups.isEmpty())
        group->id = groups.last()->id + 1;
    else
        group->id = 0;
    group->name = name;
    group->tape = tape;
    group->visible = true;

    beginInsertRows(QModelIndex(), groups.count(), groups.count());
      groups.append(group);
    endInsertRows();
}

const QList<GROUP *> GroupsModel::getList()
{
    return groups;
}

 QVariant GroupsModel::headerData(int section, Qt::Orientation orientation, int role) const
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

 int GroupsModel::getTapeByID(int id)
 {
     return groups.at(id)->tape;
 }

Qt::ItemFlags GroupsModel::flags(const QModelIndex &index) const
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

FilterProxyModel::FilterProxyModel(QObject *parent)
    : QSortFilterProxyModel(parent)
{
}

bool FilterProxyModel::filterAcceptsRow(int sourceRow,
        const QModelIndex &sourceParent) const
{
    QModelIndex index = sourceModel()->index(sourceRow, 3, sourceParent);

    int x = sourceModel()->data(index, Qt::CheckStateRole).toInt();
    switch(x)
    {
        case Qt::Checked:
        {
            return true;
        }
        case Qt::PartiallyChecked:
        {
            return true;
        }
        case Qt::Unchecked:
        {
            return false;
        }
        default: return false;
    }
}

QVariant FilterProxyModel::data( const QModelIndex & index, int role ) const
{
    if (!index.isValid())
      return QVariant();
    Settings *settings = Settings::Instance();

    QModelIndex sourceIndex = mapToSource(index);

    QModelIndex idx = sourceModel()->index(sourceIndex.row(), 2, QModelIndex());

    QString name = sourceModel()->data(idx, Qt::DisplayRole).toString().toLower();

    if (role == Qt::ForegroundRole)
    {
        if(settings->getGroupsRejectList()->contains(name, Qt::CaseInsensitive))
        {
            return QVariant(QColor(Qt::darkRed));
        }

        if(settings->getGroupsACLModel()->getNames()->contains(name, Qt::CaseInsensitive))
        {
            return QVariant(QColor(Qt::darkGreen));
        }
        return QVariant(QColor(Qt::red));
    }

    if(role == Qt::DecorationRole)
    {
        idx = sourceModel()->index(sourceIndex.row(), 0, QModelIndex());
        int guid = sourceModel()->data(idx, Qt::DisplayRole).toInt();
        int tape = static_cast<GroupsModel*>(sourceModel())->getTapeByID(guid);
        return settings->getColors().at(tape);
    }

    return sourceModel()->data(sourceIndex, role);
}
