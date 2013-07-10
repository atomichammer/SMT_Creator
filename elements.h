#ifndef ELEMENTS_H
#define ELEMENTS_H

#include <QObject>
#include <QStringList>
#include "myelem.h"
#include "settings.h"
#include "groupsmodel.h"
//2408800

typedef struct
{
    QString designator;
    quint32 coord_x;
    quint32 coord_y;
    qint32 angle;
    uint tape;
    uint group_id;
} ELEMENT;
    Q_DECLARE_METATYPE(ELEMENT)


class Elements : public QObject
{
    Q_OBJECT
public:
    explicit Elements(QObject *parent = 0);
    
    bool loadBinaryFile(QString &fileName);
    void loadCSVElements();
    void loadCSVFile(QString &filename);

    unsigned int itemsCount() { return chips.length(); }
    QList<Chip *> chips;
    QList<Chip *> visibleChips;

    void moveMultiply(qint32 deltaX, qint32 deltaY);
    void moveSingle(quint32 newValX, quint32 newValY, int i);
    void makeRotate(double rx1, double ry1, double rx2, double ry2, double ix1, double iy1, double ix2, double iy2);
    void flipH();
    void flipV();
    QStringList *getFootprints() { return footprints; }
    void addChip(Chip *chip);
    void addChip(QString designator, quint32 x, quint32 y, int angle, int groupID);
    QList<Chip *> getVisibleChips();
    QList<Chip *> getSelectedChips();
    void sortByX();
    void sortByY();
    void sortByTape();
    void removeChipFromVisible(Chip *chip);
    void testRotate(double angle);
    void fillGroups();
    GroupsModel *getGroupsModel() { return groupsModel; }

    void findMatchGroups();
    void rotateSelected(int angle);
    void updateColors();
signals:
    
public slots:
    void hideGroupElements(QModelIndex index);

private:
    float prepareNum(QString s);
    QList<GROUP *> groups;
    QStringList *footprints;

    Settings *settings;
    QList<QStringList> str;
    QList<int> list;
    QList<QColor> colors;
    GroupsModel *groupsModel;
    char divisor;
};

#endif // ELEMENTS_H
