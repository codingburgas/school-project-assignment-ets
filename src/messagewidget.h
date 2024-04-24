#ifndef MESSAGEWIDGET_H
#define MESSAGEWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

class MessageWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MessageWidget(const QString &message, QWidget *parent = nullptr);

private:
    QLabel *messageLabel;
};

#endif // MESSAGEWIDGET_H
