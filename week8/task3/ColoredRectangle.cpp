#include"ColoredRectangle.h"

ColoredRectangle::ColoredRectangle()
{}

ColoredRectangle::ColoredRectangle(const char *type,const double width,const double height,const char *color)
:Rectangle(type,width,height),color(color)
{}