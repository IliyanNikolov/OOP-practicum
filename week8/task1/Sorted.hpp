#ifndef SORTED_ARRAY
#define SORTED_ARRAY


#include<iostream>
using namespace std;


template<typename T>
class Sorted{
private:
    T *arr;
    unsigned capacity;
    unsigned size;
    void resize();
    void copying(const Sorted<T>&);
    void deleteing();

public:
    Sorted();
    Sorted(const Sorted<T>&);
    Sorted<T>& operator=(const Sorted<T>&);
    ~Sorted();

    Sorted(Sorted<T>&&);
    Sorted<T>& operator=(Sorted<T>&&);

    void addElem(const T&);
    void removeElem(const T&);
    void print() const;


};


template<typename T>
void Sorted<T>::resize(){
    capacity*=2;
    T *temp=new T[capacity];
    for(int i=0;i<size;++i){
        temp[i]=arr[i];
    }
    delete[] arr;
    arr=temp;
}

template<typename T>
void Sorted<T>::copying(const Sorted<T>& other){
    capacity=other.capacity;
    size=other.size;
    arr=new T[capacity];
    for(int i=0;i<size;++i){
        arr[i]=other.arr[i];
    }
}

template<typename T>
void Sorted<T>::deleteing(){
    delete[] arr;
}

template<typename T>
Sorted<T>::Sorted(){
    capacity=8;
    arr=new T[capacity];
    size=0;
}

template<typename T>
Sorted<T>::Sorted(const Sorted<T>& other){
    copying(other);
}


template<typename T>
Sorted<T>& Sorted<T>::operator=(const Sorted<T>& other){
    if(this!=&other){
        deleteing();
        copying(other);
    }
    return *this;
}

template<typename T>
Sorted<T>::~Sorted(){
    deleteing();
}


template<typename T>
Sorted<T>::Sorted(Sorted<T>&& other){
    capacity=move(other.capacity);
    size=move(other.size);
    arr=move(other.arr);
    other.arr=nullptr;
}


template<typename T>
Sorted<T>& Sorted<T>::operator=(Sorted<T>&& other){
    if(this!=&other){
        deleteing();
        capacity=move(other.capacity);
        size=move(other.size);
        arr=move(other.arr);
        other.arr=nullptr;
    }
}


template<typename T>
void Sorted<T>::addElem(const T& toAdd){
    if(size==capacity){
        resize();
    }
    int i=0;
    while(i<size && arr[i]<toAdd){
        ++i;
    }
    for(int j=size;j>i;--j){
        arr[j]=arr[j-1];
    }
    arr[i]=toAdd;
    ++size;
}

template<typename T>
void Sorted<T>::removeElem(const T& elem){
    int i=0;
    while(i<size){
        if(arr[i]==elem){
            for(int j=i;j<size-1;++j){
                arr[j]=arr[j+1];
            }
            --size;
        }
        else{
            ++i;
        }
    }
}

template<typename T>
void Sorted<T>::print() const{
    for(int i=0;i<size-1;++i){
        cout<<arr[i]<<"\n";
    }
    cout<<arr[size-1];
}






#endif