#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H
#include <memory>
#include <QtSql>
#include <QSqlDatabase>
#include <QDebug>
class DatabaseManager {
private:
    static std::shared_ptr<DatabaseManager> instance;
    DatabaseManager();
    QSqlDatabase database;

public:
    static std::shared_ptr<DatabaseManager> GetInstance();
    void ConfigDatabase();
    QSqlDatabase& GetDatabase();
};

#endif // DATABASEMANAGER_H
