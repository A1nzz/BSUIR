#include "lights.h"

lights::lights()
{

}

void lights::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    QPolygon pol;
    pol << QPoint(190, 10) << QPoint(180, 10) << QPoint(190, -10);
    painter->setBrush(Qt::yellow);
    painter->drawPolygon(pol);
    QPolygon pol2;
    pol2 <<   QPoint(-190, 10) << QPoint(-170, 10) << QPoint(-170, 20) << QPoint(-190, 20);
    painter->setBrush(Qt::yellow);
    painter->drawPolygon(pol2);
}




