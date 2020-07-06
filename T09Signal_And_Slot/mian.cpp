#include <QCoreApplication>
#include "MySignal.h"
#include "MySlot.h"
int main(int argc,char* argv[])
{
    QCoreApplication app(argc,argv);

    MySignal signal;
    MySlot slot;

    QObject::connect(&signal,SIGNAL(sig()),&slot,SLOT(slot()));

    emit signal.sig();
    return app.exec();
}
