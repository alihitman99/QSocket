#ifndef CHATCLIENTMODEL_H
#define CHATCLIENTMODEL_H

#include <QAbstractListModel>
#include <QObject>
#include "chatclient.h"


struct ChatClientItem {
    QString msg;
    bool isClient;
};

class ChatClientModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum Roles {
        MsgRole = Qt::UserRole + 1,
        IsClientRole,
    };

    explicit ChatClientModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE void addItem(const QString msg, const bool isClient);

private:
    QList<ChatClientItem> mChatItem;
    ChatClient mChatClinet;
};

#endif // CHATCLIENTMODEL_H
