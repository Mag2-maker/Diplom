#include "mainwindow.h"
#include "windowcontroller.h"
#include <QApplication>
#include <menu.h>
#include <QMenu>
#include <QMenuBar>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //a.setQuitOnLastWindowClosed(false);
    MainWindow w;
    WindowController controller(&w);//контроллер
    //MainWindow *window = new MainWindow();
    w.show();
   // w.showMaximized();


    return a.exec();
}
