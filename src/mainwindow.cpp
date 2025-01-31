#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "blueprintwidget.h"
#include <QMessageBox>
#include <QGraphicsScene>
#include <QGraphicsView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    secondScene = std::make_shared<BlueprintWidget>();
    chatScene = std::make_shared<Chat>();
}

MainWindow::~MainWindow()
{
    delete ui;
}
//Quit button method
void MainWindow::on_quitButton_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Quit", "Are you sure you want to quit the application?", QMessageBox::Yes | QMessageBox::No);

    if(reply == QMessageBox::Yes)
    {
        QApplication:: quit();
    }else{
        qDebug() << "No clicked";
    }
}


void MainWindow::on_openBlueprintButton_clicked()
{
    this->hide();
    secondScene->show();
}

void MainWindow::on_pushButton_clicked(){
    this->hide();
    chatScene->show();
}
