#ifndef QGN_EXPORT_H
#define QGN_EXPORT_H

#include "QGN_Export_global.h"


#include <../interfaces.h>

class QGN_Export : public QObject,
                         public ExportInterface,
                         public ImportInterface
{
    Q_OBJECT
    Q_INTERFACES(ExportInterface ImportInterface)

public:
    bool saveToFile();
    bool loadFromFile();
};

#endif // QGN_EXPORT_H
