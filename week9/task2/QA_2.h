#ifndef QA_HEADER
#define QA_HEADER

#include"Employee_2.h"

enum Tester{
    automation=0,
    manual=1
};

class QualityAssurance: public Employee{
private:
    vector<Project> projects;
    Tester testerType;

public:
    QualityAssurance();
    QualityAssurance(const char*,const unsigned,const unsigned,const vector<Project>,const Tester);
    virtual unsigned salaryRaisePercent() const override{
        if(testerType==1){
            if(projects.size()==1){
                return 5;
            }
            if(projects.size()<4){
                return 10;
            }
            return 15;
        }
        unsigned temp=0;
        for(int i=0;i<projects.size();++i){
            temp+=projects[i].getProjectDifficulty();
        }
        unsigned result=temp/projects.size();
        if(temp<5){
            return 5;
        }
        if(temp<8){
            return 10;
        }
        return 15;
    }

};




#endif