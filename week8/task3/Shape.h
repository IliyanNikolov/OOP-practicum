#ifndef SHAPE_HEADER
#define SHAPE_HEADER

#include<string>
using namespace std;


class Shape{
private:
    string type;

public:
    Shape();
    Shape(const char*);
    void setType(const char*);
};



#endif