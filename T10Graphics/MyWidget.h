#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QPrinter>

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);
    void mousePressEvent(QMouseEvent *event);
    QGraphicsScene* _scene;  //data model
    QGraphicsView* _view;   //show data model

signals:
public slots:
    void slotPaintRequested(QPrinter*);
};

#endif // MYWIDGET_H
