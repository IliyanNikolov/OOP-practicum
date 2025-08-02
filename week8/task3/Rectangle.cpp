#include"Rectangle.h"

Rectangle::Rectangle()
{}

Rectangle::Rectangle(const char *type,const double width,const double height)
:Shape(type),width(width),height(height)
{
    if(width<0){
        this->width=0;
    }
    else{
        this->width=width;
    }
    if(height<0){
        this->height=0;
    }
    else{
        this->height=height;
    }
}

void Rectangle::setWidth(const double width){
    if(width<0){
        this->width=0;
    }
    else{
        this->width=width;
    }
}

void Rectangle::setHeight(const double height){
    if(height<0){
        this->height=0;
    }
    else{
        this->height=height;
    }
}
