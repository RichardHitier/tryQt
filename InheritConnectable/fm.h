#ifndef FM_H
#define FM_H

#include <QObject>

#include "er.h"

class  Maman : public QObject
{
    Q_OBJECT

    int m_a=0;
    Emetteur *m_e;
public:
    Maman(int a);
    Maman();
    void init(int a);
    void showInt();
    void setEmetteur(Emetteur *);
public    slots:
    void  exploded();
};



class Fils : public Maman
{
public:
    Fils(int a);

    Fils();
    void showInt();
};

#endif // FM_H
