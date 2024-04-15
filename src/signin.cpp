#include <iostream>
#include "signin.h"
#include "ui_signin.h"
#include <QMessageBox>
SignIn::SignIn(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SignIn)
{
    ui->setupUi(this);
    chatScene = std::make_shared<Chat>();
}

SignIn::~SignIn()
{
    delete ui;
}

void SignIn::on_pushButton_clicked()
{
    QString email = ui->lineEditEmail->text();
    QString password = ui->lineEditPassword->text();

    if(email == "test" && password == "test")
    {
        this->hide();
        chatScene->show();
    }
    else
    {
        QMessageBox::warning(this, "Login", "Wrong username or password");
    }
}

