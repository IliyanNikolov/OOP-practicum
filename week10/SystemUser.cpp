#include "SystemUser.h"


void SystemUser::setIsEmployee(bool isEmployee){
    this->isEmployee=isEmployee;
}

void SystemUser::setUsername(std::string username){
    this->username=username;
}

void SystemUser::setPassword(std::string password){
    this->password=password;
}

SystemUser::SystemUser(const char *username,const char *password,bool isEmployee)
:username(username),password(password),isEmployee(isEmployee)
{}

std::string SystemUser::getUsername() const{
    return username;
}

std::string SystemUser::getPassword() const{
    return password;
}