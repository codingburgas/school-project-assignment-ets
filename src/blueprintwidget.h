#ifndef BLUEPRINTWIDGET_H
#define BLUEPRINTWIDGET_H

#include <QWidget>
#include "signin.h"
namespace Ui {
class BlueprintWidget;
}

class BlueprintWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BlueprintWidget(QWidget *parent = nullptr);
    ~BlueprintWidget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::BlueprintWidget *ui;
    std::shared_ptr<SignIn> signInScene;
};

#endif // BLUEPRINTWIDGET_H
