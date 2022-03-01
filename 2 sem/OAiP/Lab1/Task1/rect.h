#ifndef RECT_H
#define RECT_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QPainter>
#include <QTimer>
#include <QPushButton>


class Rect : public QGraphicsItem
{
private:
    int m_width;
    int m_height;
public:
    Rect(int width = 100, int height = 40);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
};

#endif // RECT_H
