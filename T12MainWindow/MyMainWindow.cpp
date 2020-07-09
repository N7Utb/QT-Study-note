#include "MyMainWindow.h"


MyMainWindow::MyMainWindow(QWidget *parent) : QMainWindow(parent)
{
    QMenuBar* pmenubar = menuBar();
    QMenu* pmenu = pmenubar->addMenu("&File");
    _menu = pmenu;
    QAction* OpenAction = pmenu->addAction("&Open",this,SLOT(slotFileOpen()),QKeySequence::Open);
    QAction* SaveAction = pmenu->addAction("&Save",this,SLOT(slotFileOpen()),QKeySequence::Save);
    QAction* CloseAction = pmenu->addAction("&Exit",this,SLOT(close()),QKeySequence::Close);
    CloseAction->setToolTip("close window");
    QToolBar* toolBar = this->addToolBar("My toolBar");
    toolBar->addAction(OpenAction);
    toolBar->addAction(SaveAction);
    toolBar->addAction(CloseAction);

    QStatusBar* pStatusBar = this->statusBar();
    pStatusBar->addWidget(_label = new QLabel("OK"));

    _view = new MyView;
    /* 别的控件占用了之后，剩下的区域都是CentralWidget的 */
    this->setCentralWidget(_view);
}
void MyMainWindow::slotFileOpen()
{
    QString strFile = QFileDialog::getOpenFileName();
    qDebug() << "Open file is " << strFile;
}
void MyMainWindow::mousePressEvent(QMouseEvent * event)
{
    _menu->exec(QCursor::pos());
}
void MyMainWindow::paintEvent(QPaintEvent *)
{
    //QPainter p(this);
    //p.drawPixmap(QPoint(0,0),QPixmap("../abc.png"));
}
int main(int argc,char* argv[])
{
    QApplication app(argc,argv);
    
    MyMainWindow w;
    w.show();
    
    return app.exec();
}
