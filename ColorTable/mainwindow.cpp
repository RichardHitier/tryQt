#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
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
    m_sceneW = ui->graphicsView_2->width()*0.99;
    m_sceneH =ui->graphicsView_2->height()*0.99;
    if( NULL == m_sceneBitMap)
    {
        m_sceneBitMap = new BitMapScene();
        m_sceneBitMap->setSceneRect(0,0,m_sceneW,m_sceneH );
        ui->graphicsView_2->setScene(m_sceneBitMap);
    }

    initColorTable();
    addRectList();

    connect(m_sceneBitMap, SIGNAL(countPosition(int,int,int)), this, SLOT(gotCountPos(int,int,int)));
}

void MainWindow::gotCountPos(int x, int y, int count)
{
    ui->xLabel->setText(QString::number(x));
    ui->yLabel->setText(QString::number(y));
    ui->countLabel->setText(QString::number(count));
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

void MainWindow::cleanBitMap()
{
   int i;
   int sceneItems = m_sceneBitMap->items().size();
   for( i=0; i<sceneItems; i++)
   {
       m_sceneBitMap->removeItem(m_pxList.at(i));
   }
   int pxListItems = m_pxList.size();
   for( i=0; i<pxListItems; i++)
   {
       delete(m_pxList.at(0));
       m_pxList.removeAt(0);
   }
}

void MainWindow::fillBitMapRand()
{
    int i=0;
    int pxW=ui->pxWidthSpinBox->value();

    for( int x=0; x<m_sceneW/pxW;x++)
    {
        for( int y=0; y<m_sceneH/pxW;y++ )
        {
            i++;
            int max = ui->maxSpinBox->value();
            int count = randInt(0,max);
            QColor pxColor = countColor(count, max);
            PxItem *px = (PxItem *)m_sceneBitMap->addRect(x*pxW,y*pxW,pxW,pxW, QPen(Qt::transparent), QBrush(pxColor));
            px->setCount(count);
            m_pxList.append(px);
        }
    }
    qDebug()<<"Filled "<<i<<" items";
}

int MainWindow::randInt(int low, int high)
{
    // Random number between low and high
    return qrand() % ((high + 1) - low) + low;
}

void MainWindow::recolor()
{
    for( int i=0; i<m_pxList.size(); i++)
    {
        int count = ( m_pxList.at(i) )->count();
        int max = ui->maxSpinBox->value();
        QColor pxcolor = countColor(count, max);
        ( m_pxList.at(i) )->setBrush(QBrush(pxcolor) );
    }
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
    count = (count * ( NBCOLORS -1)) / maxValue;


    return m_colorList.at(count);
}

void MainWindow::on_pushButton_clicked()
{
    cleanBitMap();
    fillBitMapRand();
}

void MainWindow::on_pushButton_3_clicked()
{
   cleanBitMap();
}

void MainWindow::on_pushButton_2_clicked()
{
  recolor();
}

void MainWindow::on_maxSpinBox_valueChanged(int arg1)
{
   recolor();
}

void BitMapScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
  QGraphicsScene::mousePressEvent(mouseEvent); //Call the ancestor

    int x = mouseEvent->scenePos().x();
    int y = mouseEvent->scenePos().y();

  QGraphicsItem *item;
   item = itemAt(mouseEvent->scenePos(), QTransform()); //Get the item at the position
   if (item) //If there is an item at that position
   {
     emit countPosition(x, y, ((PxItem *)item)->count());
   }
}


PxItem::PxItem(){
    setAcceptHoverEvents(true);
}


void PxItem::setCount(int count){
    m_count = count;
}

void MainWindow::on_stepSpinBox_valueChanged(int arg1)
{

    ui->maxSpinBox->setSingleStep( ui->stepSpinBox->value() );
}
