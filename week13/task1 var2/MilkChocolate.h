#ifndef MILK_CHOCOLATE_HEADER
#define MILK_CHOCOLATE_HEADER

#include"justChocolate.h"

class MilkChocolate : virtual public Chocolate{
private:
    int ID;
    int milkPercentage;

public:
    MilkChocolate();
    MilkChocolate(int);

    static int IDcounter;

    Chocolate* clone() const override{
        return new MilkChocolate(*this);
    }


};







#endif