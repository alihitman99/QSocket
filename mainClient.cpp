#include <QCoreApplication>
#include "chatclient.h"


int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);
    ChatClient client;
    client.connectToServer();

    return app.exec();
}
