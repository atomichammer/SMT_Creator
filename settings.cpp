#include "settings.h"

#include <QSettings>
#include <QDebug>
#include <QStringList>

Settings *Settings ::_self=NULL;

Settings::Settings()
{
    basicGroups = new GroupsModel();
    groupsACLModel = new GroupsACLModel();
    QSettings *iniSettings = new QSettings("main.ini", QSettings::IniFormat);

    iniSettings->beginGroup("Settings");
        stepsPerMm = iniSettings->value("stepsPerMM", 197).toInt();
        zeroX = iniSettings->value("zeroX", 61635).toInt();
        zeroY = iniSettings->value("zeroY", 1838).toInt();
        maxX = iniSettings->value("maxX", 75000).toInt();
        maxY = iniSettings->value("maxY", 72000).toInt();
    iniSettings->endGroup();
    delete iniSettings;    
    //loadBasicGroups();
    loadGroupsACL();
    loadGroupsRejectList();
    loadColors();
    loadLastFiles();
}

void Settings::loadColors()
{
    QSettings *iniSettings = new QSettings("main.ini", QSettings::IniFormat);
    int size = iniSettings->beginReadArray("Colors");
    size = 24;
    int m = 360/24;
    for(int i = 0; i < size; i++)
    {
        iniSettings->setArrayIndex(i);
        colors.append(iniSettings->value("color", QColor::fromHsl(i*m, 255, 128)).value<QColor>());
    }
    iniSettings->endArray();
    delete iniSettings;
}

void Settings::saveColors()
{
    QSettings *iniSettings = new QSettings("main.ini", QSettings::IniFormat);
    iniSettings->beginWriteArray("Colors");
    for(int i = 0; i < colors.length(); i++)
    {
        iniSettings->setArrayIndex(i);
        iniSettings->setValue("color", colors.at(i));
    }
    iniSettings->endArray();
    delete iniSettings;
}

void Settings::loadLastFiles()
{
    QSettings *iniSettings = new QSettings("main.ini", QSettings::IniFormat);
    lastFiles = iniSettings->value("LastFiles").toStringList();
    delete iniSettings;
}

void Settings::saveLastFiles()
{
    QSettings *iniSettings = new QSettings("main.ini", QSettings::IniFormat);
    iniSettings->setValue("LastFiles", lastFiles);
    delete iniSettings;
}



void Settings::loadBasicGroups()
{
    basicGroups->clear(QModelIndex());
    QSettings *iniSettings = new QSettings("main.ini", QSettings::IniFormat);
    int size = iniSettings->beginReadArray("Groups");
    size = 24;
    for (int i = 0; i < size; ++i)
    {
        iniSettings->setArrayIndex(i);
        QString name = iniSettings->value("name", QString("group_%1").arg(i)).toString();
        int tape = iniSettings->value("tape", i+1).toInt();
        basicGroups->appendRow(tape, name);
    }
    iniSettings->endArray();
    delete iniSettings;

}

void Settings::saveBasicGroups()
{
    QSettings *iniSettings = new QSettings("main.ini", QSettings::IniFormat);
    int size = basicGroups->rowCount(QModelIndex());
    QModelIndex index;
    iniSettings->beginWriteArray("Groups");

    for (int i = 0; i < size; ++i)
    {
        iniSettings->setArrayIndex(i);
        index = basicGroups->index(i, 2, QModelIndex());
        iniSettings->setValue("name", basicGroups->data(index, Qt::DisplayRole));
        index = basicGroups->index(i, 1, QModelIndex());
        iniSettings->setValue("tape", basicGroups->data(index, Qt::DisplayRole));
    }
    iniSettings->endArray();
    delete iniSettings;
}

void Settings::loadGroupsACL()
{
    ACL record;
    groupsACL.clear();
    QSettings *iniSettings = new QSettings("main.ini", QSettings::IniFormat);
    int size = iniSettings->beginReadArray("GroupsACL");
    for (int i = 0; i < size; ++i)
    {
        iniSettings->setArrayIndex(i);
        record.name = iniSettings->value("name", QString("group_%1").arg(i)).toString();
        record.tape = iniSettings->value("tape", i+1).toInt();
        groupsACL.append(record);
    }


    groupsACLModel->setGroupsACLList(groupsACL);

    iniSettings->endArray();
    delete iniSettings;
}

void Settings::saveGroupsACL()
{
    QSettings *iniSettings = new QSettings("main.ini", QSettings::IniFormat);

    groupsACL = *groupsACLModel->getGroupsACLList();

    int size = groupsACL.count();

    iniSettings->beginWriteArray("GroupsACL");

    for (int i = 0; i < size; ++i)
    {
        iniSettings->setArrayIndex(i);
        iniSettings->setValue("name", groupsACL.at(i).name);
        iniSettings->setValue("tape", groupsACL.at(i).tape);
    }
    iniSettings->endArray();
    delete iniSettings;
}

void Settings::loadGroupsRejectList()
{
    groupsRejectList.clear();
    QSettings *iniSettings = new QSettings("main.ini", QSettings::IniFormat);
    int size = iniSettings->beginReadArray("GroupsRejectList");
    for (int i = 0; i < size; ++i)
    {
        iniSettings->setArrayIndex(i);
        groupsRejectList.append(iniSettings->value("name", QString("group_%1").arg(i)).toString());
    }
    iniSettings->endArray();
    delete iniSettings;
}

void Settings::saveGroupsRejectList()
{
    QSettings *iniSettings = new QSettings("main.ini", QSettings::IniFormat);

    int size = groupsRejectList.count();

    iniSettings->beginWriteArray("GroupsRejectList");

    for (int i = 0; i < size; ++i)
    {
        iniSettings->setArrayIndex(i);
        iniSettings->setValue("name", groupsRejectList.at(i));
    }
    iniSettings->endArray();
    delete iniSettings;
}

void Settings::saveSettings()
{

    QSettings *iniSettings = new QSettings("main.ini", QSettings::IniFormat);

    iniSettings->beginGroup("StaticSettings");
        iniSettings->setValue("stepsPerMM", stepsPerMm);
        iniSettings->setValue("zeroX", zeroX);
        iniSettings->setValue("zeroY", zeroY);
        iniSettings->setValue("maxX", maxX);
        iniSettings->setValue("maxY", maxY);
    iniSettings->endGroup();
    delete iniSettings;
}


