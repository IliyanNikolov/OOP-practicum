#include"GardenSystem.h"

void GardenSystem::copying(const GardenSystem& other){
    greenhouse=new Greenhouse(other.greenhouse[0]);
    bookOfPlants=other.bookOfPlants;
}

void GardenSystem::deleteing(){
    delete[] greenhouse;
}

GardenSystem::GardenSystem()
{
    greenhouse=new Greenhouse();
}

GardenSystem::GardenSystem(const GardenSystem& other){
    copying(other);
}

GardenSystem& GardenSystem::operator=(const GardenSystem& other){
    if(this!=&other){
        deleteing();
        copying(other);
    }
    return *this;
}

GardenSystem::~GardenSystem(){
    deleteing();
}

GardenSystem::GardenSystem(GardenSystem&& other){
    greenhouse=other.greenhouse;
    bookOfPlants=other.bookOfPlants;
    other.greenhouse=nullptr;
}

GardenSystem& GardenSystem::operator=(GardenSystem&& other){
    if(this!=&other){
        deleteing();
        greenhouse=other.greenhouse;
        bookOfPlants=other.bookOfPlants;
        other.greenhouse=nullptr;
    }
    return *this;
}

GardenSystem::GardenSystem(const Greenhouse greenhouse,const PlantBook bookOfPlants){
    this->greenhouse=new Greenhouse(greenhouse);
    this->bookOfPlants=bookOfPlants;
}

GardenSystem::GardenSystem(const PlantBook bookOfPlants,const unsigned sunnyPlaces,const unsigned neutralPlaces,const unsigned shadyPlaces){
    greenhouse=new Greenhouse(bookOfPlants,sunnyPlaces,neutralPlaces,shadyPlaces);
    this->bookOfPlants=bookOfPlants;
}

void GardenSystem::addPlantToTheGreenhouse(const Plant toAdd){
    greenhouse[0].addPlant(toAdd);
}

void GardenSystem::getGreenhousePlantStatistics() const{
    greenhouse[0].plantStatistics();
}

Plant GardenSystem::removePlantFromGreenhouse(const HabitPlace rowToRemoveFrom,const unsigned indexToRemove){
    return greenhouse[0].removePlant(rowToRemoveFrom,indexToRemove);
}

void GardenSystem::printBookOfPlants() const{
    cout<<bookOfPlants;
}