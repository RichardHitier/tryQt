#include <iostream>
#include "er.h"
#include "fm.h"
#include <QObject>


using namespace std;



int main()
{
    cout << "Hello World!" << endl;
    Emetteur *e = new Emetteur();
    Fils *fils = new Fils();
    fils->setEmetteur(e);
    e->changer(10);


    return 0;
}
