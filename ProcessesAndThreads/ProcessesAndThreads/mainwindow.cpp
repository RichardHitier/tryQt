#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QThread>
#include <QString>
#include <QProcess>
#include <QTimer>
#include <QDebug>
#include <QEventLoop>



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


void MainWindow::on_pingBtn_clicked()
{
    QEventLoop qel;
    //QTimer tT;
    PingThread pt(ui->hostEdit->text());

    // disable ui
    QPushButton *btn = qobject_cast<QPushButton *>(sender());
    btn->setEnabled(false);

    //tT.setSingleShot(true);
    //connect(&tT, SIGNAL(timeout()), &qel, SLOT(quit()));

    connect( &pt, SIGNAL(finished()), &qel, SLOT(quit()));

    pt.start(); // start ping process

    qel.exec(); // wait here for pt.finished signal

    //pt.wait();


    // reenable ui
    btn->setEnabled(true);
}


PingThread::PingThread(QString host)
{
    setHost(host);
}

void PingThread::setHost(QString host)
{

    m_host = host.isEmpty() ? "google.com": host;
}

void PingThread::run()
{
    qDebug()<<"Yes I run";
    pingProcess(m_host);
    qDebug()<<"Ok i leave";

}

void PingThread::pingProcess(QString host)
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
