#ifndef PROFILEWIDGET_H
#define PROFILEWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include "user.h"

class ProfileWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ProfileWidget(const QString &name, QWidget *parent = nullptr);
    void SetUser(const User& user);
    User& GetUser();
    void SetButtonFunc(std::function<void()>);
private slots:
    void onButtonClicked();

private:
    QLabel *nameLabel;
    User user;
    std::function<void()> buttonFunc;
};

#endif // PROFILEWIDGET_H
