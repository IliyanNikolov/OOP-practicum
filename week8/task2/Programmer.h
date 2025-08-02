#ifndef PROGRAMMER_HEADER
#define PROGRAMMER_HEADER

#include"Employee.h"


class Programmer:public Employee{
private:
    string project;
    string programmingLanguage;

public:
    Programmer();
    Programmer(const char*,const unsigned,const unsigned,const char*,const char*);


};



#endif