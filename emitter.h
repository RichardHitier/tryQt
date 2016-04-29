#ifndef EMITTER_H
#define EMITTER_H

#include <QObject>
#include <QString>
class Emitter: public QObject
{
    Q_OBJECT

signals:
    void sendingSignal( QString message);

public:
    Emitter();
    void finished(QString msg);

};

#endif //EMITTER_H
