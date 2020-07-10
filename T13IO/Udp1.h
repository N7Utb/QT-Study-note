#ifndef UDP1_H
#define UDP1_H

#include <QWidget>
#include <QUdpSocket>
#include <QDebug>
#include <QTimer>
#include <QDateTime>
class Udp1 : public QWidget
{
    Q_OBJECT
public:
    explicit Udp1(QWidget *parent = nullptr);
    QUdpSocket* _udp;
signals:

public slots:
    void slotreadyread();
    void slottimeout();
};

#endif // UDP1_H
