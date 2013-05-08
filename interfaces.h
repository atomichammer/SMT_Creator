#ifndef INTERFACES_H
#define INTERFACES_H

#include <QtPlugin>

class ExportInterface
{
public:
    virtual ~ExportInterface() { }
    virtual bool saveToFile();
};

class ImportInterface
{
public:
    virtual ~ImportInterface() { }
    virtual bool loadFromFile();
};

Q_DECLARE_INTERFACE(ExportInterface, "smtconverter.ExportInterface/1.0")
Q_DECLARE_INTERFACE(ImportInterface, "smtconverter.ImportInterface/1.0")

#endif // INTERFACES_H
