#ifndef STAFIDI_MILK_CHOCOLATE_H
#define STAFIDI_MILK_CHOCOLATE_H

#include"MilkChocolate.h"
#include"StafidakisChocolate.h"

class StafidiMilkChocolate: public MilkChocolate, public StafidiChocolate{
public:
    StafidiMilkChocolate();
    StafidiMilkChocolate(int,int);

    Chocolate* clone() const override{
        return new StafidiMilkChocolate(*this);
    }
};








#endif