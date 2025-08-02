#ifndef PERSON_CINEMA_SYSTEM_HEADER
#define PERSON_CINEMA_SYSTEM_HEADER

#include"Reservation.h"



class Person{
private:
    string personName;
    string birthDate;
    vector<Reservation> reservations;

};



#endif