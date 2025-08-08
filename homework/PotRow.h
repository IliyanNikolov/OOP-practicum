#ifndef POT_ROW_HEADER
#define POT_ROW_HEADER

#include"PotPlace.h"



class PotRow{
private:
    HabitPlace rowHabit;
    PotPlace **plantsInRow;
    unsigned capacity;
    unsigned size;
    void copying(const PotRow&);
    void deleteing();

public:
    PotRow();
    PotRow(const PotRow&);
    PotRow& operator=(const PotRow&);
    ~PotRow();

    PotRow(PotRow&&);
    PotRow& operator=(PotRow&&);

    PotRow(const HabitPlace,const unsigned);
    bool isFull()const;

    void addPlant(const Plant,const unsigned,const HabitPlace);
    Plant removePlant(const int);
    unsigned getCapacity()const;
    unsigned getSize()const;
};




#endif