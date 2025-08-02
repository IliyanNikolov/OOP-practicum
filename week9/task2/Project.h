#ifndef IT_PROJECT_HEADER
#define IT_PROJECT_HEADER

#include<cstring>
#include<iostream>
using namespace std;

class Project{
private:
    char *projectName;
    unsigned projectDifficulty;
    void copying(const Project& other);
    void deleteing();

public:
    Project();
    Project(const Project&);
    Project& operator=(const Project&);
    ~Project();

    Project(Project&&);
    Project& operator=(Project&&);

    Project(const char*,const unsigned);
    unsigned getProjectDifficulty() const;

};



#endif