#ifndef MESSAGE_H
#define MESSAGE_H
#include <QString>
#include "encrypt.h"
#include "databaseManager.h"
#include <QSql>
#include <QSqlDatabase>>

class Message {
private:
    int senderId, recId;
    QString text, time;
public:
    Message();
    Message(int senderId, int recId, QString text, QString time);
    QString GetText();
    QString GetTime();
    QString GetDecryptedText();
    int GetSenderId();
    int GetRecId();
};

std::vector<Message> GetSentMessagesFromChat(int senderId, int recId);

#endif // MESSAGE_H
