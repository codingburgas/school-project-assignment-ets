#include "profilewidget.h"

ProfileWidget::ProfileWidget(const QString &name, QWidget *parent)
    : QWidget(parent)
{
    // Set background color and border for the main container widget
    QString styleSheet = "QWidget { background-color: lightgray; border: 1px solid gray; padding: 10px;}";
    this->setStyleSheet(styleSheet);

    nameLabel = new QLabel(name, this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(nameLabel);

    setFixedHeight(100);

    setLayout(layout);
}
