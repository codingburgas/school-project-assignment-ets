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
    MainWindow window;
    window.show();

    int result = app.exec();

    return result;
}
