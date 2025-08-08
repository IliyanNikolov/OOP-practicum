#include"Greenhouse.h"

void Greenhouse::copying(const Greenhouse& other){
    rowsInTheGreenhouse=new PotRow*[NUMBER_OF_COLUMNS];
    rowsInTheGreenhouse[SUNNY_ROW]=new PotRow(*(other.rowsInTheGreenhouse[SUNNY_ROW]));
    rowsInTheGreenhouse[NEUTRAL_ROW]=new PotRow(*(other.rowsInTheGreenhouse[NEUTRAL_ROW]));
    rowsInTheGreenhouse[SHADY_ROW]=new PotRow(*(other.rowsInTheGreenhouse[SHADY_ROW]));
    katalog=other.katalog;
}

void Greenhouse::deleteing(){
    delete[] rowsInTheGreenhouse[SUNNY_ROW];
    delete[] rowsInTheGreenhouse[NEUTRAL_ROW];
    delete[] rowsInTheGreenhouse[SHADY_ROW];
    delete[] rowsInTheGreenhouse;
}

bool Greenhouse::isGreenhouseFull() const{
    return rowsInTheGreenhouse[SUNNY_ROW]->isFull()
           && rowsInTheGreenhouse[NEUTRAL_ROW]->isFull()
           && rowsInTheGreenhouse[SHADY_ROW]->isFull();
}

Greenhouse::Greenhouse()
{
    rowsInTheGreenhouse=new PotRow*[NUMBER_OF_COLUMNS];
    for(int i=0;i<NUMBER_OF_COLUMNS;++i){
        rowsInTheGreenhouse[i]=nullptr;
    }
}

Greenhouse::Greenhouse(const Greenhouse& other){
    copying(other);
}

Greenhouse& Greenhouse::operator=(const Greenhouse& other){
    if(this!=&other){
        deleteing();
        copying(other);
    }
    return *this;
}

Greenhouse::~Greenhouse(){
    deleteing();
}

Greenhouse::Greenhouse(Greenhouse&& other){
    katalog=other.katalog;
    rowsInTheGreenhouse=other.rowsInTheGreenhouse;
    other.rowsInTheGreenhouse=nullptr;
}

Greenhouse& Greenhouse::operator=(Greenhouse&& other){
    if(this!=&other){
        deleteing();
        katalog=other.katalog;
        rowsInTheGreenhouse=other.rowsInTheGreenhouse;
        other.rowsInTheGreenhouse=nullptr;
    }
    return *this;
}

Greenhouse::Greenhouse(const PlantBook set,const unsigned sunnyPlaces,const unsigned neutralPlaces,const unsigned shadyPlaces){
    katalog=set;
    rowsInTheGreenhouse=new PotRow*[NUMBER_OF_COLUMNS];
    rowsInTheGreenhouse[SUNNY_ROW]=new PotRow(Sunny,sunnyPlaces);
    rowsInTheGreenhouse[NEUTRAL_ROW]=new PotRow(Neutral,neutralPlaces);
    rowsInTheGreenhouse[SHADY_ROW]=new PotRow(Shady,shadyPlaces);
}

void Greenhouse::addPlant(const Plant plantToAdd){
    int i=katalog.isPlantPresent(plantToAdd.getPlantName());
    if(i<0 || isGreenhouseFull()){// the plant isn't present in the current plantbook or there is no empty place for it
        return;
    }

    bool isSunnyRowFull  =rowsInTheGreenhouse[SUNNY_ROW]->isFull();
    bool isNeutralRowFull=rowsInTheGreenhouse[NEUTRAL_ROW]->isFull();
    bool isShadyRowFull  =rowsInTheGreenhouse[SHADY_ROW]->isFull();

    unsigned recommendedDaysWatering=katalog.getPlantDaysWateringByIndex(i);
    HabitPlace recommendedHabitPlace=katalog.getPlantHabitPlaceByIndex(i);

    if(!rowsInTheGreenhouse[recommendedHabitPlace-1]->isFull()){
        rowsInTheGreenhouse[recommendedHabitPlace-1]->addPlant(plantToAdd,recommendedDaysWatering,recommendedHabitPlace);
        return;
    }

    if(isSunnyRowFull && isShadyRowFull){
        rowsInTheGreenhouse[NEUTRAL_ROW]->addPlant(plantToAdd,recommendedDaysWatering,recommendedHabitPlace);
        return;
    }

    if(isSunnyRowFull && isNeutralRowFull){
        rowsInTheGreenhouse[SHADY_ROW]->addPlant(plantToAdd,recommendedDaysWatering,recommendedHabitPlace);
        return;
    }

    if(isNeutralRowFull && isShadyRowFull){
        rowsInTheGreenhouse[SUNNY_ROW]->addPlant(plantToAdd,recommendedDaysWatering,recommendedHabitPlace);
        return;
    }

    // only the column, in which the plant is suited for, is occupied
    if(isSunnyRowFull){
        rowsInTheGreenhouse[NEUTRAL_ROW]->addPlant(plantToAdd,recommendedDaysWatering,recommendedHabitPlace);
    }

    if(isNeutralRowFull){
        rowsInTheGreenhouse[SUNNY_ROW]->addPlant(plantToAdd,recommendedDaysWatering,recommendedHabitPlace);
    }

    if(isShadyRowFull){
        rowsInTheGreenhouse[NEUTRAL_ROW]->addPlant(plantToAdd,recommendedDaysWatering,recommendedHabitPlace);
    }
}

Plant Greenhouse::removePlant(const HabitPlace rowToRemoveFrom,const unsigned indexToRemove){
    return rowsInTheGreenhouse[rowToRemoveFrom-1]->removePlant(indexToRemove);
}

void Greenhouse::plantStatistics() const{
    cout<<"Number of plants on the sunny row: "<<rowsInTheGreenhouse[SUNNY_ROW]->getSize();
    cout<<"\nNumber of plants on the neutral row: "<<rowsInTheGreenhouse[NEUTRAL_ROW]->getSize();
    cout<<"\nNumber of plants on the shady row: "<<rowsInTheGreenhouse[SHADY_ROW]->getSize();
}

