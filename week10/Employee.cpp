#include"EmployeeUser.h"

Employee::Employee(const char *username,const char *password)
:SystemUser(username,password,1)
{}

std::istream& operator>>(std::istream& is,Employee& inUser){    
    std::string temp;
    is>>temp;
    inUser.setUsername(temp);
    is>>temp;
    inUser.setPassword(temp);
    inUser.setIsEmployee(1);
    return is;
}

std::ostream& operator<<(std::ostream& os,const Employee& outUser){
    os<<outUser.getUsername()<<" "<<outUser.getPassword();
    return os;
}