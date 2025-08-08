#ifndef PLANT_BOOK_HEADER
#define PLANT_BOOK_HEADER

#include"PlantInfo.h"


class PlantBook{
private:
    PlantInfo *plants;
    unsigned capacity;
    unsigned size;
    char bookName[128];

    void resize();
    void copying(const PlantBook&);
    void deleteing();
    void readFromFile();
    void writeToFile();

public:
    PlantBook();
    PlantBook(const PlantBook&);
    PlantBook& operator=(const PlantBook&);
    ~PlantBook();
    
    PlantBook(PlantBook&&);
    PlantBook& operator=(PlantBook&&);
    
    PlantBook(const char*);
    void addPlantType(const PlantInfo&);
    void setBookName(const char*);
    
    friend istream& operator>>(istream&,PlantBook&);
    friend ostream& operator<<(ostream&,const PlantBook&);

    int isPlantPresent(const char*);
    unsigned getPlantDaysWateringByIndex(const int);
    HabitPlace getPlantHabitPlaceByIndex(const int);
    

};


#endif