#include"ExternalUser.h"

ExternalUser::ExternalUser(const char *username,const char *password)
:SystemUser(username,password,0)
{}

std::istream& operator>>(std::istream& is,ExternalUser& inUser){    
    std::string temp;
    is>>temp;
    inUser.setUsername(temp);
    is>>temp;
    inUser.setPassword(temp);
    inUser.setIsEmployee(0);
    return is;
}

std::ostream& operator<<(std::ostream& os,const ExternalUser& outUser){
    os<<outUser.getUsername()<<" "<<outUser.getPassword();
    return os;
}