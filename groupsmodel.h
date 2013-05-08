#ifndef GROUPSMODEL_H
#define GROUPSMODEL_H

#include <QAbstractTableModel>
#include <QSortFilterProxyModel>

typedef struct
{
    int id;
    int tape;
    QString name;
    bool visible;
} GROUP;

class FilterProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    FilterProxyModel(QObject *parent = 0);


    QVariant data(const QModelIndex &index, int role) const;
protected:
    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const;
//    bool filterAcceptsColumn(int source_column, const QModelIndex &source_parent) const;

private:
};

class GroupsModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit GroupsModel(QObject *parent = 0);
    
    int rowCount(const QModelIndex &parent) const;
    int columnCount ( const QModelIndex & parent = QModelIndex() ) const { return 4; }
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    QVariant data(const QModelIndex &index, int role) const;
    bool insertRows(int row, int count, const QModelIndex &parent);
    bool removeRows(int row, int count, const QModelIndex &parent);
    void clear(const QModelIndex &parent);
    void appendRow(int tape, QString name);
    const QList<GROUP *> getList();
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    void setGroups(QList<GROUP *> _groups);
    void resetModel() { reset(); }
    int getTapeByID(int id);
signals:
    void changed(QModelIndex);
public slots:

private:
    QList<GROUP *> groups;
    
};

#endif // GROUPSMODEL_H
