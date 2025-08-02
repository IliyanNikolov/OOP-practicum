#ifndef CINEMA_CLASS_CINEMA_SYSTEM_HEADER
#define CINEMA_CLASS_CINEMA_SYSTEM_HEADER

#include"Projection.h"
#include"Client.h"
#include"CinemaEmployee.h"

class Cinema{
    vector<Projection> projections;
    vector<Movie> movies;
    vector<Client> clients;
    vector<Employee> employies;

};





#endif