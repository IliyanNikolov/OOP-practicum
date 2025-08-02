#include"Programmer_3.h"

Programmer::Programmer():Employee()
{}

Programmer::Programmer(const char* name,const unsigned months,const unsigned salary,vector<Project> projects,const char* language)
:Employee(name,months,salary),project(project),programmingLanguage(language)
{}

void Programmer::addProject(Project toAdd){
    project.push_back(toAdd);
}

void Programmer::removeProject(int indexToRemove){
    if(indexToRemove<project.size() && indexToRemove>=0){
        for(int i=indexToRemove;i<project.size()-1;++i){
            project[i]=project[i+1];
        }
        project.pop_back();
    }
}