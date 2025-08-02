#ifndef SYSTEM_FIRMA_IT_HEADER
#define SYSTEM_FIRMA_IT_HEADER

#include"QA_3.h"
#include"Programmer_3.h"
#include"Merindjei_3.h"

const int INITIAL_CAPACITY=8;

class System{
private:
    double annualBalance;
    Employee **arr;
    unsigned capacity;
    unsigned size;
    vector<Project> projects;
    void copying(const System&);
    void deleteing();
    void resize();

public:
    System();
    System(const System&);
    System& operator=(const System&);
    ~System();

    void annualRaises();



};







#endif