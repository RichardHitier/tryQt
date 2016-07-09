#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QThread>
#include <QString>
#include <QProcess>
#include <QTimer>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::pingProcess(QString host)
{
    QProcess *pingprocess = new QProcess();
    QString exec = "ping";
    int status;

    qDebug()<<"About to ping "<<host;

    #if defined(win32)
    QString parameter="-n 1";
    #else
    QString parameter="-c 1";
    #endif
    //    pingprocess->closereadchannel(qprocess::standardoutput);
    //    pingprocess->closereadchannel(qprocess::standarderror);

    status = pingprocess->execute(exec, QStringList() << parameter << host);
    //    pingprocess->setreadchannel(qprocess::standardoutput);
    //    pingprocess->setreadchannel(qprocess::standarderror);
    qDebug()<<"pingstatus: "<<status;
    pingprocess->close();

}

void MainWindow::on_pingBtn_clicked()
{
    QPushButton *btn = qobject_cast<QPushButton *>(sender());
    btn->setEnabled(false);

    pingProcess(ui->hostEdit->text());

    btn->setEnabled(true);
}
