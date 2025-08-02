#include"StafidiDark.h"

StafidiDarkChocolate::StafidiDarkChocolate(){
    DarkChocolate("S");
    StafidiChocolate();
}

StafidiDarkChocolate::StafidiDarkChocolate(int stafidiPercent,int cocoaPercent):DarkChocolate(cocoaPercent),StafidiChocolate(stafidiPercent)
{}

StafidiDarkChocolate::StafidiDarkChocolate(int stafidiPercent,int cocoaPercent,string id):StafidiChocolate(stafidiPercent)
{
    id="S"+id;
    DarkChocolate(id,cocoaPercent);
}