#include "rect.h"

Rect::Rect(int width, int height)
{
    m_width = width;
    m_height = height;
}

QRectF Rect::boundingRect() const {
    return QRectF(0, 0, 500, 200);
}

void Rect::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(Qt::black);
    painter->setBrush(QBrush(Qt::red));
    painter->drawRect(0, 0, m_width, m_height);
}


