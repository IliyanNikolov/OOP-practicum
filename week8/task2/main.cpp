#include"Programmer.h"
#include"QA.h"
#include"Merindjei.h"



int main(){

    Programmer p1("Pesho",15,5000,"zle e polojenieto","Fortran");
    Programmer p2=p1;
    Programmer p3;
    Programmer p4=p3;
    p4=p2;

    QualityAssurance q1("Lelq Ginka",21,7000,"zle e polojenieto",automation);
    QualityAssurance q2=q1;
    QualityAssurance q3;
    QualityAssurance q4(q3);
    q4=q2;

    Manager m1("Chicho Gosho",30,15000,8);
    Manager m2=m1;
    Manager m3;
    Manager m4=m3;
    m4=m2;

}
