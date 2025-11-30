#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QTcpServer>
#include <QTcpSocket>
#include <QCoreApplication>
#include <QList>
#include <QDebug>
#include "chatserver.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    ChatServer server;
    engine.rootContext()->setContextProperty("server", &server);

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("chatServer", "Main");

    return app.exec();
}
