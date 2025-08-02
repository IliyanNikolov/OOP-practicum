#ifndef CHOCOLATE_NORMAL_VIRTUAL
#define CHOCOLATE_NORMAL_VIRTUAL

#include<iostream>
#include<string>
using namespace std;

class Chocolate{
public:
    virtual Chocolate* clone() const = 0;
    virtual ~Chocolate()=default;
};








#endif