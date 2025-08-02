#include"QA_2.h"

QualityAssurance::QualityAssurance()
{}

QualityAssurance::QualityAssurance(const char* name,const unsigned month,const unsigned salary,const vector<Project> projects,const Tester testerType)
:Employee(name,month,salary),projects(projects),testerType(testerType)
{}