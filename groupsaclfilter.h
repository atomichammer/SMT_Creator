#ifndef GROUPSACLFILTER_H
#define GROUPSACLFILTER_H

#include <QSortFilterProxyModel>
#include "groupsmodel.h"
#include "groupsaclmodel.h"

class GroupsACLFilter : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    GroupsACLFilter(QStringList *model, GroupsACLModel *ACLModel);

    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const;
    bool filterAcceptsColumn(int source_column, const QModelIndex &source_parent) const;

    QVariant data(const QModelIndex &index, int role) const;
private:
    QStringList *groupsModel;
    GroupsACLModel *groupsACLModel;

};

#endif // GROUPSACLFILTER_H
