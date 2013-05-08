#ifndef CSVIMPORT_H
#define CSVIMPORT_H

#include <QDialog>
#include <QString>
#include <QStringList>

namespace Ui {
    class CSVImport;
}

class CSVImport : public QDialog
{
    Q_OBJECT

public:
    explicit CSVImport(QWidget *parent = 0);
    ~CSVImport();

    void setData(QList<QStringList> _data);
   QList<int> getList() { return list; }

private:
    Ui::CSVImport *ui;
    QList<QStringList> data;
    QList<int> list;
    void accept();
};

#endif // CSVIMPORT_H
