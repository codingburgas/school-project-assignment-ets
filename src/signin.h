#ifndef SIGNIN_H
#define SIGNIN_H

#include <QWidget>
#include "chat.h"

namespace Ui {
class SignIn;
}

class SignIn : public QWidget
{
    Q_OBJECT

public:
    explicit SignIn(QWidget *parent = nullptr);
    ~SignIn();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SignIn *ui;
    std::shared_ptr<Chat> chatScene;
};

#endif // SIGNIN_H
