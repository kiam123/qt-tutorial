#ifndef CHATSERVER_H
#define CHATSERVER_H

#include <QTcpServer>
#include <QTcpSocket>

class ChatServer: public QTcpServer
{
public:
    explicit ChatServer(QObject *parent=0);

private slots:
    void readyRead();
    void disconnected();
    void sendUserList();

protected:
    void incommingConnection(int socketfd);

private:
    QSet<QTcpSocket*> clients;
    QMap<QTcpSocket*, QString> users;
};

#endif // CHATSERVER_H
