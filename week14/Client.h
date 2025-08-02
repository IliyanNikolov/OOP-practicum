#ifndef CLIENT_CINEMA_SYSTEM_H
#define CLIENT_CINEMA_SYSTEM_H

#include"Person.h"

enum Discount{
    None=0,
    Pensiq,
    Uchenik,
    Student
};

class Client: public Person{
private:
    Discount discount;
    double currentMoney;


};

#endif