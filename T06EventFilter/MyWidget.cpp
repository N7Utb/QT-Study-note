#include "MyWidget.h"
#include <QPushButton>
#include <QEvent>
#include <QDebug>
MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
    QPushButton* button;
    button = new QPushButton("This Button",this);
    connect(button,SIGNAL(clicked()),this,SLOT(close()));
    /* button 给自己安装了一个消息过滤器，经过button的消息，都先要调用过滤器的eventFilter函数*/
    button->installEventFilter(this);
    _button=button;
}
bool MyWidget::eventFilter(QObject *o, QEvent *e)
{
    if( o == _button && e->type() == QEvent::MouseButtonRelease)
    {
        return true;
    }
    return QWidget::eventFilter(o,e);
}
#include<QApplication>
bool QApplication::notify(QObject * o, QEvent *e)
{
    QWidget* mainWnd = this ->topLevelWidgets().at(0);
    if(o == (QObject*)mainWnd && e->type() == QEvent::MouseButtonPress)
    {
        qDebug() << "mainwnd is clicked";
    }
    return QApplication::notify(o, e);
}
int main(int argc,char* argv[])
{
    QApplication app(argc,argv);


    MyWidget w;
    w.show();

    return app.exec();
}
