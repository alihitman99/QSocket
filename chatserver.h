#ifndef CHATSERVER_H
#define CHATSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>

class ChatServer : public QTcpServer {
    Q_OBJECT
public:
    ChatServer(QObject *parent = nullptr);

private slots:
    void onNewConnection();
};

#endif // CHATSERVER_H
