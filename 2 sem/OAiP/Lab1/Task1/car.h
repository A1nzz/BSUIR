#ifndef CAR_H
#define CAR_H


#include "rect.h"


class Car : public Rect
{
private:
    QPoint points[42];

    void drawPol(QPainter *painter, int p1,int p2, int p3, QColor color);
    void drawPol(QPainter *painter, int p1,int p2, int p3, int p4, QColor color);
    void drawPol(QPainter *painter, int p1,int p2, int p3, int p4, int p5, QColor color);
    void drawPol(QPainter *painter, int p1,int p2, int p3, int p4, int p5, int p6, int p7, QColor color);
    void drawPol(QPainter *painter, int p1,int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9, int p10, int p11, int p12, QColor color);

public:
    Car();
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
};
#endif // CAR_H
