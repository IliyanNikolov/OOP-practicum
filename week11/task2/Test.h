#ifndef TEST_CONTAINER_HEAADER
#define TEST_CONTAINER_HEAADER

#include"YesNoQuestion.h"
#include"MultipleChoice.h"
#include"OpenQuestion.h"

const int INITIAL_CAPACITY=8;

class Test{
private:
    Question **arr;
    unsigned capacity;
    unsigned size;
    void copying(const Test&);
    void deleteing();
    void resize();

public:
    Test();
    Test(const Test&);
    Test& operator=(const Test&);
    ~Test();

    void addQuestion(Question*);
    void doTest();
    long long gradeTest();

};




#endif