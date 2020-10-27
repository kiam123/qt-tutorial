#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    count = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    server = new ChatServer();
    bool success = server->listen(QHostAddress::Any, 9999);
    QObject::connect(server, SIGNAL(clients_signal(int)),this, SLOT(slot_clients(int))); // signal和slot的參數一樣的話，slot可以拿到signal傳進來的值
    QObject::connect(server, SIGNAL(message_signal(QString)),this, SLOT(slot_message(QString))); // signal和slot的參數一樣的話，slot可以拿到signal傳進來的值

    if(success) {
        ui->textEdit->append("Chat Server start");
    } else {
        ui->textEdit->append("Chat Server error");
    }
}

void MainWindow::slot_clients(int users)
{
    QString str = QString("Clients : %1").arg(users);
    ui->label->setText(str);
}

void MainWindow::slot_message(QString msg)
{
    ui->textEdit->append(msg);
}
