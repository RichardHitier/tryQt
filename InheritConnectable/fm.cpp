#include "fm.h"
#include <iostream>
#include <QObject>

using namespace std;

Maman::Maman(int a){
    init(a);
}

Maman::Maman(){
    init(0);
    cout<<"construit dans la maman"<<endl;
}

void Maman::init(int a){
    m_a=a;
    setEmetteur(new Emetteur());
    cout<<"maman initialise a "<<m_a<<endl;
}

void Maman::show(){
    cout<<"maman montre: "<<m_a<<endl;
}

void  Maman::exploded(){
    cout <<"explode"<<endl;
    show();
}

void Maman::setEmetteur(Emetteur *e)
{
    m_e=e;
    QObject::connect(m_e, SIGNAL(bang()), this, SLOT(exploded()) );
}


Fils::Fils(int a): Maman(a) {
}

Fils::Fils(){
    cout<<"construit dans le fils"<<endl;
}

void Fils::show(){
    Maman::show();
    cout<<"je surcouche le show() dans le fis"<<endl;
}
