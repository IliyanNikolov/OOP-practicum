#include"QA.h"

QualityAssurance::QualityAssurance()
{}

QualityAssurance::QualityAssurance(const char* name,const unsigned month,const unsigned salary,const char *project,const Tester testerType)
:Employee(name,month,salary),project(project),testerType(testerType)
{}