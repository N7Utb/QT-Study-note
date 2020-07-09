#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QAction>
#include <QFileDialog>
#include <QDebug>
#include <QStatusBar>
#include <QLabel>
#include <QPaintEvent>
#include <QPainter>
#include <QPixmap>
#include "MyView.h"
#include <QMouseEvent>
#include <QCursor>
class MyMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MyMainWindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent* );
    QLabel* _label;
    MyView* _view;
    QMenu* _menu;
    void mousePressEvent(QMouseEvent*);

signals:

public slots:
    void slotFileOpen();
};

#endif // MYMAINWINDOW_H
