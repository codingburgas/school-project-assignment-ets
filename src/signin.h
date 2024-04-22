#ifndef SIGNIN_H
#define SIGNIN_H

#include <QWidget>
#include "chat.h"
#include "register.h"
#include "databaseManager.h"
#include "encrypt.h"
#include "QDebug.h"
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

    void on_pushButton_3_clicked();

private:
    Ui::SignIn *ui;
    std::shared_ptr<Chat> chatScene;
    std::shared_ptr<Register> registerScene;

};

#endif // SIGNIN_H
