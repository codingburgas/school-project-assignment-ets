#include "message.h"

Message::Message() = default;

QString Message::GetDecryptedText() {
    return Decrypt(this->text);
}

QString Message::GetText() {
    return this->text;
}

int Message::GetRecId(){
    return this->GetRecId();
}

int Message::GetSenderId(){
    return this->GetSenderId();
}

QString Message::GetTime(){
    return this->time;
}

Message::Message(int senderId, int recId, QString text, QString time):
    senderId(senderId), recId(recId), text(text), time(time){}

std::vector<Message> GetMessagesFromChat(int senderId, int recId){
    QSqlDatabase db = DatabaseManager::GetInstance()->GetDatabase();
    std::vector<Message> messages;

    QString queryString = "SELECT * FROM chats WHERE sender_id = :sender_id AND rec_id = :rec_id ORDER BY time ASC";
    QSqlQuery query;
    query.prepare(queryString);
    query.bindValue(":sender_id", senderId);
    query.bindValue(":rec_id", recId);

    query.exec();
    while(query.next()){
        Message message( senderId, recId, query.value(2).toString(), query.value(3).toString() );
        messages.push_back(message);
    }


    return messages;
}

void SendMessage(int senderId, int recId, QString text){

    QSqlDatabase db = DatabaseManager::GetInstance()->GetDatabase();
    QString encryptedText = Encrypt(text);

    QString queryString = "INSERT INTO chats (sender_id, rec_id, message) VALUES (:sender_id, :rec_id, :message)";
    QSqlQuery query;
    query.prepare(queryString);
    query.bindValue(":sender_id", senderId);
    query.bindValue(":rec_id", recId);
    query.bindValue(":message", encryptedText);

    if(!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return;
    }

    qDebug() << "Message sent successfully";
}
