#ifndef CHATCLIENT_H
#define CHATCLIENT_H

#include <QCoreApplication>
#include <QTcpSocket>
#include <QDebug>
#include <QTimer>
#include <QUuid>


struct ClientInfo {
    QString id;
    QString name;
};

class ChatClient : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString clientName READ clientName WRITE setClientName NOTIFY clientNameChanged FINAL)

public:
    ChatClient(QObject *parent = nullptr);
    Q_INVOKABLE void connectToServer();
    Q_INVOKABLE void sendMessage(const QString &msg);

    QString clientName() const;
    void setClientName(const QString &newClientName);

signals:
    void messageReceived(const QString &msg);
    void clientNameChanged();

private slots:
    void onReadyRead();

private:
    QTcpSocket socket;
    ClientInfo clientInfo;
    QString m_clientName;
};

#endif // CHATCLIENT_H
