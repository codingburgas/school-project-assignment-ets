#include "chat.h"
#include "ui_chat.h"

Chat::Chat(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Chat)
{
    ui->setupUi(this);

    QSize iconSize(50,50);
    QString assetPath = ":/assets/assets/";
    QIcon courseIcon(assetPath + "CourseButton.png");
    ui->courseButton->setIcon(courseIcon);
    ui->courseButton->setIconSize(iconSize);

    QIcon homeIcon(assetPath + "HomeButton.png");
    ui->homeButton->setIcon(homeIcon);
    ui->homeButton->setIconSize(iconSize);

    QIcon adminIcon(assetPath + "AdminButton.png");
    ui->adminButton->setIcon(adminIcon);
    ui->adminButton->setIconSize(iconSize);

    QIcon chatIcon(assetPath + "ChatButton.png");
    ui->chatButton->setIcon(chatIcon);
    ui->chatButton->setIconSize(iconSize);

    QSize iconSize2(30,30);
    QIcon saveIcon(assetPath + "SaveButton.png");
    ui->sendMessage->setIcon(saveIcon);
    ui->sendMessage->setIconSize(iconSize2);

    ui->searchBar->setPlaceholderText("Search...");
    ui->messageField->setPlaceholderText("Type a message...");
}

Chat::~Chat()
{
    delete ui;
}

void Chat::on_adminButton_clicked()
{

}


void Chat::on_chatButton_clicked()
{

}


void Chat::on_courseButton_clicked()
{

}


void Chat::on_homeButton_clicked()
{

}


void Chat::on_sendMessage_clicked()
{

}

