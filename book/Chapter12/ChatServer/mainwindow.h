#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include "chatserver.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int count;

private slots:
    void on_pushButton_clicked();
    void slot_clients(int users);
    void slot_message(QString msg);

private:
    Ui::MainWindow *ui;

    ChatServer *server;

};
#endif // MAINWINDOW_H
