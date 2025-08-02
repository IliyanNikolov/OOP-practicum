#include"MilkChocolate.h"

MilkChocolate::MilkChocolate(){
    ID=IDcounter;
    ++IDcounter;
    milkPercentage=35;
}

MilkChocolate::MilkChocolate(int milkPercentage){
    while(milkPercentage<0 && milkPercentage>100){
        cin>>milkPercentage;
    }
    this->milkPercentage=milkPercentage;
    ID=IDcounter;
    ++IDcounter;
}

int MilkChocolate::IDcounter=1;