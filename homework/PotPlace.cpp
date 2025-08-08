#include"PotPlace.h"

bool PotPlace::isEmptyPlace() const{
    return isItOccupied==0;
}

PotPlace::PotPlace(const HabitPlace rowHabitPlace):rowHabitPlace(rowHabitPlace)
{
    isItOccupied=0;
}

PotPlace::PotPlace(const HabitPlace rowHabitPlace,const Plant plant):rowHabitPlace(rowHabitPlace),plant(plant)
{
    isItOccupied=1;
}

void PotPlace::addPlant(const Plant plantToAdd,const unsigned recommendedDaysWatering,const HabitPlace recommendedHabitPlace){
    plant=plantToAdd;
    plant.setHabitPlace(rowHabitPlace);


    int diff=recommendedHabitPlace-rowHabitPlace;// it's complicated, but works
    if(abs(diff)>=recommendedDaysWatering && diff<0){
        plant.setDaysWatering(1);
    }
    else{
        plant.setDaysWatering(recommendedDaysWatering+diff);
    }

    // if(rowHabitPlace=recommendedHabitPlace){
    //     plant.setDaysWatering(recommendedDaysWatering);
    // }
    
    // if(rowHabitPlace==1 && recommendedHabitPlace==3){
    //     plant.setDaysWatering(recommendedDaysWatering+2);
    // }

    // if(recommendedHabitPlace-rowHabitPlace==1){
    //     plant.setDaysWatering(recommendedDaysWatering+1);
    // }

    // if(recommendedHabitPlace-rowHabitPlace==-1){
    //     if(recommendedDaysWatering==1){
    //         plant.setDaysWatering(recommendedDaysWatering);
    //     }
    //     else{
    //         plant.setDaysWatering(recommendedDaysWatering-1);
    //     }
    // }

    // if(recommendedHabitPlace-rowHabitPlace==-2){
    //     if(recommendedDaysWatering==1 || recommendedDaysWatering==2){
    //         plant.setDaysWatering(1);
    //     }
    //     else{
    //         plant.setDaysWatering(recommendedDaysWatering-2);
    //     }
    // }

    isItOccupied=1;
}

Plant PotPlace::removePlant(){
    if(!isItOccupied){
        throw runtime_error("The place is empty");
    }
    isItOccupied=0;
    return plant;
}

PotPlace::PotPlace()
{
    isItOccupied=0;
}
