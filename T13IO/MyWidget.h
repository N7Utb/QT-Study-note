#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QFile>
#include <QApplication>
#include <QIODevice>
#include <QDebug>
#include <QBuffer>
#include <QPixmap>
#include <QLabel>
#include <QTextStream>
#include <QDataStream>
#include <QHBoxLayout>
#include <TcpClient.h>
#include <TcpServe.h>
#include <Udp1.h>
#include <Udp2.h>
/* QFile
 * QBuffer
 * QTcpSocket
 * QUdpSocked
 *
 * QDataStream
 * QTextStream
*/
class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = nullptr);

signals:

};

#endif // MYWIDGET_H
