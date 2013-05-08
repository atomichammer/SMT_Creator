#ifndef ORDERBY_H
#define ORDERBY_H

#include <QDialog>

namespace Ui {
class OrderBy;
}

class OrderBy : public QDialog
{
    Q_OBJECT
    
public:
    explicit OrderBy(QWidget *parent = 0);
    ~OrderBy();
    int getNum() { return num; }
    
private:
    Ui::OrderBy *ui;
    void accept();
    int num;
};

#endif // ORDERBY_H
