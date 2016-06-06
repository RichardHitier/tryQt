#include "abstractlistener.h"


// kind of interface you have to implement in order to ensure you are a listener of event emitter you possesse
AbstractListener::AbstractListener()
{
    m_em = new Emetteur();

}

AbstractListener::AbstractListener(Emetteur *em)
{
    setEmetteur( em );

}

void AbstractListener::setEmetteur(Emetteur *em)
{
    m_em = em;
    listenBang();
}
