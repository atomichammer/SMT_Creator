#ifndef BASICGROUPSDIALOG_H
#define BASICGROUPSDIALOG_H

#include <QDialog>
#include "settings.h"
#include "groupsmodel.h"

namespace Ui {
class BasicGroupsDialog;
}

class BasicGroupsDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit BasicGroupsDialog(QWidget *parent = 0);
    ~BasicGroupsDialog();
    void setModel(GroupsModel *model);
    void addGroup();
    
    void removeGroup();
private slots:
    void on_pbAddGroup_clicked();

    void on_pbRemoveGroup_clicked();

private:
    Ui::BasicGroupsDialog *ui;
    GroupsModel * basicGroups;
};

#endif // BASICGROUPSDIALOG_H
