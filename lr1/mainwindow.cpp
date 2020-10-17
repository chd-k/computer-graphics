#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qpaintwidget.h"

#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pw = new qpaintwidget(this->ui->canvaswidget);
//    pw->drawImage();
//    ui->verticalLayout->addWidget(wgt);
}



MainWindow::~MainWindow()
{
    pw->deleteLater();
    delete ui;
}




void MainWindow::on_enter_clicked()
{
//    if (pw == nullptr)
//        pw = new qpaintwidget(this->ui->canvaswidget);
//    else
//        pw->update();
    pw->x1 = ui->linex1->text().toFloat();
    pw->x2 = ui->linex2->text().toFloat();
    pw->y1 = ui->liney1->text().toFloat();
    pw->y2 = ui->liney2->text().toFloat();
    pw->r1 = ui->liner1->text().toFloat();
    pw->r2 = ui->liner2->text().toFloat();
    pw->update();
}
