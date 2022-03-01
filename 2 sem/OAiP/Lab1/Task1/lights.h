#ifndef LIGHTS_H
#define LIGHTS_H

#include "car.h"

#include <QGraphicsItem>
#include <QPainter>


class lights : public Car
{
public:
    lights();
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // LIGHTS_H
