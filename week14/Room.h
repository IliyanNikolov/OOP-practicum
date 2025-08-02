#ifndef ROOM_CINEMA_SYSTEM_HEADER
#define ROOM_CINEMA_SYSTEM_HEADER

#include"Reservation.h"

class Room{
    vector<Reservation> seats;
    unsigned capacity;// capacity can't be changed once we initialize it
    unsigned size;
    string roomName;
    

};



#endif