#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QObject>
#include <QWidget>
#include <QPushButton>

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = nullptr);
    bool eventFilter(QObject*, QEvent*);
    QPushButton* _button;

signals:

};

#endif // MYWIDGET_H
