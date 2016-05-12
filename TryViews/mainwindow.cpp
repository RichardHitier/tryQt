#include <iostream>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QGraphicsScene *scene = new QGraphicsScene(0, 0, 3500, 4500, this);

    QPen pen (Qt::black, 10);
    QBrush brush (Qt::red);

    ui->setupUi(this);
    ui->graphicsView->setScene( scene );
    ui->graphicsView->rotate(180);
    ui->graphicsView->scale(0.1, 0.1);

    //ui->xSlider->setValue(100);
    //ui->ySlider->setValue(100);

    ei->setBrush(brush);
    ei->setPen(pen);
    scene->addItem(ei);
    ui->graphicsView->show();

    ei->setFlag(QGraphicsItem::ItemIsSelectable);
    ei->setFlag(QGraphicsItem::ItemIsMovable);
    ei->setFlag(QGraphicsItem::ItemSendsGeometryChanges);

    ei->setAcceptDrops(true);

//    connect(ui->xScrollBar, SIGNAL(valueChanged(int)), this, SLOT(moveEi(int)));
//    connect(ui->yScrollBar, SIGNAL(valueChanged(int)), this, SLOT(moveEi(int)));
    connect(ui->xSlider, SIGNAL(sliderMoved(int)), this, SLOT(moveEi(int)));
    connect(ui->ySlider, SIGNAL(sliderMoved(int)), this, SLOT(moveEi(int)));

    //connect(scene, SIGNAL(focusItemChanged(QGraphicsItem*,QGraphicsItem*,Qt::FocusReason)), this, SLOT(show()))));

    connect(ui->pushButton, SIGNAL(pressed()), this, SLOT(showpressed()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showpressed()
{
    std::cout<<ei->pos().x()<<QString(":").toStdString()<<ei->pos().y()<<std::endl;
}

void MainWindow::moveEi(int)
{
//    std::cout<<"HEY ! moving "<<sender()->objectName().toStdString();//<<QString(slider->value).toStdString()<<std::endl;
    QSlider *slider = qobject_cast<QSlider *>(QObject::sender());
    std::cout<<"HEY ! moving "<<slider->objectName().toStdString()<<slider->value()<<std::endl;//<<QString(slider->value).toStdString()<<std::endl;
    ei->setPos(ui->xSlider->value(), ui->ySlider->value());
 //   ui->graphicsView->show();
}
