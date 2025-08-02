#include"Test.h"



int main(){
    Test c1;

    Question* p1=new YesNoQuestion("cat1",5,"type1");
    Question* p2=new YesNoQuestion("cat2",15,"type2");
    Question* p3=new YesNoQuestion("cat3",152,"type3");
    Question* p4=new YesNoQuestion("cat4",45,"type4");
    Question* p5=new YesNoQuestion("cat5",10,"type5");
    Question* p6=new OpenQuestion("dog1",1);
    Question* p7=new OpenQuestion("dog2",12);
    Question* p8=new OpenQuestion("dog3",123);
    Question* p9=new OpenQuestion("dog4",1234);
    Question* p10=new OpenQuestion("dog5",451);

    c1.addQuestion(p1);
    c1.addQuestion(p2);
    c1.addQuestion(p3);
    c1.addQuestion(p4);
    c1.addQuestion(p5);
    c1.addQuestion(p6);
    c1.addQuestion(p7);
    c1.addQuestion(p8);
    c1.addQuestion(p9);
    c1.addQuestion(p10);

    c1.doTest();


    long long var1=c1.gradeTest();
    cout<<var1;

    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;
    delete p6;
    delete p7;
    delete p8;
    delete p9;
    delete p10;

// cat1
// type1
// cat2
// type2
// cat3
// fsg
// cat4
// type4
// cat5
// type5
// dog1
// a    
// dog2
// d
// dog3
// c
// dog4
// e
// dog5
// g
// question's description: dog1
// given answer: a
// 100
// question's description: dog2
// given answer: d
// 100
// question's description: dog3
// given answer: c
// 0
// question's description: dog4
// given answer: e
// 0
// question's description: dog5
// given answer: g
// 0
// 88

    return 0;
}