#ifndef CHATCLIENT_H
#define CHATCLIENT_H

#include <QCoreApplication>
#include <QTcpSocket>
#include <QDebug>
#include <QTimer>

class ChatClient : public QObject {
    Q_OBJECT

public:
    ChatClient(QObject *parent = nullptr);
    Q_INVOKABLE void connectToServer();
    Q_INVOKABLE void sendMessage(const QString &msg);

signals:
    void messageReceived(const QString &msg);
private slots:    
    void onReadyRead();

private:
    QTcpSocket socket;
};

#endif // CHATCLIENT_H
