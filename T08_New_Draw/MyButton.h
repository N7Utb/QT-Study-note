#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QObject>
#include <QWidget>

class MyButton : public QWidget
{
    Q_OBJECT
public:
    explicit MyButton(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    QRect _rect;
    QString _text;
    bool _pressed;
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    //virtual void clicked();
    MyButton(const QString& text,QWidget* parent = 0);
signals:
       void clicked();
};

#endif // MYBUTTON_H
