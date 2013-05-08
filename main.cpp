#include <QtGui/QApplication>
#include <QTranslator>
#include <QLibraryInfo>
#include <QLocale>
#include "mainwindow.h"
#include <QDebug>
#include "qt-solutions-qt-solutions/qtsingleapplication/src/QtSingleApplication"


//int main(int argc, char *argv[])
//{

//    QApplication a(argc, argv);

//    MainWindow w;

//    w.show();

//    return a.exec();
//}

int main(int argc, char *argv[])
{

    QtSingleApplication instance("File loader QtSingleApplication example", argc, argv);
    QString message;

    QString locale = QLocale::system().name();

    QTranslator translator;
    translator.load(QString("tablo_") + locale);
    instance.installTranslator(&translator);

    for (int a = 1; a < argc; ++a) {
    message += argv[a];
    if (a < argc-1)
        message += " ";
    }

    if (instance.sendMessage(message))
    return 0;

    MainWindow mw;
    mw.handleMessage(message);
    mw.show();

    QObject::connect(&instance, SIGNAL(messageReceived(const QString&)),
             &mw, SLOT(handleMessage(const QString&)));

    instance.setActivationWindow(&mw, false);
    QObject::connect(&mw, SIGNAL(needToShow()), &instance, SLOT(activateWindow()));

    return instance.exec();
}
