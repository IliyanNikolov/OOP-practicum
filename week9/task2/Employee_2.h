#ifndef EMPLOYEE_HEADER
#define EMPLOYEE_HEADER

#include<string>
#include<vector>
#include"Project.h"
using namespace std;

class Employee{
private:
    string name;
    unsigned internship;
    unsigned salary;

public:
    Employee();
    Employee(const char*,const unsigned,const unsigned);

    virtual unsigned salaryRaisePercent()const;
    void annual_raise(){// not sure if it works
        salary=(salary*(100+this->salaryRaisePercent()))/100;
    }

};



#endif