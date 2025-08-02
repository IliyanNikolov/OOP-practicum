#include"CatsAndDogs.h"


void Container::copying(const Container& other){
    capacity=other.capacity;
    size=other.size;
    arr=new Animal*[capacity];
    for(int i=0;i<size;++i){
        arr[i]=other.arr[i]->clone();
    }
}

void Container::deleteing(){
    for(int i=0;i<size;++i){
        delete arr[i];
    }
    delete[] arr;
}

void Container::resize(){
    capacity*=2;
    Animal **temp=new Animal*[capacity];
    for(int i=0;i<size;++i){
        temp[i]=arr[i];
    }
    delete[] arr;
    arr=temp;
}

Container::Container(){
    capacity=INITIAL_CAPACITY;
    arr=new Animal*[capacity];
    size=0;
}

Container::Container(const Container& other){
    copying(other);
}

Container& Container::operator=(const Container& other){
    if(this!=&other){
        deleteing();
        copying(other);
    }
    return *this;
}

Container::~Container(){
    deleteing();
}

void Container::addAnimal(Animal *toAdd){
    if(size==capacity){
        resize();
    }
    arr[size++]=toAdd;
}

void Container::print() const{
    for(int i=0;i<size;++i){
        arr[i]->talk();
    }
}