#include "server.h"

Server::Server()
{

}
void Server::incommingConnection(int socketfd)
{
    QTcpSocket *client = new QTcpSocket(this);
    client->setSocketDescriptor(socketfd);
    clients.insert(client);

    emit clients_signal(clients.count());

    QString str;
    str = QString("New client from: %1")
            .arg(client->peerAddress().toString());

    emit message_signal(str);

    connect(client, SIGNAL(readyRead()), this,
            SLOT(readyRead()));

    connect(client, SIGNAL(readyRead()), this,
            SLOT(disconnected()));
}

void Server::readyRead(){
//    QTcpSocket *client = (QTcpSocket*)sender();
//    this.sender();
}

void Server::disconnected(){

}

void Server::sendUserList(){

}

void Server::clients_signal(int users)
{

}

void Server::message_signal(QString msg){

}
