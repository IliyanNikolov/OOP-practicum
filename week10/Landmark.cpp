#include"Landmark.h"

Landmark::Landmark(std::string coordinates,std::string description)
:coordinates(coordinates),description(description)
{}

std::istream& operator>>(std::istream& is,Landmark& inLandmark){
    std::string temp;
    is>>temp;
    inLandmark.coordinates=temp;
    is>>temp;
    inLandmark.description=temp;
    return is;
}

std::ostream& operator<<(std::ostream& os,const Landmark& outLandmark){
    os<<outLandmark.coordinates<<" "<<outLandmark.description;
    return os;
}