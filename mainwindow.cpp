#include <QtGui>
#include <QPushButton>
#include "mainwindow.h"

MainWindow::MainWindow()
{
    QPushButton hello("Hello world!");
    hello.resize(100,30);
    hello.show();
}
