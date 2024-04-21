#ifndef REGISTER_H
#define REGISTER_H

#include <QWidget>
#include "chat.h"
#include "databaseManager.h"
#include "encrypt.h"

namespace Ui {
class Register;
}

class Register : public QWidget
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Register *ui;
    std::shared_ptr<Chat> chatScene;
};

#endif // REGISTER_H
