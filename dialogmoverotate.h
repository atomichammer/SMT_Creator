#ifndef DIALOGMOVEROTATE_H
#define DIALOGMOVEROTATE_H

#include <QDialog>

namespace Ui {
class DialogMoveRotate;
}

class DialogMoveRotate : public QDialog
{
    Q_OBJECT
    
public:
    explicit DialogMoveRotate(QWidget *parent = 0);
    ~DialogMoveRotate();
    
    quint32 getFirstXCoord();
    quint32 getFirstYCoord();
    quint32 getSecondXCoord();
    quint32 getSecondYCoord();
private:
    Ui::DialogMoveRotate *ui;
};

#endif // DIALOGMOVEROTATE_H
