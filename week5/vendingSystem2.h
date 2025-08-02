#ifndef VENDING_MACHINE_SYSTEM_AGAIN
#define VENDING_MACHINE_SYSTEM_AGAIN

#include "vendingMachine2.h"

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
    const char* getAddressById(const int);
    void getCurrentProductsById(const int);
    void sellProductsById(const int id,int,int,int);
    void addProductsById(const int id,int,int,int);
    VendingSystem(VendingSystem&&);
    VendingSystem& operator=(VendingSystem&&);
    
};


#endif