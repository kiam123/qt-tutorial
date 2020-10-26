#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mCamera = new QCamera(this);
    mCameraViewfinder = new QCameraViewfinder(this);
    mCameraImageCapture = new QCameraImageCapture(mCamera, this);
    mLayout = new QVBoxLayout;
    mOpcionesMenu = new QMenu("Opciones", this);
    mEncenderAction = new QAction("Encender", this);
    mApagarAction = new QAction("Apagar", this);
    mCapturatAction = new QAction("Capture", this);

    mOpcionesMenu->addActions({ mEncenderAction, mApagarAction,
                                mCapturatAction });
    ui->opcionesPushButton->setMenu(mOpcionesMenu);
    mCamera->setViewfinder(mCameraViewfinder);
    mLayout->addWidget(mCameraViewfinder);
    mLayout->setMargin(0);
    ui->scrollArea->setLayout(mLayout);

    connect(mEncenderAction, &QAction::triggered, [&](){
        mCamera->start();
    });

    connect(mApagarAction, &QAction::triggered, [&](){
        mCamera->stop();
    });

    connect(mCapturatAction, &QAction::triggered, [&](){
        auto filename = QFileDialog::getSaveFileName(this, "Capturar", "/",
                                                     "Imagen (*.jpg;*.jpeg)");

        if(filename.isEmpty()) {
            return ;
        }
        mCameraImageCapture->setCaptureDestination(
                    QCameraImageCapture::CaptureToFile);
        QImageEncoderSettings imageEncoderSettings;
        imageEncoderSettings.setCodec("image/jpeg");
        imageEncoderSettings.setResolution(1600,1200);
        mCameraImageCapture->setEncodingSettings(imageEncoderSettings);
        mCamera->setCaptureMode(QCamera::CaptureStillImage);
        mCamera->start();
        mCamera->searchAndLock();
        mCameraImageCapture->capture(filename);
        mCamera->unlock();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

