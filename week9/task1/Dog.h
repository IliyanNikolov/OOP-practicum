#ifndef DOG_HEADER_WHATEVER
#define DOG_HEADER_WHATEVER

#include"Animal.h"


class Dog: public Animal{
public:
    virtual void talk() const override{
        cout<<"Bau Bau\n";
    }
    virtual Animal* clone() const override{
        return new Dog(*this);
    }

    Dog() =default;
    Dog(const char *name, const char *type):Animal(name,type)
    {}


};







#endif