#ifndef COLORED_RECTANGLE_HEADER
#define COLORED_RECTANGLE_HEADER

#include"Rectangle.h"

class ColoredRectangle: public Rectangle{
private:
    string color;

public:
    ColoredRectangle();
    ColoredRectangle(const char*,const double,const double,const char*);
};




#endif