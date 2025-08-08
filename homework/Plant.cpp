#include"Plant.h"

void Plant::copying(const Plant& other){
    habitPlace=other.habitPlace;
    daysWateringFrequency=other.daysWateringFrequency;
    name=new char[strlen(other.name)+1];
    strcpy(name,other.name);
}

void Plant::deleteing(){
    delete[] name;
}

Plant::Plant(){
    name=nullptr;
}

Plant::Plant(const Plant& other){
    copying(other);
}

Plant& Plant::operator=(const Plant& other){
    if(this!=&other){
        deleteing();
        copying(other);
    }
    return *this;
}

Plant::~Plant(){
    deleteing();
}

Plant::Plant(Plant&& other){
    habitPlace=other.habitPlace;
    daysWateringFrequency=other.daysWateringFrequency;
    name=other.name;
    other.name=nullptr;
}

Plant& Plant::operator=(Plant&& other){
    if(this!=&other){
        deleteing();
        habitPlace=other.habitPlace;
        daysWateringFrequency=other.daysWateringFrequency;
        name=other.name;
        other.name=nullptr;
    }
    return *this;
}

istream& operator>>(istream& is,Plant& inPlant){
    delete[] inPlant.name;
    char buffer[1024];
    // cout<<"Name of the plant: ";
    is.getline(buffer,1024);
    inPlant.name=new char[strlen(buffer)+1];
    strcpy(inPlant.name,buffer);
    // cout<<"Habit place of the plant(type 0 ,if you don't want to specify): ";
    // is>>buffer;
    // if(strcmp(buffer,"0")!=0){
    //     if(strcmp(buffer,"Sunny")==0){
    //         inPlant.habitPlace=Sunny;
    //     }
    //     if(strcmp(buffer,"Neutral")==0){
    //         inPlant.habitPlace=Neutral;
    //     }
    //     if(strcmp(buffer,"Shady")==0){
    //         inPlant.habitPlace=Shady;
    //     }
    // }
    // cout<<"Number of days in which the plant must be watered(type 0 ,if you don't want to specify): ";
    // is>>buffer;
    // if(strcmp(buffer,"0")!=0){
    //     int temp=atoi(buffer);
    //     if(temp>1){
    //         inPlant.daysWateringFrequency=temp;
    //     }
    // }
    return is;
}

ostream& operator<<(ostream& os,const Plant& outPlant){
    os<<outPlant.name;
    return os;
}

Plant::Plant(const char* inputName):habitPlace(Neutral),daysWateringFrequency(3)
{
    name=new char[strlen(inputName)+1];
    strcpy(name,inputName);
}

// Plant::Plant(const char* inputName,HabitPlace habit,unsigned days):habitPlace(habitPlace),daysWateringFrequency(days)
// {
//     name=new char[strlen(inputName)+1];
//     strcpy(name,inputName);
// }

// Plant::Plant(const char* inputName,HabitPlace habitPlace):habitPlace(habitPlace)
// {
    
//     name=new char[strlen(inputName)+1];
//     strcpy(name,inputName);
// }

// Plant::Plant(const char* inputName,unsigned days):daysWateringFrequency(days)
// {
//     name=new char[strlen(inputName)+1];
//     strcpy(name,inputName);
// }

char* Plant::getPlantName()const{
    return name;
}

// HabitPlace Plant::getHabitPlace()const{
//     return habitPlace;
// }

// unsigned Plant::getWateringFrequencyDays()const{
//     return daysWateringFrequency;
// }

void Plant::setHabitPlace(const HabitPlace habitPlace){
    this->habitPlace=habitPlace;
}

void Plant::setDaysWatering(const unsigned days){
    daysWateringFrequency=days;
}


