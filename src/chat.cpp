#include "chat.h"
#include "ui_chat.h"
#include "profilewidget.h"
#include "searchUser.h"
#include "messagewidget.h"
#include "message.h"

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

    profilesLayout = new QVBoxLayout(ui->profilesTab);

    userList = GetAllUsers();

    QVBoxLayout *messageTabLayout = new QVBoxLayout(ui->messagesTab);
    ui->messagesTab->setLayout(messageTabLayout);

    messageTimer = new QTimer(this);
    connect(messageTimer, &QTimer::timeout, this, &Chat::updateMessages);
    messageTimer->start(5000); // Update messages every 1000 milliseconds (1 second)


    QShortcut *shortcut = new QShortcut(QKeySequence(Qt::Key_Return), this);
    connect(shortcut, &QShortcut::activated, ui->sendMessage, &QPushButton::click);
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


void Chat::on_sendMessage_clicked() {
    QString messageText = ui->messageField->text();
    if(messageText!=""){
    qDebug() << Chat::GetUser().GetId() << Chat::GetOtherUser().GetId();
    SendMessage(Chat::GetUser().GetId(), Chat::GetOtherUser().GetId(), messageText);
    ui->messageField->setText("");
    }
}

void Chat::on_searchBar_textChanged(const QString &arg1)
{
    std::vector<User> foundUserList;

    for( User& user : userList){
        if(user.GetUsername().contains(arg1, Qt::CaseInsensitive)) {
            foundUserList.push_back(user);
        }
    }

    while (QLayoutItem* item = profilesLayout->takeAt(0)) {
        delete item->widget();
        delete item;
    }
    for (size_t i = 0; i < foundUserList.size(); ++i) {
        const QString &profileUsername = foundUserList[i].GetUsername();
        // Create a ProfileWidget instance with the name
        ProfileWidget *profileWidget = new ProfileWidget(profileUsername, this);
        profileWidget->SetUser(foundUserList[i]);
        profileWidget->SetButtonFunc([this](){
            ui->othersName->setText(GetOtherUser().GetUsername());
        });
        qDebug() << profileWidget->GetUser().GetUsername();

        profilesLayout->addWidget(profileWidget);
    }
    ui->profilesTab->setLayout(profilesLayout);
}

User Chat::otherUser;
User Chat::user;

void Chat::SetOtherUser(const User& other){
    otherUser = other;

}
User& Chat::GetOtherUser(){
    return otherUser;
}

void Chat::SetUser(const User& other){
    user = other;

}
User& Chat::GetUser(){
    return user;
}


void Chat::updateMessages()
{
    // Get the latest sent and received messages
    sentMessages = GetMessagesFromChat(Chat::GetUser().GetId(), Chat::GetOtherUser().GetId());
    receivedMessages = GetMessagesFromChat(Chat::GetOtherUser().GetId(), Chat::GetUser().GetId());

    // Update sent messages
    if (!sentMessages.empty()) {
        QVBoxLayout *messageTabLayout = qobject_cast<QVBoxLayout*>(ui->messagesTab->layout());
        if (messageTabLayout) {
            // Clear the existing message widgets before adding new ones
            QLayoutItem *child;
            while ((child = messageTabLayout->takeAt(0)) != nullptr) {
                delete child->widget();
                delete child;
            }

            // Add new message widgets for sent messages
            for (size_t i = sentMessages.size()>10?sentMessages.size()-10:0; i<sentMessages.size() ;i++) {
                QString messageText = sentMessages[i].GetText();
                if (!messageText.isEmpty()) {
                    MessageWidget *messageWidget = new MessageWidget(Decrypt(messageText), this);
                    messageTabLayout->addWidget(messageWidget);
                }
            }

        }
    }

    // Update received messages
    // Note: You may want to handle received messages similarly

    // Clear the message field after sending the message
    ui->messageField->clear();
}



