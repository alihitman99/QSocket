#include "chatserver.h"


ChatServer::ChatServer(QObject *parent) : QTcpServer(parent) {
    connect(this, &QTcpServer::newConnection, this, &ChatServer::onNewConnection);
    listen(QHostAddress::Any, 1234);
    qDebug() << "Server started on port 1234...";
}

void ChatServer::sendToAll(const QString &msg)
{
    for (QTcpSocket *c : clients) {
        if (c->state() == QAbstractSocket::ConnectedState){
            c->write(msg.toUtf8());
            c->flush();
        }
    }
}

void ChatServer::onNewConnection() {
    QTcpSocket *socket = nextPendingConnection();
    clients.append(socket);
    qDebug() << "Client connected!";

    connect(socket, &QTcpSocket::readyRead, this, [this, socket]() {
        QByteArray msg = socket->readAll();
        emit messageReceived(QString::fromUtf8(msg));
        qDebug() << "Received:" << QString::fromUtf8(msg);
        // socket->write("Hi client, I got your message!");

        // send to all clients msg
        // for (QTcpSocket *c : clients) {
        //     if (c->state() == QAbstractSocket::ConnectedState)
        //         c->write(msg);
        // }
    });

    // connect(socket, &QTcpSocket::disconnected, [socket]() {
    //     qDebug() << "Client disconnected.";
    //     socket->deleteLater();
    // });
}
