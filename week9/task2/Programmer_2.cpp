#include"Programmer_2.h"

Programmer::Programmer():Employee()
{}

Programmer::Programmer(const char* name,const unsigned months,const unsigned salary,const vector<Project> projects,const char* language)
:Employee(name,months,salary),projects(projects),programmingLanguage(language)
{}