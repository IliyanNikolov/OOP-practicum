#ifndef VENDING_MACHINE
#define VENDING_MACHINE

#include<iostream>
#include<cassert>
using namespace std;

class VendingMachine{
private:
    int salty=0;
    int sweet=0;
    int drinks=0;
    char *id=nullptr;
    char *address=nullptr;
    void copying(const VendingMachine&);
    void deleteing();
public:
    VendingMachine();
    VendingMachine(const VendingMachine&);
    VendingMachine& operator=(const VendingMachine&);
    ~VendingMachine();
    bool checkID(const char*);
    const char* getAddress();
    void addProducts(int, int, int);
    void sellProducts(int, int, int);
    VendingMachine(int,int, int, const char*, const char*);
    int getSalty()const;
    int getSweet()const;
    int getDrinks()const;
};





#endif