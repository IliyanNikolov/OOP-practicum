#ifndef WAREHOUSE_FOR_CHOCOLATE_H
#define WAREHOUSE_FOR_CHOCOLATE_H


#include"StafidiMilk.h"
#include"StafidiDark.h"

const int INITIAL_CAPACITY=8;

class Warehouse{
private:
    Chocolate **arr;
    unsigned capacity;
    unsigned size;
    void copying(const Warehouse&);
    void deleteing();
    void resize();

public:
    Warehouse();
    Warehouse(const Warehouse&);
    Warehouse& operator=(const Warehouse&);
    ~Warehouse();

    Warehouse(Chocolate**,int);

    void removeChocolate(int);
    // void print()const;

};







#endif