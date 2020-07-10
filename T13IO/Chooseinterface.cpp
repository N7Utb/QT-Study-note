#include "Chooseinterface.h"

Chooseinterface::Chooseinterface(QWidget *parent) : QDialog(parent)
{
    /* get all interface */
    QList<QHostAddress> addrlist = QNetworkInterface::allAddresses();
#if 0
    QList<QNetworkInterface> inflist = QNetworkInterface::allInterfaces();
    QList<QNetworkAddressEntry> entrylist = inflist.at(0).addressEntries() ;
    entrylist.at(0).broadcast()
#endif

    _combobox = new QComboBox;
    _layout = new QVBoxLayout(this);
    _layout->addWidget(_combobox);
    foreach(QHostAddress addr,addrlist)
    {
        quint32 ipaddr = addr.toIPv4Address();
        if(ipaddr == 0)
            continue;
        _combobox->addItem(QHostAddress(ipaddr).toString());
    }
    connect(_combobox,SIGNAL(currentIndexChanged(QString)),this,SLOT(slotcomboboxchanged(QString)));
}
void Chooseinterface::slotcomboboxchanged(QString str)
{
    this->_str = str;
}
