#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "er.h"
#include "abstractlistener.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public AbstractListener
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
