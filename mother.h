#ifndef MOTHER_H
#define MOTHER_H

#include <iostream>
#include <QWidget>

class Mother
{
public:
    Mother();
    virtual void doit()=0;
};
Q_DECLARE_INTERFACE(Mother, "motherid");

#endif
