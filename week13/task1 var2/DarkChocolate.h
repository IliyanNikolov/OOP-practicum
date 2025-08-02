#ifndef DARK_CHOCOLATE_H
#define DARK_CHOCOLATE_H

#include"justChocolate.h"

class DarkChocolate : virtual public Chocolate{
private:
    string id;
    int cocoaPercentage;

public:
    DarkChocolate();
    DarkChocolate(int);
    DarkChocolate(string);
    DarkChocolate(string,int);

    Chocolate* clone() const override{
        return new DarkChocolate(*this);
    }

};




#endif