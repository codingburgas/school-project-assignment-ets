#ifndef SEARCHUSER_H
#define SEARCHUSER_H
#include "databaseManager.h"
#include "user.h"
#include <QSql>

std::vector<User> SearchUsersByUsername(const QString& username);

#endif // SEARCHUSER_H
