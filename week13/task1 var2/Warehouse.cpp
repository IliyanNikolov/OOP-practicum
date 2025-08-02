#include "Warehouse.h"



void Warehouse::copying(const Warehouse& other){
    capacity=other.capacity;
    size=other.size;
    arr=new Chocolate*[capacity];
    for(int i=0;i<size;++i){
        arr[i]=other.arr[i]->clone();
    }
}

void Warehouse::deleteing(){
    for(int i=0;i<size;++i){
        delete arr[i];
    }
    delete[] arr;
}

void Warehouse::resize(){
    capacity*=2;
    Chocolate **temp=new Chocolate*[capacity];
    for(int i=0;i<size;++i){
        temp[i]=arr[i];
    }
    delete[] arr;
    arr=temp;
}

Warehouse::Warehouse(){
    capacity=INITIAL_CAPACITY;
    arr=new Chocolate*[capacity];
    size=0;
}

Warehouse::Warehouse(const Warehouse& other){
    copying(other);
}

Warehouse& Warehouse::operator=(const Warehouse& other){
    if(this!=&other){
        deleteing();
        copying(other);
    }
    return *this;
}

Warehouse::~Warehouse(){
    deleteing();
}

Warehouse::Warehouse(Chocolate ** arr,int arrSize){
    capacity=arrSize+INITIAL_CAPACITY;
    this->arr=new Chocolate*[capacity];
    size=arrSize;
    for(int i=0;i<size;++i){
        this->arr[i]=arr[i]->clone();
    }
}

void Warehouse::removeChocolate(int indexToRmove){
    if(indexToRmove>=0 && indexToRmove<size){
        for(int i=indexToRmove;i<size-1;++i){
            arr[i]=arr[i+1];
        }
        --size;
        arr[size]=nullptr;
    }
}