#ifndef CLASS_SET
#define CLASS_SET

#include<iostream>
using namespace std;

class Set{
private:
    int capacity;
    int size;
    int *arr;
    void resize();
    void copying(const Set&);
    void deleteing();
public:
    Set();
    Set(const Set&);
    Set& operator=(const Set&);
    ~Set();
    Set(Set&&);
    Set& operator=(Set&&);
    bool addElement(const int);
    bool deleteElement(const int);
    void print();
    void setUnion(const Set);
    void setIntersection(const Set);


    Set& operator+=(const Set&);
    Set& operator+=(const int);
    Set& operator*=(const Set&);
};

Set operator+(const Set&,const Set&);
Set operator+(Set&,const int);
Set operator+(const int,Set&);











#endif