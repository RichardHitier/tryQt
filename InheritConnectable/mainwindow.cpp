#include "mainwindow.h"
#include "ui_mainwindow.h"
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

void MainWindow::listenBang()
{
    connect(m_em, SIGNAL(bang()), this, SLOT(onBang()) );
}


void MainWindow::onBang()
{
    qDebug()<<"received bang";

}


void MainWindow::on_pushButton_clicked()
{
   m_em->changer(10);
}
