#include "chatClientModel.h"

ChatClientModel::ChatClientModel(QObject *parent)
{

}

int ChatClientModel::rowCount(const QModelIndex &parent) const
{
    return mChatItem.size();
}

QVariant ChatClientModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= mChatItem.size())
        return QVariant();

    const ChatClientItem &item = mChatItem[index.row()];
    switch (role) {
    case MsgRole: return item.msg;
    case IsClientRole: return item.isClient;
    default: return QVariant();
    }
}

QHash<int, QByteArray> ChatClientModel::roleNames() const
{
    return {
        { MsgRole, "msgRole" },
        { IsClientRole, "isClient" },
    };
}

void ChatClientModel::addItem(const QString msg, const bool isClient)
{
    beginInsertRows(QModelIndex(), mChatItem.size(), mChatItem.size());
    mChatItem.push_back({ msg, isClient });
    mChatClinet.sendMessage(msg);
    endInsertRows();
}
