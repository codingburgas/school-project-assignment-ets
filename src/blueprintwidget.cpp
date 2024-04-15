#include "blueprintwidget.h"
#include "ui_blueprintwidget.h"
#include <QPixmap>
#include <QDir>
#include <QDebug>


BlueprintWidget::BlueprintWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BlueprintWidget)
{
    ui->setupUi(this);
    QString assetPath = ":/assets/assets/";
    QPixmap blueprintPix(assetPath + "blueprint-background.png");
    ui->blueprintPic->setPixmap(blueprintPix);
    signInScene = std::make_shared<SignIn>();
    QPixmap chatPix(assetPath + "ChatButton.png");
    ui->chatPic->setPixmap(chatPix);
    QPixmap adminPic(assetPath + "AdminButton.png");
    ui->adminPic->setPixmap(adminPic);
    QPixmap coursePix(assetPath + "CourseButton.png");
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

