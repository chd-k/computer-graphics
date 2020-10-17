#include "qpaintwidget.h"
#include "calculus.h"

#include <QPainter>

qpaintwidget::qpaintwidget(QWidget *parent) : QWidget(parent)
{
    this->resize(maximumWidth(), maximumHeight());
}

void qpaintwidget::paintEvent(QPaintEvent*)
{
    QPainter p(this);
    float x1 = 50;
    float y1 = 60;
    float R1 = 30;
    float x2 = 160;
    float y2 = 180;
    float R2 = 60;
    calculus calc(x1, y1, R1, x2, y2, R2);
    p.setPen(QPen(Qt::red,2,Qt::SolidLine));
    p.drawLine(calc.xt1, calc.yt1, calc.xt2, calc.yt2);
    p.drawEllipse(x1 - R1, y1 - R1, (2 * R1), (2 * R1));
    p.drawEllipse(x2 - R2, y2 - R2, (2 * R2), (2 * R2));
}
