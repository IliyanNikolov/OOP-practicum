#ifndef VENDING_MACHINE_AGAIN
#define VENDING_MACHINE_AGAIN

#include<fstream>
#include<iostream>
#include<cstring>
using namespace std;


class VendingMachine{
private:
    int salty;
    int sweet;
    int drinks;
    int id;
    char* address;

    char** warnings;
    int warningsCount;
    int warningsCapacity;
    
    void resizeWarnings();
    void copying(const VendingMachine&);
    void deleteing();
public:
    VendingMachine();
    VendingMachine(const VendingMachine&);
    VendingMachine& operator=(const VendingMachine&);
    ~VendingMachine();
    bool checkID(const int);
    const char* getAddress();
    void addProducts(int, int, int);
    void sellProducts(int, int, int);
    VendingMachine(const int, const int, const int, const char*);
    int getSalty()const;
    int getSweet()const;
    int getDrinks()const;
    VendingMachine(VendingMachine&&);
    VendingMachine& operator=(VendingMachine&&);
};














#endif