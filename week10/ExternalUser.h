#ifndef EXTERNAL_USER_HEADER
#define EXTERNAL_USER_HEADER

#include"SystemUser.h"

class ExternalUser: public SystemUser{
public:
    ExternalUser() = default;
    ExternalUser(const char*,const char*);

    friend std::istream& operator>>(std::istream&,ExternalUser&);
    friend std::ostream& operator<<(std::ostream&,const ExternalUser&);

};





#endif