#ifndef ADDACLDIALOG_H
#define ADDACLDIALOG_H

#include <QDialog>
#include "groupsmodel.h"
#include "groupsaclmodel.h"
#include "groupsaclfilter.h"

namespace Ui {
class AddACLDialog;
}

class AddACLDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit AddACLDialog(GroupsModel *_groupsModel, GroupsACLModel *_groupsACLModel, QWidget *parent = 0);
    ~AddACLDialog();

    void setGroupsModel(GroupsModel *_groupsModel);
    void setGroupsACLModel(GroupsACLModel *_groupsACLModel);
    
private slots:

    void on_pbAddToRejectList_clicked();

    void on_pbRemoveFromRejectList_clicked();

    void on_pbAddToAcceptList_clicked();

    void on_pbRemoveFromAcceptList_clicked();


private:
    Ui::AddACLDialog *ui;
    QStringList availableNames;
    GroupsModel *groupsModel;
    GroupsACLModel *groupsACLModel;
    GroupsACLFilter *ACLFilter;
};

#endif // ADDACLDIALOG_H
