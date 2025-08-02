#include"Employee.h"

Employee::Employee(){
    internship=0;
    salary=0;
}

Employee::Employee(const char* name,const unsigned months,const unsigned salary)
:name(name),internship(months),salary(salary)
{}