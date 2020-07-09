#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QWidget>
#include <QDialog>
#include <QPainter>

class MyDialog : public QDialog
{
    Q_OBJECT
public:
    explicit MyDialog(QWidget *parent = nullptr);
    QString _strdir;
    void paintEvent(QPaintEvent*);

signals:

public slots:
    void slotButtonClicked();
};

#endif // MYDIALOG_H
