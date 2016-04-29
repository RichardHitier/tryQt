#include <QtGui>
#include <QPushButton>
#include "mainwindow.h"
#include <iostream>

MainWindow::MainWindow()
{
    QPushButton hello("Hello world!");
    hello.resize(100,30);
    hello.show();
}

void MainWindow::doit()
{

    std::cout<<"doingin it"<<std::endl;
}
