#include"Merindjei.h"

Manager::Manager(){
    staff=0;
}

Manager::Manager(const char *name,const unsigned months,const unsigned salary,const unsigned people)
:Employee(name,months,salary),staff(people)
{}