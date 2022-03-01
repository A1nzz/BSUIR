#include "car.h"

Car::Car()
{
    points[0] = QPoint(40,-50);
    points[1] = QPoint(80,-10);
    points[2] = QPoint(40,-10);
    points[3] = QPoint(-20,-10);
    points[4] = QPoint(-40,-10);
    points[5] = QPoint(-60,-20);
    points[6] = QPoint(-40,-40);
    points[7] = QPoint(40,-40);
    points[8] = QPoint(-60,-50);
    points[9] = QPoint(-80,-40);
    points[10] = QPoint(-100,-20);
    points[11] = QPoint(-180,-20);
    points[12] = QPoint(-190, 0);
    points[13] = QPoint(-190, 30);
    points[14] = QPoint(-120, 30);
    points[15] = QPoint(-110, 20);
    points[16] = QPoint(-70, 20);
    points[17] = QPoint(-70, 30);
    points[18] = QPoint(-20, 30);
    points[19] = QPoint(80, 30);
    points[20] = QPoint(110, 30);
    points[21] = QPoint(120, 20);
    points[22] = QPoint(170, 20);
    points[23] = QPoint(180, 10);
    points[24] = QPoint(190, -10);
    points[25] = QPoint(-60, 30);
    points[26] = QPoint(-60, 40);
    points[27] = QPoint(100, 40);
    points[28] = QPoint(-180, 30);
    points[29] = QPoint(-180, 40);
    points[30] = QPoint(-120, 40);
    points[31] = QPoint(150, 20);
    points[32] = QPoint(160, 30);
    points[33] = QPoint(170, 30);
    points[34] = QPoint(180, 20);
    points[35] = QPoint(200, 20);
    points[36] = QPoint(200, 10);
    points[37] = QPoint(-190, 10);
    points[38] = QPoint(-170, 10);
    points[39] = QPoint(-170, 20);
    points[40] = QPoint(-190, 20);
    points[41] = QPoint(190, 10);

}

void Car::drawPol(QPainter *painter, int p1, int p2, int p3, QColor color)
{
    QPolygon pol;
    pol << QPoint(points[p1]) << QPoint(points[p2]) << QPoint(points[p3]);
    painter->setBrush(color);
    painter->drawPolygon(pol);
}

void Car::drawPol(QPainter *painter, int p1, int p2, int p3, int p4, QColor color)
{
    QPolygon pol;
    pol << QPoint(points[p1]) << QPoint(points[p2]) << QPoint(points[p3]) << QPoint(points[p4]);
    painter->setBrush(color);
    painter->drawPolygon(pol);
}

void Car::drawPol(QPainter *painter, int p1, int p2, int p3, int p4, int p5, QColor color)
{
    QPolygon pol;
    pol << QPoint(points[p1]) << QPoint(points[p2]) << QPoint(points[p3]) << QPoint(points[p4]) << QPoint(points[p5]);
    painter->setBrush(color);
    painter->drawPolygon(pol);
}

void Car::drawPol(QPainter *painter, int p1, int p2, int p3, int p4, int p5, int p6, int p7, QColor color)
{
    QPolygon pol;
    pol << QPoint(points[p1]) << QPoint(points[p2]) << QPoint(points[p3]) << QPoint(points[p4]) << QPoint(points[p5]) << QPoint(points[p6]) << QPoint(points[p7]);
    painter->setBrush(color);
    painter->drawPolygon(pol);
}

void Car::drawPol(QPainter *painter, int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9, int p10, int p11, int p12, QColor color)
{
    QPolygon pol;
    pol << QPoint(points[p1]) << QPoint(points[p2]) << QPoint(points[p3]) << QPoint(points[p4]) << QPoint(points[p5]) << QPoint(points[p6]) << QPoint(points[p7])
           << QPoint(points[p8]) << QPoint(points[p9]) << QPoint(points[p10]) << QPoint(points[p11]) << QPoint(points[p12]);
    painter->setBrush(color);
    painter->drawPolygon(pol);
}



void Car::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    //Корпус
    drawPol(painter, 23, 24, 41, Qt::gray);
    drawPol(painter, 0, 1, 2, Qt::blue);
    drawPol(painter, 2, 4, 5, 6, 7, Qt::white);
    drawPol(painter, 0, 8, 9, 10, 5, 6, 7, Qt::red);
    drawPol(painter, 10, 11, 12, 13, 14, 15, 16, 17, 18, 3, 4, 5, Qt::red);
    drawPol(painter, 19, 20, 21, 22, 23, 24, 1, Qt::red);
    drawPol(painter, 25, 26, 27, 20, Qt::red);
    drawPol(painter, 28, 29, 30, 14, Qt::black);
    drawPol(painter, 34, 31, 32, 33, Qt::red);
    drawPol(painter, 37, 38, 39, 40, Qt::gray);
    drawPol(painter, 22, 23, 36, 35, Qt::black);


    //Колеса
    painter->drawEllipse(-110, 20,40,40);
    painter->drawEllipse(115, 20,40,40);
}

QRectF Car::boundingRect() const {
    return QRectF(-250, -250, 250, 250);
}


