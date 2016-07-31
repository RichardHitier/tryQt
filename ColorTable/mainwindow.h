#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QColor>
#include <QList>
#include <QGraphicsSceneHoverEvent>
#include <QGraphicsRectItem>

namespace Ui {
class MainWindow;
class BitMapScene;
class PxItem;
}

class BitMapScene : public QGraphicsScene
{
public:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
};

class PxItem : public QGraphicsRectItem
{
public:
    int m_count=0;
    PxItem();
    void setCount(int);
    int count(){return m_count;}
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_maxSpinBox_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
    BitMapScene *m_sceneBitMap = NULL;
    QGraphicsScene *m_scene = NULL;
    QList<QColor> m_colorList;
    QList<PxItem *> m_pxList;
    qreal m_sceneW;
    qreal m_sceneH;
    void initUi();
    void initColorTable();
    void fillBitMapRand();
    void cleanBitMap();
    void addRectList();
    void makeColorTable();
    int randInt(int,int);
    void recolor();
    QColor  countColor(int, int);
    void mousePressEvent(QGraphicsSceneHoverEvent *);
};
#endif // MAINWINDOW_H
