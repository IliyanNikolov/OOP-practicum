#ifndef ANIMAL_ABSTRACT_HEADER
#define ANIMAL_ABSTRACT_HEADER

#include<iostream>
#include<string>
using namespace std;


class Animal{
private:
    string animalName;
    string animalType;

public:
    virtual void talk() const=0;
    virtual Animal* clone() const=0;
    Animal(const char *name,const char *type):animalName(name),animalType(type)
    {}

    virtual ~Animal() = default;
};








#endif