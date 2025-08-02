#ifndef QA_HEADER
#define QA_HEADER

#include"Employee_3.h"

enum Tester{
    automation=0,
    manual=1
};

class QualityAssurance: public Employee{
private:
    vector<Project> project;
    Tester testerType;

public:
    QualityAssurance();
    QualityAssurance(const char*,const unsigned,const unsigned,vector<Project>,const Tester);
    void addProject(Project);
    void removeProject(int);
    virtual double annualRaise() override{
        if(testerType==manual){
            if(project.size()==1){
                return changeSalary(5);
            }
            else if(project.size()<=3){
                return changeSalary(10);
            }
            else if(project.size()>3){
                return changeSalary(15);
            }
            return 0;
        }
        else{
            double averageDifficulty=0;
            for(Project p : project){
                averageDifficulty+=p.getProjectDifficulty();
            }
            averageDifficulty/=project.size();
            if(averageDifficulty<5 && averageDifficulty>0){
                return changeSalary(5);
            }
            else if(averageDifficulty<8){
                return changeSalary(10);
            }
            else if(averageDifficulty>0){
                return changeSalary(15);
            }
            return 0;
        }
    }

    virtual Employee* clone() const override{
        return new QualityAssurance(*this);
    }
};




#endif