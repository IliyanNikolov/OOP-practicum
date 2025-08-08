#include"PlantInfo.h"

void PlantInfo::copying(const PlantInfo& other){
    plantName=new char[strlen(other.plantName)+1];
    strcpy(plantName,other.plantName);
    bestHabitPlace=other.bestHabitPlace;
    prefferedDaysWatering=other.prefferedDaysWatering;
}

void PlantInfo::deleteing(){
    delete[] plantName;
}

PlantInfo::PlantInfo(){
    plantName=nullptr;
}

PlantInfo::PlantInfo(const PlantInfo& other){
    copying(other);
}

PlantInfo& PlantInfo::operator=(const PlantInfo& other){
    if(this!=&other){
        deleteing();
        copying(other);
    }
    return *this;
}

PlantInfo::~PlantInfo(){
    deleteing();
}

PlantInfo::PlantInfo(PlantInfo&& other){
    plantName=other.plantName;
    other.plantName=nullptr;
    bestHabitPlace=other.bestHabitPlace;
    prefferedDaysWatering=other.prefferedDaysWatering;
}

PlantInfo& PlantInfo::operator=(PlantInfo&& other){
    if(this!=&other){
        deleteing();
        plantName=other.plantName;
        other.plantName=nullptr;
        bestHabitPlace=other.bestHabitPlace;
        prefferedDaysWatering=other.prefferedDaysWatering;
    }
    return *this;
}

istream& operator>>(istream& is,PlantInfo& inPlant){
    unsigned nameSize;
    is>>nameSize;
    is.get();
    inPlant.plantName=new char[nameSize+1];
    is>>inPlant.plantName;
    is.get();
    char temp[100];
    is>>temp;
    if(strcmp(temp,"Sunny")==0){
        inPlant.bestHabitPlace=Sunny;
    }
    if(strcmp(temp,"Neutral")==0){
        inPlant.bestHabitPlace=Neutral;
    }
    if(strcmp(temp,"Shady")==0){
        inPlant.bestHabitPlace=Shady;
    }
    is.get();
    is>>inPlant.prefferedDaysWatering;
    is.get();
    return is;
}

ostream& operator<<(ostream& os,const PlantInfo& outPlant){
    os<<strlen(outPlant.plantName)<<" "<<outPlant.plantName<<" ";
    if(outPlant.bestHabitPlace==1){
        os<<"Sunny";
    }
    else if(outPlant.bestHabitPlace==3){
        os<<"Shady";
    }
    else{
        os<<"Neutral";
    }
    os<<" ";
    if(outPlant.prefferedDaysWatering==0){
        os<<3;
    }
    else{
        os<<outPlant.prefferedDaysWatering;
    }
    return os;
}

PlantInfo::PlantInfo(const char *name){
    plantName=new char[strlen(name)+1];
    strcpy(plantName,name);
}

PlantInfo::PlantInfo(const char *name,const HabitPlace habitPlace):bestHabitPlace(habitPlace)
{
    plantName=new char[strlen(name)+1];
    strcpy(plantName,name);
}

PlantInfo::PlantInfo(const char *name,const unsigned days):prefferedDaysWatering(days)
{
    plantName=new char[strlen(name)+1];
    strcpy(plantName,name);
}

PlantInfo::PlantInfo(const char *name,const HabitPlace habitPlace,const unsigned days)
:bestHabitPlace(habitPlace),prefferedDaysWatering(days)
{
    plantName=new char[strlen(name)+1];
    strcpy(plantName,name);
}

const char* PlantInfo::getPlantName()const{
    return plantName;
}

const HabitPlace PlantInfo::getHabitPlace()const{
    return bestHabitPlace;
}

const unsigned PlantInfo::getDaysWatering()const{
    return prefferedDaysWatering;
}

void PlantInfo::setHabitPlace(const HabitPlace inputHabitPlace){
    bestHabitPlace=inputHabitPlace;
}

void PlantInfo::setDaysWatering(const unsigned days){
    prefferedDaysWatering=days;
}

