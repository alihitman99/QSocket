#include <QTcpServer>
#include <QTcpSocket>
#include <QCoreApplication>
#include <QList>
#include <QDebug>
#include "chatserver.h"

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);
    ChatServer server;
    return app.exec();
}
