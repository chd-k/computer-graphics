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
    p.setPen(QPen(Qt::blue,2,Qt::SolidLine));
    p.drawEllipse(x1 - R1, y1 - R1, (2 * R1), (2 * R1));
    p.drawEllipse(x2 - R2, y2 - R2, (2 * R2), (2 * R2));
    p.drawPoint(x1, y1);
    p.drawPoint(x2, y2);
    p.drawLine(x1, y1, x2, y2);
    p.setPen(QPen(Qt::red,1,Qt::SolidLine));
    calc.pointsOfTangency();
    p.drawLine(calc.x01, calc.y01, calc.x02, calc.y02);
    p.drawLine(x1, y1, calc.x01, calc.y01);
    p.drawLine(x2, y2, calc.x02, calc.y02);
//    p.drawLine(calc.xt1, calc.yt1, calc.xt2, calc.yt2);
}

//void qpaintwidget::drawImage()
//{
//    QPainter p(this);
//    float x1 = 50;
//    float y1 = 60;
//    float R1 = 30;
//    float x2 = 160;
//    float y2 = 180;
//    float R2 = 60;
//    calculus calc(x1, y1, R1, x2, y2, R2);
//    p.setPen(QPen(Qt::blue,2,Qt::SolidLine));
//    p.drawEllipse(x1 - R1, y1 - R1, (2 * R1), (2 * R1));
//    p.drawEllipse(x2 - R2, y2 - R2, (2 * R2), (2 * R2));
//    p.drawPoint(x1, y1);
//    p.drawPoint(x2, y2);
//    p.drawLine(x1, y1, x2, y2);
//    p.setPen(QPen(Qt::red,1,Qt::SolidLine));
//    calc.pointsOfTangency();
//    p.drawLine(calc.x01, calc.y01, calc.x02, calc.y02);
//    p.drawLine(x1, y1, calc.x01, calc.y01);
//    p.drawLine(x2, y2, calc.x02, calc.y02);
//}
