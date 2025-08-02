#include"UserSystem.h"


void UserSystem::resize(){
    capacity*=2;
    User *temp=new User[capacity];
    for(int i=0;i<size;++i){
        temp[i]=users[i];   
    }
    delete[] users;
    users=temp;
}

void UserSystem::copying(const UserSystem& other){
    fileName=new char[strlen(other.fileName)+1];
    strcpy(fileName,other.fileName);
    capacity=other.capacity;
    size=other.size;
    users=new User[capacity];
    for(int i=0;i<size;++i){
        users[i]=other.users[i];
    }
}

void UserSystem::deleteing(){
    delete[] users;
    delete[] fileName;
}

void UserSystem::readFromFile(){
    if(!fileName){
        return;
    }
    
    ifstream file(fileName);

    if(!file.is_open()){
        cout<<"error";
        return;
    }

    User temp;
    while(!file.eof()){
        file>>temp;
        addUser(temp);
    }

    file.close();
}

void UserSystem::writeToFile(){
    if(!fileName){
        char temp[]="Slujeben file.txt";
        fileName=new char[strlen(temp)+1];
        strcpy(fileName,temp);
    }

    ofstream file(fileName);

    if(!file.is_open()){
        cout<<"error";
        return;
    }

    int i=0;
    while(i<size-1){
        file<<users[i]<<endl;
        ++i;
    }
    file<<users[i];

    file.close();

}

UserSystem::UserSystem(){
    capacity=8;
    size=0;
    users=new User[capacity];
    fileName=nullptr;
}

UserSystem::UserSystem(const UserSystem& other){
    copying(other);
}

UserSystem& UserSystem::operator=(const UserSystem& other){
    if(this!=&other){
        deleteing();
        copying(other);
    }
    return *this;
}

UserSystem::~UserSystem(){
    writeToFile();
    deleteing();
}

UserSystem::UserSystem(UserSystem&& other){
    users=other.users;
    capacity=other.capacity;
    size=other.size;
    fileName=other.fileName;
    other.users=nullptr;
    other.fileName=nullptr;
}

void UserSystem::addUser(const User toAdd){
    if(capacity==size){
        resize();
    }
    users[size]=toAdd;
    size++;
}

UserSystem::UserSystem(const char* fileName){
    this->fileName=new char[strlen(fileName)+1];
    strcpy(this->fileName,fileName);
    capacity=8;
    size=0;
    users=new User[capacity];
    readFromFile();
}

ostream& operator<<(ostream& os,const UserSystem& system){
    int i=0;
    while(i<system.size-1){
        os<<system.users[i]<<endl;
        ++i;
    }
    os<<system.users[i];
    return os;
}