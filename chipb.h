#ifndef CHIPB_H
#define CHIPB_H

#include <QMimeData>
#include <QStringList>
#include <QList>
#include "elements.h"

class ChipB : public QMimeData
{
    Q_OBJECT
public:
    explicit ChipB();
    void appendElement(ELEMENT *element);
    
signals:
    
public slots:
    QStringList formats() const;

protected:
    QVariant retrieveData(const QString &format,QVariant::Type preferredType) const;

private:
    QStringList mime_formats;
    QList<ELEMENT*> data;
    
};

#endif // CHIPB_H
