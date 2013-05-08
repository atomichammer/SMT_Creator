#include "groupsaclfilter.h"
#include <QDebug>
#include <QColor>

GroupsACLFilter::GroupsACLFilter(QStringList *model, GroupsACLModel *ACLModel)
{
    groupsACLModel = ACLModel;
    groupsModel = model;
}

bool GroupsACLFilter::filterAcceptsRow(int sourceRow,
        const QModelIndex &sourceParent) const
{
    QModelIndex index = sourceModel()->index(sourceRow, 2, sourceParent);
    QString name = sourceModel()->data(index, Qt::DisplayRole).toString().toLower();

    for (int i = 0; i < groupsACLModel->rowCount(QModelIndex()); ++i)
    {
        index = groupsACLModel->index(i, 0, QModelIndex());
        if(name == groupsACLModel->data(index, Qt::DisplayRole).toString().toLower())
        {
            return false;
        }
    }

    for (int i = 0; i < groupsModel->count(); ++i)
    {
        if(name == groupsModel->at(i).toLower())
        {
            return false;
        }
    }
    return true;
}

bool GroupsACLFilter::filterAcceptsColumn(int source_column, const QModelIndex &source_parent) const
{
    return true;
    switch(source_column)
    {
        case 0: return false;
        case 1:
        case 2:
        case 3: return true;
        default: return false;
    }
}

QVariant GroupsACLFilter::data( const QModelIndex & index, int role ) const
{
    if (!index.isValid())
      return QVariant();

    QModelIndex sourceIndex = mapToSource(index);

    if (role == Qt::ForegroundRole)
    {
        return QVariant(QColor(Qt::red));
    }

    return sourceModel()->data(sourceIndex, role);
}
