#ifndef GROUPEDIT_H
#define GROUPEDIT_H

#include <QDialog>
#include <QAbstractTableModel>

namespace Ui {
class GroupEdit;
}

class GroupEdit : public QDialog
{
    Q_OBJECT
    
public:
    explicit GroupEdit(QWidget *parent = 0);
    ~GroupEdit();
    void setModel(QAbstractTableModel *model);
    
private:
    Ui::GroupEdit *ui;
};

#endif // GROUPEDIT_H
