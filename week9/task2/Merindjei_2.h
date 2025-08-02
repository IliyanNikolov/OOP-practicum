#ifndef MLAD_MERINDJEI_HEADER
#define MLAD_MERINDJEI_HEADER

#include"Employee_2.h"

class Manager: public Employee{
private:
    unsigned staff;

public:
    Manager();
    Manager(const char*,const unsigned,const unsigned,const unsigned);    
    virtual unsigned salaryRaisePercent() const  override{
        if(staff<11){
            return 6;
        }
        if(staff<16){
            return 12;
        }
        return 15;
    }
    

};


#endif