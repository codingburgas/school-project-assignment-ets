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

    QSize iconSize(50,50);
    QIcon chatIcon(assetPath + "ChatButton.png");
    ui->chatButton->setIcon(chatIcon);
    ui->chatButton->setIconSize(iconSize);

    QIcon adminIcon(assetPath + "AdminButton.png");
    ui->adminButton->setIcon(adminIcon);
    ui->adminButton->setIconSize(iconSize);

    QIcon courseIcon(assetPath + "CourseButton.png");
    ui->pushButton->setIcon(courseIcon);
    ui->pushButton->setIconSize(iconSize);
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

