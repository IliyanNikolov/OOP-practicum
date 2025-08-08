#ifndef GREENHOUSE_HEADER
#define GREENHOUSE_HEADER

#include"PotRow.h"

const int NUMBER_OF_COLUMNS=3;
const int SUNNY_ROW=0;
const int NEUTRAL_ROW=1;
const int SHADY_ROW=2;

class Greenhouse{
private:
    PotRow **rowsInTheGreenhouse;
    PlantBook katalog;
    void copying(const Greenhouse&);
    void deleteing();
    bool isGreenhouseFull() const;

public:
    Greenhouse();
    Greenhouse(const Greenhouse&);
    Greenhouse& operator=(const Greenhouse&);
    ~Greenhouse();

    Greenhouse(Greenhouse&&);
    Greenhouse& operator=(Greenhouse&&);

    Greenhouse(const PlantBook,const unsigned,const unsigned,const unsigned);

    void addPlant(const Plant);
    Plant removePlant(const HabitPlace,const unsigned);
    void plantStatistics()const;

};


#endif