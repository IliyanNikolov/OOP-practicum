#include"set.h"


void Set::resize(){
    capacity*=2;
    int *temp=new int[capacity];
    for(int i=0;i<size;++i){
        temp[i]=arr[i];
    }
    delete[] arr;
    arr=temp;
}

void Set::copying(const Set& other){
    capacity=other.capacity;
    size=other.size;
    arr=new int[capacity];
    for(int i=0;i<size;++i){
        arr[i]=other.arr[i];
    }
}

void Set::deleteing(){
    delete[] arr;
}

Set::Set(){
    capacity=8;
    size=0;
    arr=new int[capacity];
}

Set::Set(const Set& other){
    copying(other);
}

Set& Set::operator=(const Set& other){
    if(this!=&other){
        deleteing();
        copying(other);
    }
    return *this;
}

Set::~Set(){
    deleteing();
}

Set::Set(Set&& other){
    size=other.size;
    capacity=other.capacity;
    arr=other.arr;
    other.arr=nullptr;
}

Set& Set::operator=(Set&& other){
    if(this!=&other){
        deleteing();
        size=other.size;
        capacity=other.capacity;
        arr=other.arr;
        other.arr=nullptr;
    }
    return *this;
}

bool Set::addElement(const int element){
    for(int i=0;i<size;++i){
        if(arr[i]==element){
            return false;
        }
    }
    if(capacity==size){
        resize();
    }
    arr[size]=element;
    ++size;
    return true;
}

bool Set::deleteElement(const int element){
    for(int i=0;i<size;++i){
        if(arr[i]==element){
            for(int j=i+1;j<size;++j){
                arr[j-1]=arr[j];
            }
            --size;
            return true;
        }
    }
    return false;
}

void Set::print(){
    for(int i=0;i<size;++i){
        cout<<arr[i]<<" , ";
    }
    cout<<endl;
}

void Set::setUnion(const Set other){
    for(int i=0;i<other.size;++i){
        addElement(other.arr[i]);
    }
}

void Set::setIntersection(const Set other){
    bool f;
    for(int i=0;i<other.size;++i){
        f=1;
        for(int j=0;j<size;++j){
            if(other.arr[i]==arr[j]){
                f=0;
            }
        }
        if(f){
            deleteElement(other.arr[i]);
        }
    }
}

Set& Set::operator+=(const Set& other){
    setIntersection(other);
    return *this;
}

Set operator+(const Set& lhs,const Set& rhs){
    Set temp(lhs);
    temp+=rhs;
    return temp;
}

Set& Set::operator+=(const int num){
    for(int i=0;i<size;++i){
        arr[i]+=num;
    }
    return *this;
}

Set operator+(Set& lhs,const int num){
    lhs+=num;
    return lhs;
}

Set operator+(const int num,Set& rhs){
    rhs+=num;
    return rhs;
}



