#include"set.h"

int main(){


    Set set1;
    for(int i=1;i<11;++i){
        set1.addElement(i);
    }
    
    Set set2(set1);
    for(int i=8;i<19;++i){
        set2.addElement(i);
    }

    Set set3=set1+set2;
    set3.print();
    set3+2;
    3+set3;
    set3.print();




}