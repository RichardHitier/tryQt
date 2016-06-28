#include "mainwindow.h"
#include "ui_mainwindow.h"

#define NBROWS 10
#define NBCOLS 3

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    drawMatrix(NBROWS, NBCOLS);
}

void MainWindow::drawMatrix(int nbrows, int nbcols)
{

    ui->label->resize(160, ui->label->height());
    ui->label->setText(QString("Matrix: %1 x %2").arg(nbrows).arg(nbcols));
    for( int i =0 ; i<nbrows; i++)
    {
        for( int j=0; j<nbcols; j++)
        {
            QLabel *label=new QLabel( QString("(%1, %2)").arg(i).arg(j) );
            ui->gridLayout->addWidget(label, i, j);
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
