#ifndef SEARCHUSER_H
#define SEARCHUSER_H
#include "databaseManager.h"
#include "user.h"
#include <QSql>

std::vector<User> SearchUsersByUsername(const QString& username);

User GetUserByEmailAndPassword(const QString& email, const QString& password);

std::vector<User> GetAllUsers();

#endif // SEARCHUSER_H
