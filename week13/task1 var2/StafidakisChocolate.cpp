#include"StafidakisChocolate.h"

StafidiChocolate::StafidiChocolate(){
    stafidiPercentage=20;
}

StafidiChocolate::StafidiChocolate(int stafidiPercentage){
    while(stafidiPercentage<0 && stafidiPercentage>100){
        cin>>stafidiPercentage;
    }
    this->stafidiPercentage=stafidiPercentage;
}