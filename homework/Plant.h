#ifndef ACTUAL_PLANT_HEADER
#define ACTUAL_PLANT_HEADER


#include"PlantBook.h"


class Plant{
private:
    char *name;
    HabitPlace habitPlace;
    unsigned daysWateringFrequency;

    void copying(const Plant&);
    void deleteing();

public:
    Plant();
    Plant(const Plant&);
    Plant& operator=(const Plant&);
    ~Plant();
    Plant(Plant&&);
    Plant& operator=(Plant&&);

    friend istream& operator>>(istream&,Plant&);
    friend ostream& operator<<(ostream&,const Plant&);
    
    Plant(const char*);
    // Plant(const char*,HabitPlace,unsigned);
    // Plant(const char*,HabitPlace);
    // Plant(const char*,unsigned);
    
    char* getPlantName()const;
    // HabitPlace getHabitPlace()const;
    // unsigned getWateringFrequencyDays()const;

    void setHabitPlace(const HabitPlace);
    void setDaysWatering(const unsigned);


};




#endif