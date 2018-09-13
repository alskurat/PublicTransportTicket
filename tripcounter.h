#ifndef TRIPCOUNTER_H
#define TRIPCOUNTER_H

#include "QString"

class TripCounter
{
protected:
    QString mName;
    unsigned int mCounter;
public:
    TripCounter();

    QString name() { return mName; }
    void setCounter(int value) { mCounter = value; }
    unsigned int counter() { return mCounter; }
    void increaseCounter()  { mCounter++; }
    virtual int fullCost() = 0;
};

class SubwayTripCounter : public TripCounter
{
public:
    SubwayTripCounter();
    int fullCost();
};

class LandTransportTripCounter : public TripCounter
{
public:
    LandTransportTripCounter(QString name);
    int fullCost();
};

#endif // TRIPCOUNTER_H
