#ifndef ABSTRACTLISTENER_H
#define ABSTRACTLISTENER_H

#include "er.h"

class AbstractListener
{
    Emetteur *m_em;

public:
    AbstractListener();
    AbstractListener(Emetteur *);
    void setEmetteur(Emetteur *);
    virtual void bangArrived(){}
};

#endif // ABSTRACTLISTENER_H
