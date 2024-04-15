#include "blueprintwidget.h"
#include "ui_blueprintwidget.h"
#include <QPixmap>

BlueprintWidget::BlueprintWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BlueprintWidget)
{
    ui->setupUi(this);
    QPixmap pix("/Users/tatanasov/Code/9-10-digital-school/src/assets/blueprint-background.png");
    ui->blueprintPic-> setPixmap(pix);
    signInScene = std::make_shared<SignIn>();
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

