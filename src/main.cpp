#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QtSql>
#include <QSqlDatabase>
#include <databaseManager.h>
#include <memory>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);


    if (DatabaseManager::GetInstance()->GetDatabase().open()) {
        qDebug() << "Database connection established";
        // Perform database operations
    } else {
        qCritical() << "Error opening database:" << DatabaseManager::GetInstance()->GetDatabase().lastError().text();
    }


    MainWindow window;
    window.show();

    int result = app.exec();

    return result;
}
