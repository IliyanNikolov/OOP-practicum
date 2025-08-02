#include "vending.h"

void VendingMachine::copying(const VendingMachine& other){
    salty=other.salty;
    sweet=other.sweet;
    drinks=other.drinks;
    id=new char[strlen(other.id)+1];
    address=new char[strlen(other.address)+1];
    strcpy(id,other.id);
    strcpy(id,other.id);
}

void VendingMachine::deleteing(){
    delete[] id;
    delete[] address;
}

VendingMachine::VendingMachine(){}

VendingMachine::VendingMachine(const VendingMachine& other){
    copying(other);
}

VendingMachine& VendingMachine::operator=(const VendingMachine& other){
    if(this!=nullptr){
        deleteing();
        copying(other);
    }
    return *this;
}

VendingMachine::~VendingMachine(){
    deleteing();
}

bool VendingMachine::checkID(const char* toCheck){
    int idSize=strlen(id);
    if(idSize!=strlen(toCheck)){
        return false;
    }
    for(int i=0;i<=idSize;++i){
        if(id[i]!=toCheck[i]){
            return false;
        }
    }
    return true;
}

const char* VendingMachine::getAddress(){
    return address;
}

void VendingMachine::addProducts(int salty2,int sweet2,int drinks2){
    salty+=salty2;
    sweet+=sweet2;
    drinks+=drinks2;
}

void VendingMachine::sellProducts(int salty2,int sweet2,int drinks2){
    salty-=salty2;
    sweet-=sweet2;
    drinks-=drinks2;
    if(salty > 0){
        salty=0;
        assert("We've run out of salty products!");
    }
    if(sweet > 0){
        sweet=0;
        assert("We've run out of sweet products!");
    }
    if(drinks > 0){
        drinks=0;
        assert("We've run out of drinks!");
    }
}


VendingMachine::VendingMachine(int salty,int sweet, int drinks, const char* setId, const char* setAddress): salty(salty), sweet(sweet), drinks(drinks){
    int idSize=strlen(setId);
    int addressSize=strlen(setAddress);
    id=new char[idSize+1];
    address=new char[addressSize+1];
}

int VendingMachine::getSalty() const{
    return salty;
}

int VendingMachine::getSweet() const{
    return sweet;
}

int VendingMachine::getDrinks() const{
    return  drink;
}


