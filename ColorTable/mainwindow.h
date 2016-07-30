#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QColor>
#include <QList>

namespace Ui {
class MainWindow;
}

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
    QGraphicsScene *m_sceneBitMap ;
    QGraphicsScene *m_scene ;
    QList<QColor> m_colorList;
    QList<QGraphicsRectItem *> m_pxList;
    QList<int> m_countList;
    void initUi();
    void initColorTable();
    void fillBitMapRand();
    void cleanBitMap();
    void addRectList();
    void makeColorTable();
    int randInt(int,int);
    void recolor();
    QColor  countColor(int, int);
};

#endif // MAINWINDOW_H