#include "messagewidget.h"

MessageWidget::MessageWidget(const QString &message, QWidget *parent)
    : QWidget(parent)
{
    // Set background color and border for the message widget
    QString styleSheet = "QWidget { background-color: white; border: 1px solid gray; padding: 10px; color: black;}";
    this->setStyleSheet(styleSheet);

    // Create a label for the message
    messageLabel = new QLabel(message, this);
    messageLabel->setWordWrap(true); // Enable word wrapping for long messages
    messageLabel->setAlignment(Qt::AlignCenter); // Align text to the center vertically

    // Create a layout for the message widget
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(messageLabel);

    // Add a stretch to push the message label to the bottom
    layout->addStretch();

    // Set maximum height for the message widget
    setMaximumHeight(100); // Adjust the height as needed
    setMaximumWidth(300);

    // Set the layout for the message widget
    setLayout(layout);
}
