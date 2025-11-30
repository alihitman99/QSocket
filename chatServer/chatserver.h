#ifndef CHATSERVER_H
#define CHATSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>

class ChatServer : public QTcpServer {
    Q_OBJECT
public:
    ChatServer(QObject *parent = nullptr);
    Q_INVOKABLE void sendToAll(const QString &msg);

private slots:
    void onNewConnection();

signals:
    void messageReceived(const QString &msg);

private:
    QList<QTcpSocket*> clients;
};

#endif // CHATSERVER_H
