#ifndef GROUPSACLMODEL_H
#define GROUPSACLMODEL_H

#include <QAbstractTableModel>
#include <QDebug>
#include <QStringList>

typedef struct{
    QString name;
    int tape;
}ACL;

class GroupsACLModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit GroupsACLModel(QObject *parent = 0);
    void setGroupsACLList(const QList<ACL> &list);
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role) const;

    
    QList<ACL> *getGroupsACLList();
    void resetModel() { reset(); }
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    QStringList *getNames();
    bool removeRow(int row, const QModelIndex &parent);
signals:
    
public slots:

private:
    QList<ACL> groupsACL;
    QStringList names;
    
};

#endif // GROUPSACLMODEL_H
