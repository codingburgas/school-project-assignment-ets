#include <iostream>
#include "signin.h"
#include "ui_signin.h"
#include <QMessageBox>
#include "user.h"
#include "searchUser.h"
SignIn::SignIn(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SignIn)
{
    ui->setupUi(this);
    chatScene = std::make_shared<Chat>();
    registerScene = std::make_shared<Register>();
}

SignIn::~SignIn()
{
    delete ui;
}
//Method for sending the credentials to the database

void SignIn::on_pushButton_clicked()
{
    QString email = ui->lineEditEmail->text();
    QString password = ui->lineEditPassword->text();

    std::shared_ptr<DatabaseManager> instance = DatabaseManager::GetInstance();
    QSqlDatabase db = instance->GetDatabase();

    if (!db.open()) {
        qDebug() << "Failed to open database:" << db.lastError().text();
        return;
    }
    {
        QString cipheredPassword = Encrypt(password);
        QString queryString = "SELECT COUNT(*) FROM users WHERE email = :email AND password = :password";
        QSqlQuery query;
        query.prepare(queryString);
        query.bindValue(":email", email);
        query.bindValue(":password", cipheredPassword);

        if (query.exec()) {
            if(query.next()){
                int check = query.value(0).toInt();
                if(check>0){
                    Chat::SetUser(GetUserByEmailAndPassword(email, password));
                    chatScene->show();
                }
                else {
                    qDebug() << "Wrong credentials";
                }
            }
        } else {
            qDebug() << "Failed to add record:" << query.lastError().text();
        }
    }
}


void SignIn::on_pushButton_3_clicked()
{
    this->hide();
    registerScene->show();
}

