#include <QApplication>
#include <QPushButton>
#include "mainwindow.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    //QPushButton hello("Hello world!");
    //hello.resize(100,30);
    //hello.show();

    MainWindow mainWin;
    mainWin.show();
    return app.exec();
}
