#include"SystemFirmaIT.h"

void System::copying(const System& other){
    capacity=other.capacity;
    size=other.size;
    arr=new Employee*[capacity];
    for(int i=0;i<size;++i){
        arr[i]=other.arr[i]->clone();
    }
    annualBalance=other.annualBalance;
    projects=other.projects;
}

void System::deleteing(){
    for(int i=0;i<size;++i){
        delete arr[i];
    }
    delete[] arr;
}

void System::resize(){
    capacity*=2;
    Employee **temp=new Employee*[capacity];
    for(int i=0;i<size;++i){
        temp[i]=arr[i];
    }
    delete[] arr;
    arr=temp;
}

System::System(){
    capacity=INITIAL_CAPACITY;
    arr=new Employee*[capacity];
    size=0;
    annualBalance=0;
}

System::System(const System& other){
    copying(other);
}

System& System::operator=(const System& other){
    if(this!=&other){
        deleteing();
        copying(other);
    }
    return *this;
}

System::~System(){
    deleteing();
}

void System::annualRaises(){
    double cutInBalance=0;
    for(int i=0;i<size;++i){
        cutInBalance+=arr[i]->annualRaise();
    }
    annualBalance-=cutInBalance;
}