#ifndef QA_HEADER
#define QA_HEADER

#include"Employee.h"

enum Tester{
    automation=0,
    manual=1
};

class QualityAssurance: public Employee{
private:
    string project;
    Tester testerType;

public:
    QualityAssurance();
    QualityAssurance(const char*,const unsigned,const unsigned,const char*,const Tester);

};




#endif