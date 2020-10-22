#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    QBrush redBrush(Qt::red);
    QBrush blueBrush(Qt::blue);
    QPen blackPen(Qt::black);
    blackPen.setWidth(6);

    scene->addEllipse(100,100,100,100,blackPen,redBrush);
    rectangle = scene->addRect(-100,-100,50,50,blackPen,blueBrush);
    rectangle->setFlag(QGraphicsItem::ItemIsMovable);

    QTransform transform;
    transform.translate(50,50);
    transform.rotate(45);
//    transform.scale(0.5, 0.5);
    rectangle->setTransform(transform);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->graphicsView->rotate(-1);
}

void MainWindow::on_pushButton_clicked()
{
    ui->graphicsView->rotate(1);
}
