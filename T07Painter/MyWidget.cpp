#include "MyWidget.h"
#include <QApplication>
#include <QPainter>
#include <QPixmap>
#include <QPen>
MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{

}
void MyWidget::paintEvent(QPaintEvent *event)
{
    QPixmap pixmap(size());
    QPainter p(&pixmap);
    QTransform transform;
    pixmap.fill();
    transform.rotate(30);
    p.setTransform(transform);
    p.setRenderHint(QPainter::Antialiasing);
    //消锯齿
    p.translate(100,100);
    //整体坐标变换

    p.setPen(QPen(Qt::red,2,Qt::DashLine));
    p.setBrush(Qt::yellow);
    p.setFont(QFont("New Time",40,700,true));
    p.drawLine(QPoint(0,0),QPoint(100,100));
    p.translate(-100,-100);
    p.drawEllipse(QPoint(95,333),50,50);

    p.drawText(QPoint(300,50),"Hello World");
    p.drawRoundRect(QRect(40,40,100,50));
    p.end();

    p.begin(this);
    p.drawPixmap(0,0,pixmap);

}
int main(int argc,char* argv[])
{
    QApplication app(argc,argv);

    MyWidget w;
    w.show();
    return app.exec();
}
