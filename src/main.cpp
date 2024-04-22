#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QtSql>
#include <QSqlDatabase>
#include <databaseManager.h>
#include <memory>
#include "searchUser.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;
    window.show();

    std::vector<User> users;
    users = SearchUsersByUsername("tosho");

    for(size_t i = 0; i<users.size(); i++){
        qDebug() << users[i].GetUsername() << users[i].GetEmail() << users[i].GetId() << '\n';
    }

    int result = app.exec();

    return result;
}
