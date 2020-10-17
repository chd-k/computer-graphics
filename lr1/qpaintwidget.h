#ifndef QPAINTWIDGET_H
#define QPAINTWIDGET_H

#include <QWidget>

class qpaintwidget : public QWidget
{
    Q_OBJECT
public:
    explicit qpaintwidget(QWidget *parent = nullptr);
//    void drawImage();

protected:
    void paintEvent(QPaintEvent*);


};

#endif // QPAINTWIDGET_H
