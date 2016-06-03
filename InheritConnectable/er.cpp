#include "er.h"

#include <iostream>

using namespace std;



Emetteur::Emetteur(){
    cout<<"C'est moi l'emetteur"<<endl;
}
void Emetteur::changer(int val){
    m_val = val;
    emit bang();
}


Receveur::Receveur(){
    cout<<"c'est moi le receveur"<<endl;
}
void Receveur::explose(){
    cout<<"j'explose !!!!"<<endl;
}
