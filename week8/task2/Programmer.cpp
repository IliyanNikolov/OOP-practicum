#include"Programmer.h"

Programmer::Programmer():Employee()
{}

Programmer::Programmer(const char* name,const unsigned months,const unsigned salary,const char* project,const char* language)
:Employee(name,months,salary),project(project),programmingLanguage(language)
{}