#include <iostream>
#include "signin.h"
#include "ui_signin.h"
#include <QMessageBox>
SignIn::SignIn(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SignIn)
{
    ui->setupUi(this);
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
        QMessageBox::information(this, "Login", "Your credentials are correct!");
    }
    else
    {
        QMessageBox::warning(this, "Login", "Wrong username or password");
    }
}

