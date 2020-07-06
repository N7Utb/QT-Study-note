#include "MyWidget.h"
#include <QApplication>
#include <QVBoxLayout>
#include <QGraphicsPixmapItem>
#include <QGraphicsItemAnimation>
#include <QTimeLine>
#include <QMouseEvent>
#include <QDebug>
#include <QPrintPreviewDialog>
#include <QPrintDialog>

MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
    //QVBoxLayout* lay = new QVBoxLayout(this);
    _view = new QGraphicsView(this);
    QGraphicsLineItem* lineItem;
    QGraphicsTextItem* textItem;
    QGraphicsPixmapItem* pixmapItem;

    _view->setScene(_scene = new QGraphicsScene);


    //lay->addWidget(_view);
    _scene->addItem(lineItem = new QGraphicsLineItem(QLineF(QPointF(0,0),QPointF(100,100))));
    _scene->addItem(textItem = new QGraphicsTextItem("Hello World"));
    _scene->addItem(pixmapItem = new QGraphicsPixmapItem(QPixmap("../abc.png")));

    //_view->setBackgroundBrush(Qt::red);
    textItem->setPos(QPointF(200,300));
    textItem->setFont(QFont("aaa",50,700,true));
    textItem->setDefaultTextColor(Qt::darkGray);

    QTransform trans;
    trans.rotate(30);
    textItem->setTransform(trans);
    pixmapItem->setPos(100,100);

    //Animation
    QGraphicsItemAnimation* animation = new QGraphicsItemAnimation;
    animation->setItem(pixmapItem);

    QTimeLine* timeline = new QTimeLine(3000);
    timeline->setLoopCount(2);
    animation->setTimeLine(timeline);
    animation->setTranslationAt(1,200,200);
    timeline->start();
}
void MyWidget::resizeEvent(QResizeEvent *event)
{
    //set the size of _view = MyWidget::size
    _view->setGeometry(QRect(QPoint(0,0),size()));
}
void MyWidget::paintEvent(QPaintEvent *event)
{
}
void MyWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::RightButton)
    {
#if 0
        //save the viem
        QPixmap pixmap(size());
        QPainter painter(&pixmap);
        painter.fillRect(QRectF(),Qt::white);
        _scene->render(&painter);
        pixmap.save("../bbb.png");
#endif
        QPrintPreviewDialog dlg;
        connect(&dlg,SIGNAL(paintRequested(QPrinter*)),this,SLOT(slotPaintRequested(QPrinter*)));
        dlg.exec();
    }
}
void MyWidget::slotPaintRequested(QPrinter* printer)
{
    QPainter painter(printer);
    this->render(&painter);
}
int main(int argc,char* argv[])
{
    QApplication app(argc,argv);

    MyWidget w;
    w.show();

    return app.exec();
}
