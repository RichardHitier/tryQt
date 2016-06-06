#include "er.h"

#include <iostream>

using namespace std;



Emetteur::Emetteur(){
    cout<<"C'est moi l'emetteur"<<endl;
}
void Emetteur::changer(int val){
    cout<<"abouit to change m_val"<<endl;
    m_val = val;
    cout<<"abouit to emit bang"<<endl;
    emit bang();
}
int Emetteur::val()
{
    return m_val;
}


Receveur::Receveur(){
    cout<<"c'est moi le receveur"<<endl;
}
void Receveur::explose(){
    cout<<"j'explose !!!!"<<endl;
}
