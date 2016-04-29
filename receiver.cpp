#include "receiver.h"
#include <iostream>
#include <QString>

Receiver::Receiver()
{
    std::cout<< "building emitter"<<std::endl;
}

void Receiver::received(QString msg)
{
    std::cout<<"received signal: "<<msg.toStdString()<<std::endl;
}
