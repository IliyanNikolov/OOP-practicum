#include"Test.h"


void Test::copying(const Test& other){
    capacity=other.capacity;
    size=other.size;
    arr=new Question*[capacity];
    for(int i=0;i<size;++i){
        arr[i]=other.arr[i]->clone();
    }
}

void Test::deleteing(){
    for(int i=0;i<size;++i){
        delete arr[i];
    }
    delete[] arr;
}

void Test::resize(){
    capacity*=2;
    Question **temp=new Question*[capacity];
    for(int i=0;i<size;++i){
        temp[i]=arr[i];
    }
    delete[] arr;
    arr=temp;
}

Test::Test(){
    capacity=INITIAL_CAPACITY;
    arr=new Question*[capacity];
    size=0;
}

Test::Test(const Test& other){
    copying(other);
}

Test& Test::operator=(const Test& other){
    if(this!=&other){
        deleteing();
        copying(other);
    }
    return *this;
}

Test::~Test(){
    deleteing();
}

void Test::addQuestion(Question* toAdd){
    if(size==capacity){
        resize();
    }
    arr[size++]=toAdd;
}

void Test::doTest(){
    for(int i=0;i<size;++i){
        arr[i]->ask();
    }
}

long long Test::gradeTest(){
    long long pointsToReturn=0;
    for(int i=0;i<size;++i){
        pointsToReturn+=arr[i]->grade();
    }
    return pointsToReturn;
}