#include "chatserver.h"

ChatServer::ChatServer(QObject *parent)
    : QTcpServer(parent)
{

}


void ChatServer::incommingConnection(int socketfd)
{

}
