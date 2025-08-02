#ifndef LANDMARKS_H
#define LANDMARKS_H

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

class Landmark{
private:
    std::string coordinates;
    std::string description;
public:
    Landmark() = default;
    Landmark(std::string,std::string);

    friend std::istream& operator>>(istream&,Landmark&);
    friend std::ostream& operator<<(ostream&,const Landmark&);

};




#endif