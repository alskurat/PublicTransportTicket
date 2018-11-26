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
    virtual ~TripCounter();
    QString name() { return mName; }
    void setCounter(unsigned int value) { mCounter = value; }
    unsigned int counter() { return mCounter; }
    void increaseCounter()  { mCounter++; }
    virtual unsigned int fullCost() = 0;
};

class SubwayTripCounter : public TripCounter
{
public:
    SubwayTripCounter();
    unsigned int fullCost();
};

class LandTransportTripCounter : public TripCounter
{
public:
    LandTransportTripCounter(QString name);
    unsigned int fullCost();
};

#endif // TRIPCOUNTER_H
