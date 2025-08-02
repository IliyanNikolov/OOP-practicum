#include"Shape.h"

Shape::Shape()
{}

Shape::Shape(const char *type):type(type)
{}

void Shape::setType(const char *newType){
    type=newType;
}