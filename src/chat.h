#ifndef CHAT_H
#define CHAT_H

#include <QWidget>
#include "user.h"
#include <QVBoxLayout>
#include "message.h"
#include <QScrollArea>
#include <QScrollBar>
#include <QTimer>
#include <QShortcut>

namespace Ui {
class Chat;
}

class Chat : public QWidget
{
    Q_OBJECT

public:
    explicit Chat(QWidget *parent = nullptr);
    ~Chat();
    static void SetOtherUser(const User& other);
    static User& GetOtherUser();
    static void SetUser(const User& user);
    static User& GetUser();
private slots:
    void on_adminButton_clicked();

    void on_chatButton_clicked();

    void on_courseButton_clicked();

    void on_homeButton_clicked();

    void on_sendMessage_clicked();

    void on_searchBar_textChanged(const QString &arg1);

    void updateMessages();

private:
    Ui::Chat *ui;
    std::vector<User> userList;
    QVBoxLayout *profilesLayout;
    static User otherUser;
    static User user;
    std::vector<Message> sentMessages;
    std::vector<Message> receivedMessages;
    QTimer *messageTimer;
};

#endif // CHAT_H
