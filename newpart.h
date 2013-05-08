#ifndef NEWPART_H
#define NEWPART_H

#include <QDialog>

#include "groupsmodel.h"
namespace Ui {
class Newpart;
}

class Newpart : public QDialog
{
    Q_OBJECT
    
public:
    explicit Newpart(QWidget *parent = 0);
    ~Newpart();
    quint32 getXCoord();
    quint32 getYCoord();
    int getAngle();
    QString getName();
    int getGroup();
    int getGroupID();
    
    void setModel(GroupsModel *model_);
private:
    Ui::Newpart *ui;
    GroupsModel *model;
};

#endif // NEWPART_H
