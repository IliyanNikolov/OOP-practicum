#include"User.h"



void User::copying(const User& other){
    name=new char[strlen(other.name)+1];
    password=new char[strlen(other.password)+1];
    strcpy(name,other.name);
    strcpy(password,other.password);
}

void User::deleteing(){
    delete[] name;
    delete[] password;
}

User::User(){
    name=nullptr;
    password=nullptr;
}

User::User(const User& other){
    copying(other);
}

User& User::operator=(const User& other){
    if(this!=&other){
        deleteing();
        copying(other);
    }
    return *this;
}

User::~User(){
    deleteing();
}

User::User(User&& other){
    name=other.name;
    password=other.password;
    other.password=nullptr;
    other.name=nullptr;
}

User& User::operator=(User&& other){
    if(this!=&other){
        deleteing();
        name=other.name;
        password=other.password;
        other.password=nullptr;
        other.name=nullptr;
    }
    return *this;
}

User::User(const char *name1,const char *name2){
    name=new char[strlen(name1)+1];
    password=new char[strlen(name2)+1];
    strcpy(name,name1);
    strcpy(password,name2);
}

istream& operator>>(istream& is,User& user){
    user.deleteing();
    char buffer[1024];
    is.getline(buffer,1024,' ');
    user.name=new char[strlen(buffer)+1];
    strcpy(user.name,buffer);
    is.getline(buffer,1024,'\n');
    user.password=new char[strlen(buffer)+1];
    strcpy(user.password,buffer);
    return is;
}

ostream& operator<<(ostream& os,const User& user){
    os<<user.name<<" "<<user.password;
    return os;
}

