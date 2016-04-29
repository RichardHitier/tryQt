#include <iostream>
#include <QApplication>
#include <QObject>
#include "receiver.h"
#include "emitter.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    Emitter *emitter = new Emitter();
    Receiver *receiver = new Receiver();

    QObject::connect( emitter, SIGNAL(sendingSignal(QString)), receiver, SLOT(received(QString)));

    for( int i=0; i < 5; i++){
        emitter->finished(QString("Hello World "+i));
    }

    return app.exec();
}
