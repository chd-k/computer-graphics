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



