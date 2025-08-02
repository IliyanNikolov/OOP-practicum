#include"CatsAndDogs.h"


int main(){
    Container c1;

    Animal* p1=new Cat("cat1","type1");
    Animal* p2=new Cat("cat2","type2");
    Animal* p3=new Cat("cat3","type3");
    Animal* p4=new Cat("cat4","type4");
    Animal* p5=new Cat("cat5","type5");
    Animal* p6=new Dog("dog1","type6");
    Animal* p7=new Dog("dog2","type7");
    Animal* p8=new Dog("dog3","type8");
    Animal* p9=new Dog("dog4","type9");
    Animal* p10=new Dog("dog5","type10");

    c1.addAnimal(p1);
    c1.addAnimal(p2);
    c1.addAnimal(p3);
    c1.addAnimal(p4);
    c1.addAnimal(p5);
    c1.addAnimal(p6);
    c1.addAnimal(p7);
    c1.addAnimal(p8);
    c1.addAnimal(p9);
    c1.addAnimal(p10);

    c1.print();

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

}