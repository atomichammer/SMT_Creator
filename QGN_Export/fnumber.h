#ifndef FNUMBER_H
#define FNUMBER_H

#include <QDialog>
#include <QString>

namespace Ui {
    class FNumber;
}

class FNumber : public QDialog
{
    Q_OBJECT

public:
    explicit FNumber(QWidget *parent = 0);
    ~FNumber();
    int getNum() { return num; }
    void setSelected() { selected = true; }
    bool selectedOnly() {return selected; }

private slots:
    void on_comboBox_currentIndexChanged(int index);

private:
    void accept();
    Ui::FNumber *ui;
    int num;
    bool selected;
};

#endif // FNUMBER_H
