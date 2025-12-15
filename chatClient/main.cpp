#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QCoreApplication>
#include "chatclient.h"
#include "chatClientModel.h"


int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    ChatClient client;
    client.connectToServer();

    ChatClientModel chatModel;

    engine.rootContext()->setContextProperty("client", &client);
    engine.rootContext()->setContextProperty("chatModel", &chatModel);


    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("chatClient", "Main");



    return app.exec();
}
