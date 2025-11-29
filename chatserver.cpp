// #include "chatserver.h"

// ChatServer::ChatServer(QObject *parent)
//     : QObject{parent}
// {}

ChatServer::ChatServer(QObject *parent) : QTcpServer(parent) {
    connect(this, &QTcpServer::newConnection, this, &ChatServer::onNewConnection);
    listen(QHostAddress::Any, 1234);
    qDebug() << "Server started on port 1234...";
}
