#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "mother.h"

class MainWindow :  public QWidget, public Mother
{
    Q_OBJECT

public:
    MainWindow();

};

#endif
