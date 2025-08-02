#ifndef MY_VECTOR_TEMPLATES_HEADER
#define MY_VECTOR_TEMPLATES_HEADER

#include<iostream>
using namespace std;




const int INITIAL_CAPACITY=8;

template<typename T>
class MyVector{
private:
    T *arr;
    unsigned capacity;
    unsigned size;

    void resize();
    void copying(const MyVector<T>&);
    void deleteing();

public:
    MyVector();
    MyVector(const MyVector<T>&);
    MyVector<T>& operator=(const MyVector<T>&);
    ~MyVector();

    MyVector(MyVector<T>&&);
    MyVector<T>& operator=(MyVector<T>&&);

    void addElement(T);
    T operator[](int);
    void map(T (*function) (T&));

};


template<typename T>
void MyVector<T>::resize(){
    capacity*=2;
    T *temp=new T[capacity];
    for(int i=0;i<size;++i){
        temp[i]=arr[i];
    }
    delete[] arr;
    arr=temp;
}

template<typename T>
void MyVector<T>::copying(const MyVector<T>& other){
    capacity=other.capacity;
    size=other.size;
    arr=new T[capacity];
    for(int i=0;i<size;++i){
        arr[i]=other.arr[i];
    }
}

template<typename T>
void MyVector<T>::deleteing(){
    delete[] arr;
}

template<typename T>
MyVector<T>::MyVector(){
    capacity=INITIAL_CAPACITY;
    size=0;
    arr=new T[capacity];
}

template<typename T>
MyVector<T>::MyVector(const MyVector<T>& other){
    copying(other);
}

template<typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& other){
    if(this!=&other){
        deleteing();
        copying(other);
    }
    return *this;
}

template<typename T>
MyVector<T>::~MyVector(){
    deleteing();
}

template<typename T>
MyVector<T>::MyVector(MyVector<T>&& other){
    capacity=std::move(other.capacity);
    size=std::move(other.size);
    arr=std::move(other.arr);
    other.arr=nullptr;
}

template<typename T>
MyVector<T>& MyVector<T>::operator=(MyVector<T>&& other){
    if(this!=&other){
        deleteing();
        capacity=std::move(other.capacity);
        size=std::move(other.size);
        arr=std::move(other.arr);
        other.arr=nullptr;
    }
    return *this;
}

template<typename T>
void MyVector<T>::addElement(T toAdd){
    if(size==capacity){
        resize();
    }
    arr[size++]=toAdd;
}

template<typename T>
T MyVector<T>::operator[](int indexToReturn){
    if(indexToReturn<0 || indexToReturn>=size){
        throw runtime_error("Invalid index");
    }
    return arr[indexToReturn];
}

template<typename T>
void MyVector<T>::map(T (*function) (T&)){
    for(int i=0;i<size;++i){
        arr[i]=function(arr[i]);
    }
}



#endif