#ifndef PROGRAMMER_HEADER
#define PROGRAMMER_HEADER

#include"Employee_3.h"


class Programmer:public Employee{
private:
    vector<Project> project;
    string programmingLanguage;

public:
    Programmer();
    Programmer(const char*,const unsigned,const unsigned,vector<Project>,const char*);
    void addProject(Project);
    void removeProject(int);
    virtual double annualRaise() override{
        double averageDifficulty=0;
        for(Project p : project){
            averageDifficulty+=p.getProjectDifficulty();
        }
        averageDifficulty/=project.size();
        if(averageDifficulty<5 && averageDifficulty>0){
            return changeSalary(6);
        }
        else if(averageDifficulty<8){
            return changeSalary(12);
        }
        else if(averageDifficulty>0){
            return changeSalary(15);
        }
        return 0;
    }

    virtual Employee* clone() const override{
        return new Programmer(*this);
    }


};



#endif