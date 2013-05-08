#ifndef BASICSETTINGSMODEL_H
#define BASICSETTINGSMODEL_H

#include <QAbstractTableModel>

typedef struct
{
        uchar   number;
        quint32 pickerX;
        quint32 pickerY;
        quint32 shifterX;
        quint32 shifterY;
        quint32 shiftLength;
        quint32 someValue;
} CELL;

class BasicSettingsModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit BasicSettingsModel(QObject *parent = 0);
    
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount ( const QModelIndex & parent = QModelIndex() ) const { return 7; }
    bool setData ( const QModelIndex & index, const QVariant & value, int role = Qt::EditRole );
    QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const;
    bool insertRows ( int row, int count, const QModelIndex & parent = QModelIndex() );
    bool removeRows ( int row, int count, const QModelIndex & parent = QModelIndex() );
    void appendRow();
    void clear(const QModelIndex & parent);
    QList<CELL> getList();
    void setList(QList<CELL> l) { list = l; reset(); }
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
signals:
    void changed();
 private:
     QList <CELL>list;
     Qt::ItemFlags flags(const QModelIndex &index) const;
    
};

#endif // BASICSETTINGSMODEL_H
