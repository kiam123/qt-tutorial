#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPushButton *btn1 = new QPushButton("First", this);
    btn1->setGeometry(10,10,100,30);

    QPushButton *btn2 = new QPushButton("Second", this);
    btn1->setGeometry(10,40,100,30);

    anim1 = new QPropertyAnimation(btn1, "geometry");
    anim1->setDuration(2000);
    anim1->setStartValue(QRect(10,10,100,30));
    anim1->setEndValue(QRect(200,150,100,30));

    anim2 = new QPropertyAnimation(btn2, "geometry");
    anim2->setDuration(2000);
    anim2->setStartValue(QRect(10,10,100,30));
    anim2->setEndValue(QRect(200,195,100,30));

//    sGroup = new QSequentialAnimationGroup;
//    sGroup->addAnimation(anim1);
//    sGroup->addAnimation(anim2);

    pGroup = new QParallelAnimationGroup;
    pGroup->addAnimation(anim1);
    pGroup->addAnimation(anim2);

    connect(btn1, SIGNAL(clicked()),this, SLOT(on_pushButton_clicked()));
    connect(btn2, SIGNAL(clicked()),this, SLOT(on_pushButton_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
//    sGroup->start(QPropertyAnimation::DeleteWhenStopped);
    pGroup->start(QPropertyAnimation::DeleteWhenStopped);
}
