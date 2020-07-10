#ifndef CHOOSEINTERFACE_H
#define CHOOSEINTERFACE_H

#include <QWidget>
#include <QDialog>
#include <QNetworkInterface>
#include <QComboBox>
#include <QVBoxLayout>
class Chooseinterface : public QDialog
{
    Q_OBJECT
public:
    explicit Chooseinterface(QWidget *parent = nullptr);
    QComboBox* _combobox;
    QVBoxLayout* _layout;
    QString _str;
signals:

public slots:
    void slotcomboboxchanged(QString);

};

#endif // CHOOSEINTERFACE_H
