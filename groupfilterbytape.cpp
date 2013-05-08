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

    for (int i = 0; i < groupsModel->count(); ++i)
    {
        if(name == groupsModel->at(i).toLower())
        {
            return true;
        }
    }
    return false;
}
