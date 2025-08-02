#include"ProjectFirmaIt.h"

Project::Project(string name,Difficulty diff):projectName(name),projectDifficulty(diff)
{}

const string Project::getProjectName() const{
    return projectName;
}

const Difficulty Project::getProjectDifficulty() const{
    return projectDifficulty;
}