#include "databaseManager.h"

std::shared_ptr<DatabaseManager> DatabaseManager::instance = nullptr;

void DatabaseManager::ConfigDatabase(){
    database.setHostName("ets.postgres.database.azure.com");
    database.setUserName("ETS");
    database.setPassword("PGKPI_2024");
    database.setDatabaseName("postgres");
}

DatabaseManager::DatabaseManager(){
    database = QSqlDatabase::addDatabase("QPSQL");
    ConfigDatabase();
    qDebug() << "Configurated Database";
}

std::shared_ptr<DatabaseManager> DatabaseManager::GetInstance() {
    if (instance == nullptr) {
        instance = std::shared_ptr<DatabaseManager>(new DatabaseManager());
    }
    return instance;
}


QSqlDatabase& DatabaseManager::GetDatabase(){
    return database;
}

