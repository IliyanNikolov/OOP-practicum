#ifndef PROJECT_IT_HEADER
#define PROJECT_IT_HEADER

#include<string>
#include<vector>
#include<iostream>
using namespace std;

enum Difficulty{
    one=1,
    two,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,
    ten
};

class Project{
private:
    string projectName;
    Difficulty projectDifficulty;
public:
    Project();
    Project(string,Difficulty);
    const string getProjectName() const;
    const Difficulty getProjectDifficulty() const;

};



#endif