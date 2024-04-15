#include "mainwindow.h"
#include <QApplication>
#include "supabasemanager.h"
#include <QDebug>

int main(int argc, char *argv[])
{

    SupabaseManager supabaseManager;
    supabaseManager.fetchDataFromTable("table_name");


    QApplication app(argc, argv);
    MainWindow window;
    window.show();
    return app.exec();
}
