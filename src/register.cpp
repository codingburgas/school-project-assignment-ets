#include "register.h"
#include "ui_register.h"
#include "chat.h"
#include "searchUser.h"

Register::Register(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Register)
{
    ui->setupUi(this);
    chatScene = std::make_shared<Chat>();
}

Register::~Register()
{
    delete ui;
}
//Method for sending the credentials to the database
void Register::on_pushButton_clicked()
{
    this->hide();
    QString fullName = ui->lineEditFullName->text();
    QString email = ui->lineEditEmail->text();
    QString password = ui->password->text();
    std::shared_ptr<DatabaseManager> instance = DatabaseManager::GetInstance();
    QSqlDatabase db = instance->GetDatabase();

    if (!db.open()) {
        qDebug() << "Failed to open database:" << db.lastError().text();
        return;
    }
    {
        QString cipheredPassword = Encrypt(password);
        QString queryString = "INSERT INTO users (username, email, password) VALUES(:username, :email, :password)";
        QSqlQuery query;
        query.prepare(queryString);
        query.bindValue(":username", fullName);
        query.bindValue(":email", email);
        query.bindValue(":password", cipheredPassword);

        if (query.exec()) {
            qDebug() << "Record added successfully";
        } else {
            qDebug() << "Failed to add record:" << query.lastError().text();
        }
    }
    chatScene->show();
    Chat::SetUser(GetUserByEmailAndPassword(email, password));
}

