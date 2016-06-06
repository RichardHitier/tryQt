#include <iostream>

#include <QApplication>
#include <QObject>

#include "er.h"
#include "fm.h"
#include  "mainwindow.h"


using namespace std;



int main(int argc, char **argv)
{
   QApplication a(argc, argv);

   //cout << "Hello World!" << endl;
   Emetteur *e = new Emetteur();
   //Fils *fils = new Fils();
   //fils->setEmetteur(e);
   //e->changer(10);

    MainWindow w;
    w.setEmetteur(e);

    w.show();
    return a.exec();

}
