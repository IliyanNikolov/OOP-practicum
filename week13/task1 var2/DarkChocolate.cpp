#include"DarkChocolate.h"

DarkChocolate::DarkChocolate(){
    cocoaPercentage=80;
    this->id="\0";
}

DarkChocolate::DarkChocolate(int cocoaPercentage)
{
    while(cocoaPercentage<0 && cocoaPercentage>100){
        cin>>cocoaPercentage;
    }
    this->cocoaPercentage=cocoaPercentage;
    this->id="\0";
}

DarkChocolate::DarkChocolate(string id){
    bool b=0;
    for(int i=0;i<id.size();++i){
        if((id[i]>=65 && id[i]<=90) || (id[i]>=97 && id[i]<=122)){
            continue;
        }
        b=1;
    }
    if(!b){
        this->id=id;
    }
    else{
        this->id="\0";
    }
    cocoaPercentage=80;
}

DarkChocolate::DarkChocolate(string id,int cocoaPercentage)
{
    while(cocoaPercentage<0 && cocoaPercentage>100){
        cin>>cocoaPercentage;
    }
    bool b=0;
    for(int i=0;i<id.size();++i){
        if((id[i]>=65 && id[i]<=90) || (id[i]>=97 && id[i]<=122)){
            continue;
        }
        b=1;
    }
    if(!b){
        this->id=id;
    }
    else{
        this->id="\0";
    }
    this->cocoaPercentage=cocoaPercentage;
}
