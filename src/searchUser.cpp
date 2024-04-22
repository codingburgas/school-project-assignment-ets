#include "searchUser.h"
#include "encrypt.h"
std::vector<User> SearchUsersByUsername(const QString& username) {
    std::shared_ptr<DatabaseManager> instance = DatabaseManager::GetInstance();
    QSqlDatabase db = instance->GetDatabase();
    std::vector<User> foundUsers;
    if(username=="") return foundUsers;
    if (!db.open()) {
        qDebug() << "Failed to open database:" << db.lastError().text();
        return foundUsers;
    }


    QString queryString = "SELECT username, email, id FROM users WHERE LOWER(username) LIKE :username";
    QSqlQuery query;
    query.prepare(queryString);
    query.bindValue(":username", QString("%%1%").arg(username.toLower()));

    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return foundUsers;
    }

    while (query.next()) {
        QString foundUsername = query.value(0).toString();
        QString foundEmail = query.value(1).toString();
        int foundId = query.value(2).toInt();

        User foundUser(foundUsername, foundEmail, foundId);
        foundUsers.push_back(foundUser);
    }
    return foundUsers;
}

User GetUserByEmailAndPassword(const QString& email, const QString& password){
    QSqlDatabase db = DatabaseManager::GetInstance()->GetDatabase();
    User user;
    if (!db.open()) {
        qDebug() << "Failed to open database:" << db.lastError().text();
        return user;
    }

    QString queryString = "SELECT username, email, id FROM users WHERE email = :email AND password = :password";
    QSqlQuery query;
    query.prepare(queryString);
    query.bindValue(":email", email);
    query.bindValue(":password", Encrypt(password));

    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return user;
    }

    if (query.next()){
        QString foundUsername = query.value(0).toString();
        QString foundEmail = query.value(1).toString();
        int foundId = query.value(2).toInt();
        user = User(foundUsername, foundEmail, foundId);
    }

    return user;
}
