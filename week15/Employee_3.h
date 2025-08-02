#ifndef EMPLOYEE_HEADER
#define EMPLOYEE_HEADER

#include"ProjectFirmaIt.h"

class Employee{
private:
    string name;
    unsigned internship;
    double salary;

public:
    Employee();
    Employee(const char*,const unsigned,const double);
    virtual double annualRaise() = 0;
    virtual Employee* clone() const = 0;
    double changeSalary(int);
    double getSalary() const;
    virtual ~Employee() = default;

};



#endif