#include "profilewidget.h"

ProfileWidget::ProfileWidget(const QString &name, const QColor &color, QWidget *parent)
    : QWidget(parent)
{
    // Set background color and border for the main container widget
    QString styleSheet = "QWidget { background-color: lightgray; border: 1px solid gray; padding: 10px; }";
    this->setStyleSheet(styleSheet);

    nameLabel = new QLabel(name, this);
    pictureLabel = new QLabel(this);

    // Set background color for the profile picture
    pictureLabel->setAutoFillBackground(true);
    QPalette palette = pictureLabel->palette();
    palette.setColor(QPalette::Window, color);
    pictureLabel->setPalette(palette);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(nameLabel);
    layout->addWidget(pictureLabel);

    setLayout(layout);
}
