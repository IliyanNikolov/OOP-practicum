#include"vendingMachine2.h"

void VendingMachine::resizeWarnings(){
    warningsCapacity*=2;
    char **temp=new char*[warningsCapacity];
    for(int i=0;i<warningsCount;++i){
        temp[i]=new char[strlen(warnings[i]) + 1];
        strcpy(temp[i],warnings[i]);
    }
    delete[] warnings;
    warnings=temp;
}

void VendingMachine::copying(const VendingMachine& other){
    salty=other.salty;
    sweet=other.sweet;
    drinks=other.drinks;
    id=other.id;
    address=new char[strlen(other.address)+1];
    strcpy(address,other.address);

    warningsCapacity=other.warningsCapacity;
    warningsCount=other.warningsCount;
    for(int i=0;i<warningsCount;++i){
        warnings[i]=new char[strlen(other.warnings[i]) + 1];
        strcpy(warnings[i],other.warnings[i]);
    }
}

void VendingMachine::deleteing(){
    delete[] address;
    for(int i=0;i<warningsCapacity;++i){
        delete[] warnings[i];
    }
    delete[] warnings;
}

VendingMachine::VendingMachine(){
    salty=0;
    sweet=0;
    drinks=0;
    id=0;
    address=nullptr;
    warningsCount=0;
    warningsCapacity=8;
    warnings=new char*[warningsCapacity];
}

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

bool VendingMachine::checkID(const int toCheck){
    return id==toCheck;
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
    // salty-=salty2;
    // sweet-=sweet2;
    // drinks-=drinks2;
    // if(salty > 0){
    //     salty=0;
    //     if(warningsCapacity==warningsCount){
    //         resizeWarnings();
    //     }
    //     warnings[warningsCount++]=;
    //     string w="We've run out of salty products!";
    // }
    // if(sweet > 0){
    //     sweet=0;
    //     assert("We've run out of sweet products!");
    // }
    // if(drinks > 0){
    //     drinks=0;
    //     assert("We've run out of drinks!");
    // }
}


VendingMachine::VendingMachine(const int salty, const int sweet, const int drinks, const char* setAddress): salty(salty), sweet(sweet), drinks(drinks){
    id=0;
    address=new char[strlen(setAddress)+1];
    strcpy(address,setAddress);
    warningsCount=0;
    warningsCapacity=8;
    warnings=new char*[warningsCapacity];
}

int VendingMachine::getSalty() const{
    return salty;
}

int VendingMachine::getSweet() const{
    return sweet;
}

int VendingMachine::getDrinks() const{
    return drinks;
}

VendingMachine::VendingMachine(VendingMachine&& other){
    salty=other.salty;
    sweet=other.sweet;
    drinks=other.drinks;
    id=other.id;
    address=other.address;
    warnings=other.warnings;
    warningsCapacity=other.warningsCapacity;
    warningsCount=other.warningsCount;
    other.address=nullptr;
    other.warnings=nullptr;
}

VendingMachine& VendingMachine::operator=(VendingMachine&& other){
    if(this!=&other){
        deleteing();
        salty=other.salty;
        sweet=other.sweet;
        drinks=other.drinks;
        id=other.id;
        address=other.address;
        warnings=other.warnings;
        warningsCapacity=other.warningsCapacity;
        warningsCount=other.warningsCount;
        other.address=nullptr;
        other.warnings=nullptr;
    }
    return *this;
}



