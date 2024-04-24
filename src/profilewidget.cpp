#include "profilewidget.h"
#include "chat.h"

ProfileWidget::ProfileWidget(const QString &name, QWidget *parent)
    : QWidget(parent)
{
    // Set background color and border for the main container widget
    QString styleSheet = "QWidget { background-color: #1B262C; border: 1px solid gray; padding: 10px; border-radius: 5px; color: white;}";
    this->setStyleSheet(styleSheet);

    nameLabel = new QLabel(name, this);

    QPushButton *button = new QPushButton("Message", this); // Create a button
    connect(button, &QPushButton::clicked, this, &ProfileWidget::onButtonClicked); // Connect its clicked signal to a slot

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(nameLabel);
    layout->addWidget(button); // Add the button to the layout

    setFixedHeight(100);

    setLayout(layout);
}

void ProfileWidget::onButtonClicked() {
    // Slot function to handle button click
    qDebug() << "Button clicked for profile:" << nameLabel->text();
    Chat::SetOtherUser(GetUser());
    buttonFunc();
}

void ProfileWidget::SetUser(const User& user){
    this->user = user;
}
User& ProfileWidget::GetUser(){
    return user;
}

void ProfileWidget::SetButtonFunc(std::function<void()> buttonFunc){
    this->buttonFunc = buttonFunc;
}
