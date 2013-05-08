#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QMap>
#include "groupsmodel.h"
#include "groupsaclmodel.h"
#include <QColor>

class Settings : public QObject
{
    Q_OBJECT
    static Settings* _self;
public:
    static Settings* Instance()
    {
        if(!_self) _self = new Settings();
        return _self;
    }
    void saveSettings();

    unsigned int getStepsPerMM() { return stepsPerMm; }
    quint32 getZeroX() { return zeroX; }
    quint32 getZeroY() { return zeroY; }
    quint32 getMaxX() { return maxX; }
    quint32 getMaxY() { return maxY; }

    QList<QColor> getColors() { return colors; }

    void setZeroX(quint32 val) { zeroX = val; }
    void setZeroY(quint32 val) { zeroY = val; }
    GroupsModel *getBasicGroups() { return basicGroups; }
    QList<ACL> getGroupsACL() { return groupsACL; }
    GroupsACLModel *getGroupsACLModel() { return groupsACLModel; }
    QStringList *getGroupsRejectList() { return &groupsRejectList; }
    void setGroupsRejectList(QStringList list) { groupsRejectList = list; }

    QStringList *getLastFiles() { return &lastFiles; }

    void loadBasicGroups();
    void saveBasicGroups();
    void loadGroupsACL();
    void saveGroupsACL();

    void loadGroupsRejectList();
    void saveGroupsRejectList();
    void loadColors();
    void saveColors();
    void loadLastFiles();
    void saveLastFiles();
protected:
    Settings();

signals:
    
public slots:

private:
    unsigned int stepsPerMm;
    quint32 zeroX;
    quint32 zeroY;
    quint32 maxX;
    quint32 maxY;
    GroupsModel *basicGroups;
    QList<ACL> groupsACL;
    GroupsACLModel *groupsACLModel;
    QStringList groupsRejectList;
    QList<QColor> colors;
    QStringList lastFiles;
};

#endif // SETTINGS_H
