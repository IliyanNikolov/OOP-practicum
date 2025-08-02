#include"Project.h"

void Project::copying(const Project& other){
    projectDifficulty=other.projectDifficulty;
    projectName=new char[strlen(other.projectName)+1];
    strcpy(projectName,other.projectName);
}

void Project::deleteing(){
    delete[] projectName;
}

Project::Project(){
    projectName=nullptr;
    projectDifficulty=0;
}

Project::Project(const Project& other){
    copying(other);
}

Project& Project::operator=(const Project& other){
    if(this!=&other){
        deleteing();
        copying(other);
    }
    return *this;
}

Project::~Project(){
    deleteing();
}

Project::Project(Project&& other){
    projectDifficulty=other.projectDifficulty;
    projectName=other.projectName;
    other.projectName=nullptr;
}

Project& Project::operator=(Project&& other){
    if(this!=&other){
        deleteing();
        projectDifficulty=other.projectDifficulty;
        projectName=other.projectName;
        other.projectName=nullptr;
    }
    return *this;
}

Project::Project(const char *name,const unsigned diff){
    if(diff>10 || diff<1){
        throw runtime_error("Invalid difficulty level!");
    }
    else{
        projectDifficulty=diff;
    }
    projectName=new char[strlen(name)+1];
    strcpy(projectName,name);
}

unsigned Project::getProjectDifficulty() const{
    return projectDifficulty;
}