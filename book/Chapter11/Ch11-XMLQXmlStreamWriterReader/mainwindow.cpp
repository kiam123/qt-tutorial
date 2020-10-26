#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QXmlStreamReader>
#include <QFile>
#include <QDebug>
#include <QStringList>
#include <QTreeWidgetItem>
#include <QStack>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFile file("D:/QtProjects/QtProject/qt-tutorial/book/Chapter11/Ch11-XMLQXmlStreamWriterReader/bookindex.xml");
    QString result;
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        qDebug() << "Cannot open file for reading:"
                     << qPrintable(file.errorString()) << "\n";

    while(!file.atEnd()) {
        QByteArray line = file.readLine();
        result.append(line);
    }
    file.flush();
    file.close();
    qDebug() << result;

    QXmlStreamReader xmlReader;
    xmlReader.addData(result);

    ui->treeWidget->clear();
    QStack<QTreeWidgetItem *> stackItems;

    while(!xmlReader.atEnd()) {
        if(xmlReader.isStartElement()) {
            QStringList sl;
            sl << xmlReader.name().toString();
            QTreeWidgetItem *item = new QTreeWidgetItem(sl);

            if(stackItems.count() == 0) {
                ui->treeWidget->addTopLevelItem(item);
            } else {
                stackItems.top()->addChild(item);
            }
            stackItems.push(item);
        }
        if(xmlReader.isEndElement()) {
            stackItems.pop();
        }
        xmlReader.readNext();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QXmlStreamReader xmlReader;
    xmlReader.addData(ui->textBrowser->toPlainText());

    ui->treeWidget->clear();
    QStack<QTreeWidgetItem *> stackItems;

    while(!xmlReader.atEnd()) {
        if(xmlReader.isStartElement()) {
            QStringList sl;
            sl << xmlReader.name().toString();
            QTreeWidgetItem *item = new QTreeWidgetItem(sl);

            if(stackItems.count() == 0) {
                ui->treeWidget->addTopLevelItem(item);
            } else {
                stackItems.top()->addChild(item);
            }
            stackItems.push(item);
        }
        if(xmlReader.isEndElement()) {
            stackItems.pop();
        }
        xmlReader.readNext();
    }
}
