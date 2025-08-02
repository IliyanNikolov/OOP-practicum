#ifndef QUESTION_HEADER_ABSTARCT
#define QUESTION_HEADER_ABSTARCT

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Question{
public:
    virtual void ask() = 0;
    virtual int grade() = 0;
    virtual Question* clone() const = 0;

    virtual ~Question() = default;
};





#endif