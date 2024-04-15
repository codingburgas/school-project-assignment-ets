#include "blueprintwidget.h"
#include "ui_blueprintwidget.h"
#include <QPixmap>

BlueprintWidget::BlueprintWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BlueprintWidget)
{
    ui->setupUi(this);
    QPixmap blueprintPix("/Users/tatanasov/Code/school-project-assignment-ets/src/assets/blueprint-background.png");
    ui->blueprintPic->setPixmap(blueprintPix);
    signInScene = std::make_shared<SignIn>();
    QPixmap chatPix("/Users/tatanasov/Code/school-project-assignment-ets/src/assets/ChatButton.png");
    ui->chatPic->setPixmap(chatPix);
    QPixmap adminPic("/Users/tatanasov/Code/school-project-assignment-ets/src/assets/AdminButton.png");
    ui->adminPic->setPixmap(adminPic);
    QPixmap coursePix("/Users/tatanasov/Code/school-project-assignment-ets/src/assets/ChatButton.png");
    ui->coursePic->setPixmap(coursePix);
}

BlueprintWidget::~BlueprintWidget()
{
    delete ui;
}

void BlueprintWidget::on_pushButton_clicked()
{
    this->hide();
    signInScene->show();
}


void BlueprintWidget::on_adminButton_clicked()
{
    this->hide();
    signInScene->show();
}


void BlueprintWidget::on_chatButton_clicked()
{
    this->hide();
    signInScene->show();
}

