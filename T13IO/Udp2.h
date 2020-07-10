#ifndef UDP2_H
#define UDP2_H

#include <QWidget>
#include <QUdpSocket>
#include <QDebug>
#include <QTimer>
#include <QDateTime>
class Udp2 : public QWidget
{
    Q_OBJECT
public:
    explicit Udp2(QWidget *parent = nullptr);
    QUdpSocket* _udp;

signals:
public slots:
    void slotreadyread();
    void slottimeout();

};

#endif // UDP2_H
