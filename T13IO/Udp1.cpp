#include "Udp1.h"

Udp1::Udp1(QWidget *parent) : QWidget(parent)
{
    _udp = new QUdpSocket;
    _udp->bind(10001);

    connect(_udp,SIGNAL(readyRead()),this,SLOT(slotreadyread()));
    QTimer* timer = new QTimer;
    timer->setInterval(1000);
    timer->start();
    connect(timer,SIGNAL(timeout()),this,SLOT(slottimeout()));

}
void Udp1::slotreadyread()
{
    while(_udp->hasPendingDatagrams())
    {
        quint32 datagramsize = _udp->pendingDatagramSize();
        QByteArray buf(datagramsize,0);
        _udp->readDatagram(buf.data(),datagramsize);
        qDebug() << buf;
    }
}
void Udp1::slottimeout()
{
    quint64 timestamp = QDateTime::currentMSecsSinceEpoch();
    QString str = QString::number(timestamp);
    _udp->writeDatagram(str.toUtf8(),QHostAddress("127.0.0.1"),10002);

}
