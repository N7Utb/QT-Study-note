#include "MyDialog.h"
#include <QApplication>
#include <QPushButton>
#include <QFileDialog>
#include <QFileInfo>
#include <QColorDialog>
#include <QFontDialog>
#include <QMessageBox>

MyDialog::MyDialog(QWidget *parent) : QDialog(parent)
{
    QPushButton* button =new QPushButton("clicked me",this);
    connect(button,SIGNAL(clicked()),this,SLOT(slotButtonClicked()));

}
void MyDialog::slotButtonClicked()
{
#if 0
    QDialog* dlg = new QDialog();
    int rec;
    dlg->show();

    QString strFilename = QFileDialog::getSaveFileName(NULL,"Select file for save",_strdir,"Png file (*.png)");
    QFileInfo fileInFo(strFilename);
    _strdir = fileInFo.filePath();

    QColorDialog color;
    color.exec();

    QFontDialog font;
    font.exec();
#endif

    QMessageBox::warning(this,"warning","Hello idiots");
}
void MyDialog::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.drawLine(QLine(0,0,200,200));
}
int main(int argc,char* argv[])
{
    QApplication app(argc,argv);
    MyDialog dig;
    dig.show();

    return app.exec();
}
