#ifndef EMPLOYEE_HEADER
#define EMPLOYEE_HEADER

#include<string>
using namespace std;

class Employee{
private:
    string name;
    unsigned internship;
    unsigned salary;

public:
    Employee();
    Employee(const char*,const unsigned,const unsigned);

};



#endif