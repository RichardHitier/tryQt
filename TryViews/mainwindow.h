#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsEllipseItem>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsEllipseItem *ei= new QGraphicsEllipseItem(0,0, 50,50);

protected slots:
    void moveEi(int);
    void showpressed();
};

#endif // MAINWINDOW_H
