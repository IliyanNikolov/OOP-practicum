#ifndef STAFIDI_CHOCOLATE_HEADER
#define STAFIDI_CHOCOLATE_HEADER

#include"justChocolate.h"


class StafidiChocolate : virtual public Chocolate{
private:
    int stafidiPercentage;

public:
    StafidiChocolate();
    StafidiChocolate(int);

    Chocolate* clone() const override{
        return new StafidiChocolate(*this);
    }

};









#endif