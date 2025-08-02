#ifndef LONG_TASK_H
#define LONG_TASK_H

#include"Task.h"

class LongTask: public Task{
private:
    string descr;
    int size;
    double progress;// between 0 and 1
    bool isTaskDone;
    int time;

public:
    Task* clone() const override{
        return new LongTask(*this);
    }
};


#endif