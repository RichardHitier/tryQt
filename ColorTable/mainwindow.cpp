#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

#define NBCOLORS 255

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    makeColorTable();
    initUi();
    addRectList();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::initUi()
{
    m_scene = new QGraphicsScene(this);
    m_scene->setSceneRect(0,0,10,NBCOLORS);
    ui->graphicsView->setScene(m_scene);
    QPen mypen (Qt::black);
    mypen.setWidth(1);
    QBrush mybrush (Qt::transparent);
    m_scene->addRect(0,0,10,NBCOLORS, mypen, mybrush);
    //ui->graphicsView->fitInView(m_scene->sceneRect(), Qt::KeepAspectRatio);
    qreal xscale = ui->graphicsView->width()/(qreal)m_scene->sceneRect().width()-0.2;
    qreal yscale = ui->graphicsView->height()/(qreal)m_scene->sceneRect().height()-0.2;
    ui->graphicsView->scale(xscale, yscale);
}

void MainWindow::addRectList()
{
    for( int i=0; i<NBCOLORS; i++)
    {
        m_scene->addRect(0,i,10,10, QPen(Qt::transparent), countColor(i));
    }
}

void MainWindow::makeColorTable()
{
    int r=256;
    int g=0;
    int b=0;
    for( int i=0; i<NBCOLORS; i++)
    {
        int step = (255/NBCOLORS)*2;
        if(r>0)
        {
            r-=step;
            g+=step;
        }else if(g>0)
        {
            g-=step;
            b+=step;
        }
        r=(r==256 )?255:r;
        g=(g==256 )?255:g;
        b=(b==256 )?255:b;
        qDebug()<<"Step: "<<step<<" r: "<<r<<" g:"<<g<<" b:"<<b;
        m_colorList.append(QColor(r,g,b));
    }
}

QColor MainWindow::countColor(int index)
{
    return m_colorList.at(index);
}
