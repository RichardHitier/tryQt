#ifndef ER_H
#define ER_H

#include <QObject>

class Emetteur: public QObject
{
    Q_OBJECT
public:
    int m_val=0;
    Emetteur();
    void changer(int val);

signals:
    void bang();
};

class Receveur: public QObject
{
    Q_OBJECT
public:
    Receveur();
public slots:
    void explose();

};
#endif // ER_H
