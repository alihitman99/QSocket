#include "chatclient.h"

ChatClient::ChatClient(QObject *parent) : QObject(parent) {
    connect(&socket, &QTcpSocket::readyRead, this, &ChatClient::onReadyRead);
    // connect(&socket, &QTcpSocket::disconnected, this, []() {
    //     qDebug() << "Disconnected from server.";
    //     QCoreApplication::quit();
    // });
}

void ChatClient::connectToServer() {
    socket.connectToHost("127.0.0.1", 1234);
}

void ChatClient::sendMessage(const QString &msg)
{
    if (socket.state() == QAbstractSocket::ConnectedState) {
        socket.write(msg.toUtf8());
        socket.flush();
    } else {
        qDebug() << "Not connected!";
    }
}


void ChatClient::onReadyRead() {
    // QByteArray msg = socket.readAll();
    // qDebug() << "Server says:" << msg;

    QString msg = QString::fromUtf8(socket.readAll());
    // qDebug() << "server say: " << msg;
    emit messageReceived(msg);
    // socket.disconnectFromHost();
}
