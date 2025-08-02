#ifndef EMPLOYEE_CINEMA_SYSTEM_H
#define EMPLOYEE_CINEMA_SYSTEM_H

#include"Person.h"
#include"Projection.h"

class Employee: public Person{
private:
    double salary;

public:
    void addProjection(vector<Projection>);
    void addMovie(vector<Movie>);

};




#endif