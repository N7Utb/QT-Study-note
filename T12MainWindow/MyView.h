#ifndef MYVIEW_H
#define MYVIEW_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QMouseEvent>
class MyView : public QWidget
{
    Q_OBJECT
public:
    explicit MyView(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
signals:

};

#endif // MYVIEW_H
