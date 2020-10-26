#ifndef CHATVIEW_H
#define CHATVIEW_H

#include <QMainWindow>
#include "chatdata.h"
#include <QTcpSocket>

namespace Ui {
class ChatView;
}

class ChatView : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChatView(QWidget *parent = nullptr);
    ChatView(QWidget *parent = nullptr, ChatData *chatData = nullptr);
    ~ChatView();

private:
    Ui::ChatView *ui;
    QTcpSocket *socket;

    void readyRead();
    void connected();
};

#endif // CHATVIEW_H
