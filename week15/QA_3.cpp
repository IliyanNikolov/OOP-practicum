#include"QA_3.h"

QualityAssurance::QualityAssurance()
{}

QualityAssurance::QualityAssurance(const char* name,const unsigned month,const unsigned salary,vector<Project> projects,const Tester testerType)
:Employee(name,month,salary),project(projects),testerType(testerType)
{}

void QualityAssurance::addProject(Project toAdd){
    project.push_back(toAdd);
}

void QualityAssurance::removeProject(int indexToRemove){
    if(indexToRemove<project.size() && indexToRemove>=0){
        for(int i=indexToRemove;i<project.size()-1;++i){
            project[i]=project[i+1];
        }
        project.pop_back();
    }
}

