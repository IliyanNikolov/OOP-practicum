#include"vendingSystem2.h"

void VendingSystem::copying(const VendingSystem& other){
    capacity=other.capacity;
    size=other.size;
    machines=new VendingMachine[capacity];
    for(int i=0;i<capacity;++i){
        machines[i]=other.machines[i];
    }
}

void VendingSystem::deleteing(){
    delete[] machines;
}

void VendingSystem::resize(){
    capacity*=2;
    VendingMachine *temp=new VendingMachine[capacity];
    for(int i=0;i<size;++i){
        temp[i]=machines[i];
    }
    delete[] machines;
    machines=temp;
}

VendingSystem::VendingSystem(){
    size=0;
    capacity=8;
    machines=new VendingMachine[capacity];
}

VendingSystem::VendingSystem(const VendingSystem& other){
    copying(other);
}

VendingSystem& VendingSystem::operator=(const VendingSystem& other){
    if(this!=&other){
        deleteing();
        copying(other);
    }
    return *this;
}

void VendingSystem::addVendingMachine(VendingMachine& toAdd){
    if(size==capacity){
        resize();
    }
    machines[size]=toAdd;
    ++size;
}

const char* VendingSystem::getAddressById(const int idToSearch){
    for(int i=0;i<size;++i){
        if(machines[i].checkID(idToSearch)){
            return machines[i].getAddress();
        }
    }
    return nullptr;
}

void VendingSystem::getCurrentProductsById(const int idToSearch){
    for(int i=0;i<size;++i){
        if(machines[i].checkID(idToSearch)){
            cout<<machines[i].getSalty()<<" "<<machines[i].getSweet()<<" "<<machines[i].getDrinks();
            break;
        }
    }
}

void VendingSystem::sellProductsById(const int idToSearch,int saltyToSell,int sweetToSell,int drinksToSell){
    for(int i=0;i<size;++i){
        if(machines[i].checkID(idToSearch)){
            machines[i].sellProducts(saltyToSell,sweetToSell,drinksToSell);
            break;
        }
    }
}

void VendingSystem::addProductsById(const int idToSearch,int saltyToAdd,int sweetToAdd,int drinksToAdd){
    for(int i=0;i<size;++i){
        if(machines[i].checkID(idToSearch)){
            machines[i].addProducts(saltyToAdd,sweetToAdd,drinksToAdd);
            break;
        }
    }
}

VendingSystem::VendingSystem(VendingSystem&& other){
    machines=other.machines;
    capacity=other.capacity;
    size=other.size;
    other.machines=nullptr;
}

VendingSystem& VendingSystem::operator=(VendingSystem&& other){
    if(this!=&other){
        deleteing();
        machines=other.machines;
        capacity=other.capacity;
        size=other.size;
        other.machines=nullptr;
    }
    return *this;
}
