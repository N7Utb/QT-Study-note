#include "MyWidget.h"


MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
#if 0
    QFile file("../MyTest.txt");

    file.open(QIODevice::ReadWrite);
    file.write("abc",4);
    file.close();
#endif
#if 0
    QByteArray ba("asds");
    QString str("asds");
    qDebug()<<ba.size()<<str.size();
#endif
#if 0
    QBuffer buffer;
    buffer.open(QIODevice::ReadWrite);
    buffer.write("abc");
    buffer.write("aabbcc");

    buffer.close();

    qDebug() << buffer.buffer();
#endif
#if 0
    QBuffer buffer;
    buffer.open(QIODevice::ReadWrite);
    QPixmap pixmap("../abc.png");
    pixmap.save(&buffer,"PNG");
    buffer.close();

    QPixmap pixmap2;
    pixmap2.loadFromData(buffer.buffer());
    QLabel* label = new QLabel(this);
    label->setPixmap(pixmap2);
#endif
#if 0
    QFile file("../textstream.txt");
    file.open(QIODevice::ReadWrite);

    QTextStream textstream(file);
    textstream << 1 << "abc" << 1.2;
    file.close();
#endif
#if 0

    QFile file("../datastream.txt");
    file.open(QIODevice::ReadWrite);

    QDataStream datastream(&file);
    datastream << 1 << "abc" << 1.2;
    file.close();
#endif
    QFile file("../map.data");
    file.open(QIODevice::ReadWrite);
    file.seek(65535);
    file.write("1");
    file.close();
    file.open(QIODevice::ReadWrite);
    uchar* ptr = file.map(0,64*1024);
    *ptr = 'a';
    ptr[1] = 'b';
    file.unmap(ptr);
    file.close();

}

int main(int argc,char* argv[])
{
    QApplication app(argc,argv);
#if 0
    TcpServe s;
    s.show();
    TcpClient c;
    c.show();
    s.setWindowTitle("server");
    c.setWindowTitle("Client");
#endif
    Udp1 udp1;
    udp1.show();
    Udp2 udp2;
    udp2.show();
    udp1.setWindowTitle("udp1");
    udp2.setWindowTitle("udp2");
    app.exec();
}
