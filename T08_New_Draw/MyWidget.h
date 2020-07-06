#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QPoint>
#include "MyButton.h"
class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

    QVector<QVector<QPoint>> _line;
    MyButton* button;
signals:
public slots:
    void slotButtonClicked();
};

#endif // MYWIDGET_H
