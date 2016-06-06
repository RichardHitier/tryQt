#ifndef ABSTRACTLISTENER_H
#define ABSTRACTLISTENER_H

#include "er.h"

class AbstractListener
{

public:
    AbstractListener();
    AbstractListener(Emetteur *);
    void setEmetteur(Emetteur *);
    virtual void bangArrived(){}
    virtual void listenBang(){}

    Emetteur *m_em;
};

#endif // ABSTRACTLISTENER_H
