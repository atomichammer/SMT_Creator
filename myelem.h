#ifndef MYELEM_H
#define MYELEM_H
#include <QtGui/QColor>
#include <QtGui/QGraphicsItem>

class Chip : public QGraphicsItem
{
public:
    Chip(int x, int y, QString name, int angle);
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget);
    //setters
    void setCoordX(qint64 _x);
    void setCoordY(qint64 _y);
    void setTape(int _tape) { tape = _tape; }
    void setGroupID(uint _group_id) { group_id = _group_id; }
    void setColor(QColor color_) {color = color_;}

    //getters
    qint64 getCoordX() { return coord_x; }
    qint64 getCoordY() { return coord_y; }
    //quint32 getTape() { return tape; }
    quint32 getGroupID() { return group_id; }
    QString getDesignator() { return designator; }


protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    int x, y;
    QColor color;
    QString designator;
    qint64 coord_x;
    qint64 coord_y;
    quint32 tape;
    int angle;
    uint group_id;

};

#endif // MYELEM_H
