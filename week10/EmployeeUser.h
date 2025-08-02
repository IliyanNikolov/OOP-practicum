#ifndef EMPLOYEE_USER_HEAD
#define EMPLOYEE_USER_HEAD

#include"SystemUser.h"

class Employee: public SystemUser{
public:
    Employee() = default;
    Employee(const char*,const char*);

    friend std::istream& operator>>(std::istream&,Employee&);
    friend std::ostream& operator<<(std::ostream&,const Employee&);

};






#endif