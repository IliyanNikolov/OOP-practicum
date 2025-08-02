#include"StafidiMilk.h"

StafidiMilkChocolate::StafidiMilkChocolate(){
    MilkChocolate::IDcounter=45;
    MilkChocolate();
    StafidiChocolate();
}

StafidiMilkChocolate::StafidiMilkChocolate(int milkPercent,int stafidiPercent):MilkChocolate(milkPercent),StafidiChocolate(stafidiPercent)
{}