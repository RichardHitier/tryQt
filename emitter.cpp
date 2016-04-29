#include "emitter.h"
#include <iostream>
#include <QString>

Emitter::Emitter()
{
    std::cout<< "building emitter"<<std::endl;
}

void Emitter::finished(QString msg)
{
    emit sendingSignal( msg );
}
