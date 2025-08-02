#ifndef BASIC_USER_HEADER
#define BASIC_USER_HEADER

#include "Landmark.h"



class SystemUser{
private:
    std::string username;
    std::string password;
    bool isEmployee;// 1 for employee and 0 for external user
public:
    void setIsEmployee(bool);
    void setUsername(std::string);
    void setPassword(std::string);
    SystemUser() = default;
    SystemUser(const char*,const char*,bool);
    std::string getUsername() const;
    std::string getPassword() const;

};







#endif