#ifndef RECTANGLE_HEADER
#define RECTANGLE_HEADER

#include"Shape.h"

class Rectangle: public Shape{
private:
    double width;
    double height;

public:

    Rectangle();
    Rectangle(const char*,const double,const double);
    void setWidth(const double);
    void setHeight(const double);

};






#endif