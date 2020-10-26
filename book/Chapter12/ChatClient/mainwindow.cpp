#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <chatdata.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
//    socket->connectToHost(ui->serverLineEdit->text(), 9999);
    hide();
    ChatData *chatData = new ChatData();
    chatData->text = ui->serverLineEdit->text();

    qDebug() << "ui:" << ui->serverLineEdit->text();
    chatView = new ChatView(this, chatData);
    chatView->show();
}


