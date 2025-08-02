#ifndef CAT_HEADER
#define CAT_HEADER

#include"Animal.h"


class Cat: public Animal{
public:
    virtual void talk() const override{
        cout<<"Meowww\n";
    }
    virtual Animal* clone() const override{
        return new Cat(*this);
    }

    Cat() =default;
    Cat(const char *name,const char *type):Animal(name,type)
    {}


};



#endif