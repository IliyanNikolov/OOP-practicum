#include"Employee_3.h"

Employee::Employee(){
    internship=0;
    salary=0;
}

Employee::Employee(const char* name,const unsigned months,const double salary)
:name(name),internship(months),salary(salary)
{}

double Employee::changeSalary(int percent){
    double temp=salary*percent/100;
    salary+=temp;
    return temp;
}

double Employee::getSalary() const{
    return salary;
}