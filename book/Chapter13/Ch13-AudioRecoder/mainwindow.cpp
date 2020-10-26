#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    player = new QMediaPlayer(this);

    connect(player, &QMediaPlayer::positionChanged, this, &MainWindow::on_positionChanged);
    connect(player, &QMediaPlayer::durationChanged, this, &MainWindow::on_durationChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    player->setPosition(position);
}

void MainWindow::on_horizontalSlider_2_sliderMoved(int position)
{
    player->setVolume(position);
}

void MainWindow::on_pushButton_clicked()
{
    player->setMedia(QUrl::fromLocalFile("D:/QtProjects/QtProject/qt-tutorial/book/Chapter13/Ch13-AudioRecoder/liangliang.mp3"));
    player->play();
    qDebug() << player->errorString();
}

void MainWindow::on_pushButton_2_clicked()
{
    player->stop();
}

void MainWindow::on_positionChanged(qint64 position) {
    ui->horizontalSlider->setValue(position);
}

void MainWindow::on_durationChanged(qint64 position){
    ui->horizontalSlider_2->setMaximum(position);
}


