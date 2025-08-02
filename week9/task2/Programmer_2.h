#ifndef PROGRAMMER_HEADER
#define PROGRAMMER_HEADER

#include"Employee_2.h"


class Programmer:public Employee{
private:
    vector<Project> projects;
    string programmingLanguage;

public:
    Programmer();
    Programmer(const char*,const unsigned,const unsigned,const vector<Project>,const char*);
    virtual unsigned salaryRaisePercent() const override{
        unsigned temp=0;
        for(int i=0;i<projects.size();++i){
            temp+=projects[i].getProjectDifficulty();
        }
        unsigned result=temp/projects.size();
        if(result<5){
            return 6;
        }
        if(result<8){
            return 12;
        }
        return 15;
    }

};



#endif