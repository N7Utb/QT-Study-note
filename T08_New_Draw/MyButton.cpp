#include "MyButton.h"
#include <QPainter>
#include <QMouseEvent>
MyButton::MyButton(QWidget *parent) : QWidget(parent)
{
    _pressed = false;
    this->setGeometry(_rect);

}
MyButton::MyButton(const QString& text,QWidget *parent):
    QWidget(parent),_rect(0,0,100,30),_text(text)
{
    _pressed = false;
    this->setGeometry(_rect);
}
void MyButton::mousePressEvent(QMouseEvent *event)
{
    _pressed = true;
    update();
}
void MyButton::mouseReleaseEvent(QMouseEvent *event)
{
    _pressed = false;
    update();
    if(_rect.contains(event->pos()))
        emit clicked();
}
void MyButton::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    if( _pressed == true)
        p.setBrush((Qt::darkYellow));
    else
        p.setBrush(Qt::darkGray);
    p.drawRect(_rect);
    p.drawText(_rect,_text,QTextOption(Qt::AlignCenter));
}
