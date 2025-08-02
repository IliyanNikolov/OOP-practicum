#ifndef SIMPLE_TASK_H
#define SIMPLE_TASK_H


#include"Task.h"

class SimpleTask: public Task{
private:
    string descr;
    int size;
    double progress;// between 0 and 1
    bool isTaskDone;
    int time=1;

public:
    Task* clone() const override{
        return new SimpleTask(*this);
    }
};





#endif