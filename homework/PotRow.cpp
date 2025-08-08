#include"PotRow.h"

void PotRow::copying(const PotRow& other){
    rowHabit=other.rowHabit;
    capacity=other.capacity;
    size=other.size;
    plantsInRow=new PotPlace*[capacity];
    for(int i=0;i<capacity;++i){
        plantsInRow[i]=other.plantsInRow[i];
    }
}

void PotRow::deleteing(){
    for(int i=0;i<capacity;++i){
        delete[] plantsInRow[i];
    }
    delete[] plantsInRow;
}

PotRow::PotRow(){
    plantsInRow=nullptr;
}

PotRow::PotRow(const PotRow& other){
    copying(other);
}

PotRow& PotRow::operator=(const PotRow& other){
    if(this!=&other){
        deleteing();
        copying(other);
    }
    return *this;
}

PotRow::~PotRow(){
    deleteing();
}

PotRow::PotRow(PotRow&& other){
    capacity=other.capacity;
    size=other.size;
    plantsInRow=other.plantsInRow;
    rowHabit=other.rowHabit;
    other.plantsInRow=nullptr;
}

PotRow& PotRow::operator=(PotRow&& other){
    if(this!=&other){
        deleteing();
        capacity=other.capacity;
        size=other.size;
        plantsInRow=other.plantsInRow;
        rowHabit=other.rowHabit;
        other.plantsInRow=nullptr;
    }
    return *this;
}

PotRow::PotRow(const HabitPlace rowHabit,const unsigned initialCapacity)
:rowHabit(rowHabit),capacity(initialCapacity)
{
    size=0;
    plantsInRow=new PotPlace*[capacity];
    for(int i=0;i<capacity;++i){
        plantsInRow[i]=new PotPlace(rowHabit);
    }
}

bool PotRow::isFull() const{
    return size==capacity;
}

void PotRow::addPlant(const Plant toAdd,const unsigned recommendedDaysWatering,const HabitPlace recommendedHabitPlace){
    int i=0;
    while(!plantsInRow[i]->isEmptyPlace()){
        ++i;
    }
    plantsInRow[i]->addPlant(toAdd,recommendedDaysWatering,recommendedHabitPlace);
    ++size;
}

Plant PotRow::removePlant(const int toRemove){
    if(toRemove<0 && toRemove>=capacity){
        throw runtime_error("There's no such index in the current column!");
    }
    return plantsInRow[toRemove]->removePlant();
}

unsigned PotRow::getCapacity() const{
    return capacity;
}

unsigned PotRow::getSize() const{
    return size;
}
