#ifndef STAFIDI_DARK_CHOCOLATE_J
#define STAFIDI_DARK_CHOCOLATE_J

#include"DarkChocolate.h"
#include"StafidakisChocolate.h"


class StafidiDarkChocolate: public DarkChocolate, public StafidiChocolate{
public:
    StafidiDarkChocolate();
    StafidiDarkChocolate(int,int);
    StafidiDarkChocolate(int,int,string);

    Chocolate* clone() const override{
        return new StafidiDarkChocolate(*this);
    }
};




#endif