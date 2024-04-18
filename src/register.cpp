#include "register.h"
#include "ui_register.h"
#include <QDebug>

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

void Register::on_pushButton_clicked()
{
    this->hide();
    QString fullName = ui->lineEditFullName->text();
    QString email = ui->lineEditEmail->text();
    QString password = ui->password->text();
    qDebug() << fullName << email << password;
    chatScene->show();
}

