#ifndef CATS_AND_DOGS_CONTAINER
#define CATS_AND_DOGS_CONTAINER

#include"Cat.h"
#include"Dog.h"

const int INITIAL_CAPACITY=8;


class Container{
private:
    Animal **arr;
    unsigned capacity;
    unsigned size;
    void copying(const Container&);
    void deleteing();
    void resize();

public:
    Container();
    Container(const Container&);
    Container& operator=(const Container&);
    ~Container();
    
    void addAnimal(Animal*);
    void print() const;


};




#endif