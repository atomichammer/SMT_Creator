#ifndef MYGVIEW_H
#define MYGVIEW_H

#include <QGraphicsView>
#include "QWheelEvent"

class MyGView : public QGraphicsView
{
    Q_OBJECT
public:
    MyGView(QWidget* parent = NULL);


signals:
    void emitCoords(QPoint point, int mod);
    void mousePos(QPointF point);
    void emitKey(int key);

public slots:

protected:
    virtual void wheelEvent(QWheelEvent* event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void keyPressEvent(QKeyEvent *event);

private:
    void scaleBy(double factor);
    void zoomIn();
    void zoomOut();
    bool _pan;
    int _panStartX;
    int _panStartY;

};

#endif // MYGVIEW_H
