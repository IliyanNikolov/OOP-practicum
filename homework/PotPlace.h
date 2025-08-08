#ifndef POT_PLACE_HEADER
#define POT_PLACE_HEADER

#include"Plant.h"

class PotPlace{
private:
    Plant plant;
    HabitPlace rowHabitPlace;
    bool isItOccupied;

public:
    bool isEmptyPlace()const;
    PotPlace(const HabitPlace);
    PotPlace(const HabitPlace,const Plant);
    void addPlant(const Plant,const unsigned,const HabitPlace);
    Plant removePlant();
    PotPlace();

};





#endif