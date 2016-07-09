#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QThread>
#include <QMainWindow>

namespace Ui {
class MainWindow;
class PingThread;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pingBtn_clicked();

private:
    Ui::MainWindow *ui;
    void pingProcess(QString host);
};

class PingThread : public QThread
{
    Q_OBJECT

private:
    void run();
};

#endif // MAINWINDOW_H
