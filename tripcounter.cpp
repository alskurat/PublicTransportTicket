#include "tripcounter.h"

TripCounter::TripCounter()
{
    mCounter = 0;
}

SubwayTripCounter::SubwayTripCounter()
{
    mName =  "метро";
}

unsigned int SubwayTripCounter::fullCost()
{
    unsigned int total = 0;
    if     (mCounter < 11 )        total = 36 * mCounter;
    else if(mCounter < 21 )        total = 360 + 35 * mCounter;
    else if(mCounter < 31 )        total = 350+360 + 34 * mCounter;
    else if(mCounter < 41 )        total = 340+350+360 + 33 * mCounter;
    else                           total = 330+340+350+360 + 32 * mCounter;

    return total;
}

LandTransportTripCounter::LandTransportTripCounter(QString name)
{
    mName = name;
}

unsigned int LandTransportTripCounter::fullCost()
{
    unsigned int total = 0;

    if     (mCounter < 11 )     total = 31 * mCounter;
    else if(mCounter < 21 )     total = 310 + 30 * mCounter;
    else if(mCounter < 31 )     total = 300+310 + 29 * mCounter;
    else if(mCounter < 41 )     total = 290+300+310 + 28 * mCounter;
    else                        total = 280+290+300+310 + 27 * mCounter;

    return total;
}
