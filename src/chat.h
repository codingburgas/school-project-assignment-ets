#ifndef CHAT_H
#define CHAT_H

#include <QWidget>

namespace Ui {
class Chat;
}

class Chat : public QWidget
{
    Q_OBJECT

public:
    explicit Chat(QWidget *parent = nullptr);
    ~Chat();

private slots:
    void on_adminButton_clicked();

    void on_chatButton_clicked();

    void on_courseButton_clicked();

    void on_homeButton_clicked();

    void on_sendMessage_clicked();

    void on_searchBar_textChanged(const QString &arg1);

private:
    Ui::Chat *ui;
};

#endif // CHAT_H
