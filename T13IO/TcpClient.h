#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QPushButton>
class TcpClient : public QWidget
{
    Q_OBJECT
public:
    explicit TcpClient(QWidget *parent = nullptr);
    QTcpSocket* _socket;
    QLineEdit* _lineEdit;
signals:
public slots:
    void slotButtonClick();

};

#endif // TCPCLIENT_H
