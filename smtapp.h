#ifndef SMTAPP_H
#define SMTAPP_H

#include <QApplication>

class SMTApp : public QApplication
{
    Q_OBJECT
public:
    explicit SMTApp(QObject *parent = 0);
    
signals:
    
public slots:

protected:
    bool event(QEvent *);

    
};

#endif // SMTAPP_H
