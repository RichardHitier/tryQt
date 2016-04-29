#ifndef RECEIVER_H
#define RECEIVER_H
#include <QObject>
#include <QString>

class Receiver: public QObject
{
    Q_OBJECT

protected slots:
    void received(QString msg);

public:
    Receiver();
};
#endif
