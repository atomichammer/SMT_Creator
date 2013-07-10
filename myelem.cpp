#include "myelem.h"

#include <QtGui>
#include "settings.h"

Chip::Chip(int x, int y, QString name, int angle)
{

    color = QColor::fromHsl(0, 255, 125);

    divisor = 60;
    chipWidth = 1.5*197;
    chipHeight = 3*197;

    this->x = x;
    this->y = y;
    this->tape = 0;
    setZValue((x + y) % 2);
    this->setRotation(angle);
    this->designator = name;

    this->setTransformOriginPoint(chipWidth/2/divisor, chipHeight/2/divisor);

    setFlags(ItemIsSelectable);
    setAcceptsHoverEvents(true);

}

void Chip::setCoordX(qint64 _x)
{
    Settings *settings = Settings::Instance();
    coord_x = _x;
    setPos((settings->getMaxX() - coord_x)/divisor, coord_y/divisor);
}
void Chip::setCoordY(qint64 _y)
{
    Settings *settings = Settings::Instance();
    coord_y = _y;
    setPos((settings->getMaxX() - coord_x)/divisor, coord_y/divisor);
}

 QRectF Chip::boundingRect() const
 {
     return QRectF(0, 0, chipWidth/divisor, chipHeight/divisor);
 }

 QPainterPath Chip::shape() const
 {
     QPainterPath path;
     path.addRect(0, 0, chipWidth/divisor, chipHeight/divisor);
     return path;
 }

 void Chip::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
 {
     Q_UNUSED(widget);
     int x = y = 0;

     QColor fillColor = (option->state & QStyle::State_Selected) ? QColor(Qt::white) : color;
     QColor dotColor = (option->state & QStyle::State_Selected) ? color : QColor(Qt::black);
     if (option->state & QStyle::State_MouseOver)
         fillColor = fillColor.darker(125);

     const qreal lod = option->levelOfDetailFromTransform(painter->worldTransform());
     if (lod < 0.2) {
         if (lod < 0.125) {
             painter->fillRect(QRectF(0, 0, chipWidth/divisor, chipHeight/divisor), fillColor);
             return;
         }

         QBrush b = painter->brush();
         painter->setBrush(fillColor);
         painter->drawRect(0, 0, chipWidth/divisor, chipHeight/divisor);
         painter->setBrush(b);
         return;
     }

     QPen oldPen = painter->pen();
     QPen pen = oldPen;
     int width = 0;
     if (option->state & QStyle::State_Selected)
         width += 2;

     pen.setWidth(width);
     QBrush b = painter->brush();
     painter->setBrush(QBrush(fillColor.dark(option->state & QStyle::State_Sunken ? 120 : 100)));

     painter->drawRect(QRect(0, 0, chipWidth/divisor, chipHeight/divisor));
     painter->setBrush(b);

     if (lod >= 1.5) {
         painter->save();
         painter->setBrush(dotColor);
         painter->scale(0.1, 0.1);
         painter->drawEllipse(22,3,15,15);
         painter->restore();
     }

     // Draw text
     if (lod >= 4) {

         //define coords
         if(this->rotation() == 0){
             x = 50;
             y = 0;
         }
         if(this->rotation() == 90){
             x = 0;
             y = 0;
         }
         if(this->rotation() == 180){
             x = 0;
             y = -80;
         }
         if(this->rotation() == -90){
             x = 0;
             y = 0;
         }
         if(this->rotation() == -180){
             x = 0;
             y = -80;
         }
         int step = 128;
         QFont font("Arial", step/lod);
         font.setStyleStrategy(QFont::ForceOutline);
         painter->setFont(font);
         painter->save();
         painter->rotate(-this->rotation());
         painter->scale(0.1, 0.1);
         painter->setPen(QColor("black"));
         painter->drawText(x, y+step/lod, QString("%1").arg(designator));
         painter->drawText(x, (y+step*2+10)/lod, QString("%1%2").arg(this->rotation()).arg(QString::fromUtf8("\u00B0")));
         //painter->drawText(x, (y+step*3+20)/lod, QString("%1").arg(group_id));
         painter->restore();
     }

     // Draw lines
     if (lod >= 0.5) {

     }
     if (lod >= 0.4) {
     }
 }

 void Chip::mousePressEvent(QGraphicsSceneMouseEvent *event)
 {
     QGraphicsItem::mousePressEvent(event);
     update();
 }

 void Chip::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
 {
     QGraphicsItem::mouseMoveEvent(event);
 }

 void Chip::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
 {
     QGraphicsItem::mouseReleaseEvent(event);
     update();
 }
