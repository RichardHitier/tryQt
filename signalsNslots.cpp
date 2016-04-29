#include <iostream>
#include <QApplication>
#include "receiver.h"
#include "emitter.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    Emitter emitter;
    emitter.finished(QString("Hello World"));
    return app.exec();
}
