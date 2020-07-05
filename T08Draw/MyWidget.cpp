#include "MyWidget.h"
#include <QApplication>
#include <QPainter>
#include <QMouseEvent>
MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{

}
void MyWidget::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);
    for(int i=0;i<this->_line.size()-1;++i)
    {
        p.drawLine(_line.at(i),_line.at(i+1));
    }
}
void MyWidget::mouseMoveEvent(QMouseEvent *event)
{
    _line.append(event->pos());
    update();
}
void MyWidget::mousePressEvent(QMouseEvent *event)
{
    _line.append(event->pos());
}
void MyWidget::mouseReleaseEvent(QMouseEvent *event)
{
    _line.append(event->pos());
}
int main(int argc,char* argv[])
{
    QApplication app(argc,argv);

    MyWidget w;
    w.show();
    return app.exec();
}
