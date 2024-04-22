#ifndef PROFILEWIDGET_H
#define PROFILEWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

class ProfileWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ProfileWidget(const QString &name, QWidget *parent = nullptr);

private slots:
    void onButtonClicked();

private:
    QLabel *nameLabel;
};

#endif // PROFILEWIDGET_H
