#ifndef MLAD_MERINDJEI_HEADER
#define MLAD_MERINDJEI_HEADER

#include"Employee_3.h"

class Manager: public Employee{
private:
    unsigned staff;

public:
    Manager();
    Manager(const char*,const unsigned,const unsigned,const unsigned);    
    virtual double annualRaise() override{
        if(staff>0 && staff<11){
            return changeSalary(6);
        }
        else if(staff<16){
            return changeSalary(12);
        }
        else if(staff>15){
            return changeSalary(15);
        }
        return 0;
    }
    virtual Employee* clone() const override{
        return new Manager(*this);
    }
};


#endif