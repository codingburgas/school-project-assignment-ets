#include "messagewidget.h"
//Message widgets for creating boxes
MessageWidget::MessageWidget(const QString &message, QWidget *parent)
    : QWidget(parent)
{
    QString styleSheet = "QWidget { background-color: white; padding: 10px; color: black; border-radius: 5px; font-size: 15px}";
    this->setStyleSheet(styleSheet);

    messageLabel = new QLabel(message, this);
    messageLabel->setWordWrap(true);
    messageLabel->setAlignment(Qt::AlignCenter);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(messageLabel);

    layout->addStretch();

    setMaximumHeight(100);
    setMaximumWidth(300);
    setLayout(layout);
}
