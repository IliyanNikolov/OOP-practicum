#ifndef TASK_VIRTUAL_H
#define TASK_VIRTUAL_H

#include<iostream>
#include<string>
using namespace std;

class Task{
public:
    virtual Task* clone() const = 0;
    virtual ~Task() = default;
};







#endif