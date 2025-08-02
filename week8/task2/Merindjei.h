#ifndef MLAD_MERINDJEI_HEADER
#define MLAD_MERINDJEI_HEADER

#include"Employee.h"

class Manager: public Employee{
private:
    unsigned staff;

public:
    Manager();
    Manager(const char*,const unsigned,const unsigned,const unsigned);    

};


#endif