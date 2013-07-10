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
    void    setFirstXCoord(quint32 x);
    void    setFirstYCoord(quint32 y);
    void    setSecondXCoord(quint32 x);
    void    setSecondYCoord(quint32 y);

private:
    Ui::DialogMoveRotate *ui;
};

#endif // DIALOGMOVEROTATE_H
