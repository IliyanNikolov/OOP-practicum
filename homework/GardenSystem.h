#ifndef GARDEN_SYSTEM
#define GARDEN_SYSTEM

#include"Greenhouse.h"

class GardenSystem{
private:
    Greenhouse *greenhouse;
    PlantBook bookOfPlants;
    void copying(const GardenSystem&);
    void deleteing();

public:
    GardenSystem();
    GardenSystem(const GardenSystem&);
    GardenSystem& operator=(const GardenSystem&);
    ~GardenSystem();

    GardenSystem(GardenSystem&&);
    GardenSystem& operator=(GardenSystem&&);
    
    GardenSystem(const Greenhouse,const PlantBook);
    GardenSystem(const PlantBook,const unsigned,const unsigned,const unsigned);
    void addPlantToTheGreenhouse(const Plant);
    void getGreenhousePlantStatistics() const;
    Plant removePlantFromGreenhouse(const HabitPlace,const unsigned);
    void printBookOfPlants() const;
    

};




#endif