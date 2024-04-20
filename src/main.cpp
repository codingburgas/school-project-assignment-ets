#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QtSql>
#include <QSqlDatabase>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("ets.postgres.database.azure.com");
    db.setUserName("ETS");
    db.setPassword("PGKPI_2024");
    db.setDatabaseName("postgres");

    if (!db.open()) {
        qDebug() << "Error opening database:" << db.lastError().text();
        return 1;
    }
    QSqlQuery query;
    QString insertQuery = "INSERT INTO users (username, email, password) VALUES ('Alex', 'AZK@gmail.com', 'asdasd')";
    if (query.exec(insertQuery)) {
        qDebug() << "Insert successful";
    } else {
        qCritical() << "Insert failed:" << query.lastError().text();
    }


    db.close();

    qDebug() << "Database connection established";


    MainWindow window;
    window.show();

    int result = app.exec();

    db.close();

    return result;
}
