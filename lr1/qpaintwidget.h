#ifndef QPAINTWIDGET_H
#define QPAINTWIDGET_H

#include <QWidget>

class qpaintwidget : public QWidget
{
    Q_OBJECT
public:
    explicit qpaintwidget(QWidget *parent = nullptr);
    float x1, y1, r1, x2, y2, r2, x01, x02, y01, y02;
    void pointsOfTangency();

protected:
    void paintEvent(QPaintEvent*);

};

#endif // QPAINTWIDGET_H
