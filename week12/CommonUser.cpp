#include"CommonUser.h"

unsigned long long CommonUser::IDcounter=0;

std::string encryptPassword(std::string password){
    for(int i=0;i<password.size();++i){
        password[i]=password[i]+1;
    }
    return password;
}

std::string decryptPassword(std::string password){
    for(int i=0;i<password.size();++i){
        password[i]=password[i]-1;
    }
    return password;
}

CommonUser::CommonUser(){
    ID=IDcounter;
    ++IDcounter;
}

CommonUser::CommonUser(std::string name,std::string password):name(name){
    ID=IDcounter;
    ++IDcounter;
    this->password=encryptPassword(password);
}

bool CommonUser::comparePasswords(CommonUser *lhs,CommonUser *rhs){
    return lhs->password==rhs->password;
}

std::string CommonUser::getName() const{
    return name;
}
