#include "qpaintwidget.h"

#include <QPainter>

qpaintwidget::qpaintwidget(QWidget *parent) : QWidget(parent)
{

}

void qpaintwidget::paintEvent(QPaintEvent*)
{
    QPainter p(this);
    p.setPen(QPen(Qt::red,1,Qt::SolidLine));
    p.drawLine(10, 10, 30, 20);
}
