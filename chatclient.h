#ifndef CHATCLIENT_H
#define CHATCLIENT_H

#include <QCoreApplication>
#include <QTcpSocket>
#include <QDebug>
#include <QTimer>

class ChatClient : public QObject {
    Q_OBJECT
    QTcpSocket socket;

public:
    ChatClient(QObject *parent = nullptr);

    void connectToServer();

private slots:
    void onConnected();

    void onReadyRead();
};

#endif // CHATCLIENT_H
