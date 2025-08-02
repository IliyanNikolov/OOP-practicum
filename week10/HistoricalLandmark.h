#ifndef HISTORICAL_LANDMARK_H
#define HISTORICAL_LANDMARK_H

#include"Landmark.h"

class HistoricalLandmark: public Landmark{
private:
    int yearOfEvent;

public:
    HistoricalLandmark() = default;
    HistoricalLandmark(std::string,std::string,int);

    friend std::istream& operator>>(std::istream&,HistoricalLandmark&);
    friend std::ostream& operator<<(std::ostream&,const HistoricalLandmark&);

};




#endif