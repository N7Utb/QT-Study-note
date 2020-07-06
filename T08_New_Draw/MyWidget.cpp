#include "MyWidget.h"
#include <QApplication>
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
    button = new MyButton("Mybutton",this);
    connect(button,SIGNAL(clicked()),this,SLOT(slotButtonClicked()));
    button->setGeometry(30,30,100,30);
}
void MyWidget::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    ;
    p.setRenderHint(QPainter::Antialiasing);
    for(int i=0;i<this->_line.size();++i)
    {
        const QVector<QPoint>& line = _line.at(i);
        for(int j=0;j<line.size()-1;++j)
        {
            p.drawLine(line.at(j),line.at(j+1));
        }
    }
}
void MyWidget::slotButtonClicked()
{
    qDebug() << "button is clicked";
}
void MyWidget::mouseMoveEvent(QMouseEvent *event)
{
    if(_line.size() == 0)
    {
        QVector<QPoint> line;
        _line.append(line);
    }
    QVector<QPoint>& lastline = _line.last();
    lastline.append(event->pos());
    update();
}
void MyWidget::mousePressEvent(QMouseEvent *event)
{
    QVector<QPoint> line;
    _line.append(line);
    QVector<QPoint>& lastline = _line.last();
    lastline.append(event->pos());
}
void MyWidget::mouseReleaseEvent(QMouseEvent *event)
{
    QVector<QPoint>& lastline = _line.last();

}
int main(int argc,char* argv[])
{
    QApplication app(argc,argv);

    MyWidget w;
    w.show();
    return app.exec();
}
