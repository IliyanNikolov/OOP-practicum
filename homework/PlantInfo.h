#ifndef PLANT_INFORMATION_HEADER
#define PLANT_INFORMATION_HEADER

#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

enum HabitPlace{
    Sunny=1,
    Neutral,
    Shady
};


class PlantInfo{
private:
    char *plantName;
    HabitPlace bestHabitPlace;
    unsigned prefferedDaysWatering;
    void copying(const PlantInfo&);
    void deleteing();
public:
    PlantInfo();
    PlantInfo(const PlantInfo&);
    PlantInfo& operator=(const PlantInfo&);
    ~PlantInfo();

    PlantInfo(PlantInfo&&);
    PlantInfo& operator=(PlantInfo&&);

    friend istream& operator>>(istream&,PlantInfo&);
    friend ostream& operator<<(ostream&,const PlantInfo&);

    PlantInfo(const char*);
    PlantInfo(const char*,const HabitPlace);
    PlantInfo(const char*,const unsigned);
    PlantInfo(const char*,const HabitPlace,const unsigned);

    const char* getPlantName()const;
    const HabitPlace getHabitPlace()const;
    const unsigned getDaysWatering()const;

    void setHabitPlace(const HabitPlace);
    void setDaysWatering(const unsigned);

};




#endif