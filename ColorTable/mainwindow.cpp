#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QGraphicsTextItem>
#include <QThread>

#define NBCOLORS 255

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    makeColorTable();
    initUi();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::initUi()
{
    initColorTable();
    addRectList();
}

void MainWindow::initColorTable()
{
    m_scene = new QGraphicsScene(this);
    m_scene->setSceneRect(0,0,10,NBCOLORS);
    ui->graphicsView->setScene(m_scene);
    QPen mypen (Qt::black);
    mypen.setWidth(1);
    QBrush mybrush (Qt::transparent);
    //m_scene->addRect(0,0,10,NBCOLORS, mypen, mybrush);
    //ui->graphicsView->fitInView(m_scene->sceneRect(), Qt::KeepAspectRatio);
    qreal xscale = ui->graphicsView->width()/(qreal)m_scene->sceneRect().width()-0.2;
    qreal yscale = ui->graphicsView->height()/(qreal)m_scene->sceneRect().height()-0.2;
    ui->graphicsView->scale(xscale, yscale);
}

void MainWindow::fillBitMapRand()
{
    m_sceneBitMap = new QGraphicsScene(this);
    qreal sceneW = ui->graphicsView_2->width()-10;
    qreal sceneH =ui->graphicsView_2->height()-10;
    m_sceneBitMap->setSceneRect(0,0,sceneW,sceneH );
    ui->graphicsView_2->setScene(m_sceneBitMap);
    for( int x=0; x<sceneW/10;x++)
    {
        for( int y=0; y<sceneH/10;y++ )
        {
            int max = ui->maxSpinBox->value();
            QColor pxColor = countColor(randInt(0,max), max);
            m_sceneBitMap->addRect(x*10,y*10,10,10, QPen(Qt::black), QBrush(pxColor));
            //QThread::msleep(2);
            //QApplication::processEvents();
        }
    }
}

int MainWindow::randInt(int low, int high)
{
    // Random number between low and high
    return qrand() % ((high + 1) - low) + low;
}


/*
 * draws the color table
 */
void MainWindow::addRectList()
{
    for( int i=0; i<NBCOLORS; i++)
    {
        m_scene->addRect(0,i,3,10, QPen(Qt::transparent), countColor(i, NBCOLORS));
        // now draw tics
        int tic = i%10;
        if( tic == 0)
        {
            QGraphicsTextItem *text = m_scene->addText(QString::number(i), QFont("Arial",3));
            text->setPos(-1,i-5);
        }
    }
}

/*
 * build color table
 */
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
        m_colorList.append(QColor(b,g,r));
    }
}

/*
 * return a color from int value
 */
QColor MainWindow::countColor(int count, int maxValue)
{
    // cut to top
    count = count > maxValue ?  maxValue : count;

    // normalize to max
    count = (count * NBCOLORS) / maxValue;

    return m_colorList.at(count);
}

void MainWindow::on_pushButton_clicked()
{
   fillBitMapRand();
}
