#include "mainwindow.h"
#include <QApplication>
#include <menu.h>
#include <QMenu>
#include <QMenuBar>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.showMaximized();


    return a.exec();
}
