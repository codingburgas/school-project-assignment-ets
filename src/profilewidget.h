#ifndef PROFILEWIDGET_H
#define PROFILEWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

class ProfileWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ProfileWidget(const QString &name, const QColor &color, QWidget *parent = nullptr);

private:
    QLabel *nameLabel;
    QLabel *pictureLabel;
};

#endif // PROFILEWIDGET_H
