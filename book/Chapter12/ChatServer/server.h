#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>

#include <QTcpSocket>
class Server : public QTcpServer
{
public:
    Server();

private slots:
    void readyRead();
    void disconnected();
    void sendUserList();

signals:
    void clients_signal(int users);
    void message_signal(QString msg);

protected:
    void incommingConnection(int socketfd);

private:
    QSet<QTcpSocket*> clients;
    QMap<QTcpSocket*, QString> users;
};

#endif // SERVER_H
