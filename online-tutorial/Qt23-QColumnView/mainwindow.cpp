#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->columnView->setColumnWidths({80, 120});
    for(auto i=0;i < 10;i++) {
        auto group = new QStandardItem(QString("%1").arg(i));
        for(auto j=0; j < 10;j++) {
            group->appendRow(new QStandardItem(QString("%1").arg(i)));
        }
        model.appendRow(group);
    }

    ui->columnView->setModel(&model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

