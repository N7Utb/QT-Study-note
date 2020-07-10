#ifndef TCPSERVE_H
#define TCPSERVE_H

#include <QObject>
#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTextBrowser>
#include <QHBoxLayout>
#include <QNetworkInterface>
#include <QMessageBox>
class TcpServe : public QWidget
{
    Q_OBJECT
public:
    explicit TcpServe(QWidget *parent = nullptr);
    QTcpServer* _server;
    QTcpSocket* _socket;
    QTextBrowser* _show;
signals:
public slots:
    void slotNetConnection();
    void slotreadyread();
};

#endif // TCPSERVE_H
