#include "mygview.h"
#include "math.h"
#include "QDebug"
#include <QScrollBar>

MyGView::MyGView(QWidget* parent) : QGraphicsView(parent) {

    _pan = false;
    setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    setDragMode(QGraphicsView::RubberBandDrag);
}

void MyGView::scaleBy(double factor)
{
    scale(factor, factor);

}

void MyGView::wheelEvent(QWheelEvent *event)
{
   //if (event->modifiers() == Qt::ControlModifier)
    {
        setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
        scaleBy(pow(4.0 / 3.0, (event->delta() / 240.0)));
    }
    //else
    {
    //    QGraphicsView::wheelEvent(event);
    }
}

void MyGView::mousePressEvent(QMouseEvent *event){
    if (event->button() == Qt::LeftButton)
    {
       // emit emitCoords(QPoint(event->x(),event->y()), event->modifiers());
    }
    if(event->button() == Qt::MiddleButton)
    {
        _pan = true;
        _panStartX = event->x();
        _panStartY = event->y();
        setCursor(Qt::ClosedHandCursor);
        event->accept();
        return;
    }
    QGraphicsView::mousePressEvent(event);
}

void MyGView::mouseReleaseEvent(QMouseEvent *event){

    if(event->button() == Qt::MiddleButton)
    {
        _pan = false;
        setCursor(Qt::ArrowCursor);
        event->accept();
        return;
    }
    QGraphicsView::mouseReleaseEvent(event);
}

void MyGView::mouseMoveEvent(QMouseEvent* event)
{
    emit mousePos(mapToScene(QPoint(event->x(), event->y())));

    if (_pan)
    {

        horizontalScrollBar()->setValue(horizontalScrollBar()->value() - (event->x() - _panStartX));
        verticalScrollBar()->setValue(verticalScrollBar()->value() - (event->y() - _panStartY));

        _panStartX = event->x();
        _panStartY = event->y();
        event->accept();
        return;
    }
    QGraphicsView::mouseMoveEvent(event);
}

void MyGView::keyPressEvent(QKeyEvent *event)
{
    emit emitKey(event->key());
}

void MyGView::zoomIn()
{
    scaleBy(1.1);
}

void MyGView::zoomOut()
{
    scaleBy(1.0 / 1.1);
}
