#include "smtapp.h"
#include <QFile>
#include <QFileOpenEvent>

SMTApp::SMTApp(QObject *parent) :
    QApplication(parent)
{
}

bool SMTApp::event ( QEvent * event )
{
    if(event->type() == QEvent::FileOpen)
    {
        qDebug() << static_cast<QFileOpenEvent*>(event)->file();
    }
}
