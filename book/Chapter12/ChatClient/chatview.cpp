#include "chatview.h"
#include "ui_chatview.h"
#include <QDebug>

ChatView::ChatView(QWidget *parent, ChatData *chatData) :
    QMainWindow(parent),
    ui(new Ui::ChatView)
{
    ui->setupUi(this);
    qDebug() << "text: "<< chatData->text;

    socket = new QTcpSocket(this);
    socket->connectToHost(chatData->text, 9999);

    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
}

ChatView::~ChatView()
{
    delete ui;
}

void ChatView::readyRead()
{
    while(socket->canReadLine())
    {
        QString line = QString::fromUtf8(socket->readLine()).trimmed();
        QRegExp messageRegex("^([^:]+):(.*)$");

        if(messageRegex.indexIn(line) != -1)
        {
            QString user = messageRegex.cap(1);
            QString message = messageRegex.cap(2);
            ui->roomTextEdtit->append("<b>"+user+"</br>: "+message);
        }
    }
}

void ChatView::connected()
{
    socket->write(QString("/me"+ui->userLineEdit->text()
                               +"\n").toUtf8());
}

void ChatView::on_pushButton_clicked()
{
//    socket->
}
