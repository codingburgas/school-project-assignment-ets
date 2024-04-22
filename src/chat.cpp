#include "chat.h"
#include "ui_chat.h"
#include "profilewidget.h"
#include "searchUser.h"

Chat::Chat(QWidget *parent) : QWidget(parent)
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


    QVBoxLayout *profilesLayout = new QVBoxLayout(ui->profilesTab);
    // ui->groupBox_2->setStyleSheet("background-color: lightgray; border: 1px solid gray; padding: 10px;");

    // Dummy data, replace this with your actual profile data
    QString profiles[] = {"Alice", "Bob", "Charlie", "Todor"};
    int numProfiles = sizeof(profiles) / sizeof(profiles[0]);

    for (int i = 0; i < numProfiles; ++i) {
        const QString &profile = profiles[i];
        // Create a ProfileWidget instance with the name
        ProfileWidget *profileWidget = new ProfileWidget(profile, this);
        profilesLayout->addWidget(profileWidget);
    }

    ui->profilesTab->setLayout(profilesLayout);
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

void Chat::on_searchBar_textChanged(const QString &arg1)
{
    userList = SearchUsersByUsername(arg1);
    qDebug() << arg1 << " ";
}

