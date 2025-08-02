#ifndef COMMON_SYSTEM_USER_H
#define COMMON_SYSTEM_USER_H

#include<iostream>
#include<fstream>
#include<string>
#include<vector>

std::string encryptPassword(std::string password);
std::string decryptPassword(std::string password);


class CommonUser{
private:
    unsigned long long ID;
    std::string name;
    std::string password;

public:
    static unsigned long long IDcounter;
    CommonUser();
    CommonUser(std::string name,std::string password);
    static bool comparePasswords(CommonUser*,CommonUser*);
    std::string getName() const;

};




#endif