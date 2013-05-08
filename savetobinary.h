#ifndef SAVETOBINARY_H
#define SAVETOBINARY_H

#include "groupsmodel.h"
#include "elements.h"

#include <QObject>

class SaveToBinary : public QObject
{
    Q_OBJECT
public:
    explicit SaveToBinary(QObject *parent = 0);
    
    static bool saveToBinary(QString fileName, int num, bool selectedOnly, QList<Chip *> *chips, GroupsModel *groupsModel);
signals:
    
public slots:
    
};

#endif // SAVETOBINARY_H
