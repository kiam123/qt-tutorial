#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPropertyAnimation>
#include <QPushButton>
#include <QRect>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPushButton *btn = new QPushButton("Buttn", this);
    btn->setGeometry(10, 10, 100, 30);

    QPropertyAnimation *animation;
    animation = new QPropertyAnimation(btn, "geometry", this);

    animation->setDuration(3000);
    animation->setStartValue(QRect(10, 10, 100, 30));
    animation->setEndValue(QRect(200,150,100,30));

    animation->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

