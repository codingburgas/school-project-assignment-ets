#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "blueprintwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_pushButton_clicked();

    void on_quitButton_clicked();

    void on_openBlueprintButton_clicked();

private:
    Ui::MainWindow *ui;
    std::shared_ptr<BlueprintWidget> secondScene;
};

#endif
