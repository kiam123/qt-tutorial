#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMediaPlayer>
#include <QVideoWidget>
#include <QMediaPlaylist>
#include <QVBoxLayout>
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // "D:/QtProjects/QtProject/qt-tutorial/book/Chapter13/ch13-QMediaPlayer/langrensha.mp4"
    // https://github.com/qyvlik/Flat.qml/issues/4
    // https://github.com/Nevcairiel/LAVFilters
    player = new QMediaPlayer(this);
    vw = new QVideoWidget(this);
    vw->setGeometry(50,50,800,300);
    player->setVideoOutput(vw);
//    this->setCentralWidget(vw);

    ui->statusbar->addPermanentWidget(ui->horizontalSlider);
    ui->statusbar->addPermanentWidget(ui->progressBar);

    connect(player,&QMediaPlayer::durationChanged,ui->horizontalSlider,&QSlider::setMaximum);
    connect(player,&QMediaPlayer::positionChanged,ui->horizontalSlider,&QSlider::setValue);
    connect(ui->horizontalSlider,&QSlider::sliderMoved,player,&QMediaPlayer::setPosition);

    connect(player,&QMediaPlayer::durationChanged,ui->progressBar,&QProgressBar::setMaximum);
    connect(player,&QMediaPlayer::positionChanged,ui->progressBar,&QProgressBar::setValue);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open a file");
    on_pushButton_4_clicked();

    player->setMedia(QUrl::fromLocalFile(filename));
    qDebug()<< filename;

    on_pushButton_2_clicked();
}

void MainWindow::on_pushButton_2_clicked()
{
    player->play();
    ui->statusbar->showMessage("playing...");
}

void MainWindow::on_pushButton_3_clicked()
{
    player->pause();
    ui->statusbar->showMessage("pause...");
}

void MainWindow::on_pushButton_4_clicked()
{
    player->stop();
    ui->statusbar->showMessage("stop...");
}
