// #include "chatclient.h"

// ChatClient::ChatClient(QObject *parent)
//     : QObject{parent}
// {}

ChatClient::ChatClient(QObject *parent) : QObject(parent) {
    connect(&socket, &QTcpSocket::connected, this, &ChatClient::onConnected);
    connect(&socket, &QTcpSocket::readyRead, this, &ChatClient::onReadyRead);
    connect(&socket, &QTcpSocket::disconnected, this, []() {
        qDebug() << "Disconnected from server.";
        QCoreApplication::quit();
    });
}
