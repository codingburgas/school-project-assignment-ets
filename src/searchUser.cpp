#include "searchUser.h"

std::vector<User> SearchUsersByUsername(const QString& username) {
    std::shared_ptr<DatabaseManager> instance = DatabaseManager::GetInstance();
    QSqlDatabase db = instance->GetDatabase();
    std::vector<User> foundUsers;

    if (!db.open()) {
        qDebug() << "Failed to open database:" /*<< db.lastError().text()*/;
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
