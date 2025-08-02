#include"HistoricalLandmark.h"

HistoricalLandmark::HistoricalLandmark(std::string coordinates,std::string description,int yearOfEvent)
:Landmark(coordinates,description)
{
    this->yearOfEvent=yearOfEvent;
}

std::istream& operator>>(std::istream& is,HistoricalLandmark& inLandmark){
    // Landmark::operator>>(is,((Landmark&)inLandmark));
    is>>((Landmark&)inLandmark);
    int temp;
    is>>temp;
    inLandmark.yearOfEvent=temp;
    return is;
}

std::ostream& operator<<(std::ostream& os,const HistoricalLandmark& outLandmark){
    os<<((Landmark&)outLandmark);
    os<<" "<<outLandmark.yearOfEvent;
    return os;
}