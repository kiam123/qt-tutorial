#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QImage>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    QImage image(":/new/prefix1/img/categories-new-white (1).png");
//    QPainter painter(this);
//    painter.setPen(QPen(Qt::blue, 1, Qt::DashLine));
//    painter.drawRect(0,0,100,100);

//    QTransform transform;
//    transform.translate(50,50);
//    transform.rotate(45);
//    transform.scale(0.5, 0.5);

//    painter.setTransform(transform);
//    painter.drawImage(0, 0, image);

}

MainWindow::~MainWindow()
{
    delete ui;
}

// 重新定義paintEvent()事件處理
void MainWindow::paintEvent(QPaintEvent *e) {
    QImage image(":/new/prefix1/img/categories-new-white (1).png");
    QPainter painter(this);
    painter.setPen(QPen(Qt::blue, 1, Qt::DashLine));
    painter.drawRect(0,0,100,100);

    QTransform transform;
    transform.translate(50,50);
    transform.rotate(45);
    transform.scale(0.5, 0.5);

    painter.setTransform(transform);
    painter.drawImage(0, 0, image);
}

