#ifndef RESERVATION_CINEMA_SYSTEM_HEADER
#define RESERVATION_CINEMA_SYSTEM_HEADER

#include"Movie.h"


class Reservation{
    Movie movie;
    bool isItReserved;// if 0 then all methods won't do anything except reserved()
    unsigned seat;
    string personName;

    bool reserved(){
        return isItReserved;
    }
};







#endif