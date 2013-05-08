#ifndef CHANGEGROUPDIALOG_H
#define CHANGEGROUPDIALOG_H

#include <QDialog>
#include <groupsmodel.h>

namespace Ui {
class ChangeGroupDialog;
}

class ChangeGroupDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit ChangeGroupDialog(QWidget *parent = 0);
    ~ChangeGroupDialog();
    
    void setModel(GroupsModel *model);
    void addNewGroup();
    QModelIndex getSelectedIndex();
private slots:
    void on_pbAdd_clicked();

private:
    Ui::ChangeGroupDialog *ui;
};

#endif // CHANGEGROUPDIALOG_H
