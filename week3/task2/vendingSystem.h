#ifndef VENDING_MACHINE_SYSTEM
#define VENDING_MACHINE_SYSTEM

#include "vending.h"

class VendingSystem{
private:
    VendingMachine *machines;
    int capacity;
    int size;
    void copying(const VendingSystem&);
    void deleteing();
    void resize();
public:
    VendingSystem();
    VendingSystem(const VendingSystem&);
    VendingSystem& operator=(const VendingSystem&);
    ~VendingSystem();
    void addVendingMachine(VendingMachine&);
    const char* getAddressById(const char*);
    void getCurrentProductsById(const char*);
    void sellProductsById(const char*,int,int,int);
    void addProductsById(const char*,int,int,int);
};


#endif