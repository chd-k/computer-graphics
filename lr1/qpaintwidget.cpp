#include "qpaintwidget.h"

#include <QPainter>
#include <cmath>

qpaintwidget::qpaintwidget(QWidget *parent) : QWidget(parent)
{
    this->resize(1100, 580);
    x1 = y1 = r1 = x2 = y2 = r2 = x01 = x02 = y01 = y02 = 0;
}

void qpaintwidget::paintEvent(QPaintEvent*)
{
    QPainter p(this);
//    ���������� ����� �������
    pointsOfTangency();
//    ��������� �����������
    p.setPen(QPen(Qt::blue,3,Qt::SolidLine));
    p.drawEllipse(x1 - r1, y1 - r1, (2 * r1), (2 * r1));
    p.drawEllipse(x2 - r2, y2 - r2, (2 * r2), (2 * r2));
//    ��������� ������� �����������
    p.drawPoint(x1, y1);
    p.drawPoint(x2, y2);
//    ��������� ������� ����� �������� �����������
    p.setPen(QPen(Qt::green,2,Qt::DotLine));
    p.drawLine(x1, y1, x2, y2);
//    ��������� ������� �����������
    p.setPen(QPen(Qt::red,2,Qt::SolidLine));
    p.drawLine(x01, y01, x02, y02);
//    ��������� �������� � ����� �������
    p.setPen(QPen(Qt::yellow,2,Qt::DashLine));
    p.drawLine(x1, y1, x01, y01);
    p.drawLine(x2, y2, x02, y02);
}

void qpaintwidget::pointsOfTangency()
{
//    ������ �������� ���
    float dx = x2 - x1;
//    ������ �������� �����
    float dy = y2 - y1;
//    ���������� ����� �������� �����������
    float dxy = sqrt(pow(dx, 2) + pow(dy, 2));
//    ��������������� �������
    float R = (r1 + r2) / dxy;
//    ���������� ����� �������
    x01 = x1 + R * r1 * (dx / dxy) + sqrt(1 - pow(R, 2)) * r1 * (dy / dxy);
    y01 = y1 + R * r1 * (dy / dxy) + sqrt(1 - pow(R, 2)) * r1 * ( - dx / dxy);
    x02 = x2 - R * r2 * (dx / dxy) - sqrt(1 - pow(R, 2)) * r2 * (dy / dxy);
    y02 = y2 - R * r2 * (dy / dxy) - sqrt(1 - pow(R, 2)) * r2 * ( - dx / dxy);
}
