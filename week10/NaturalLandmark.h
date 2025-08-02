#ifndef NATURAL_LANDMARK_HEADER
#define NATURAL_LANDMARK_HEADER

#include"Landmark.h"

class NaturalLandmark: public Landmark{
private:
    unsigned startOfPeriod;//in months
    unsigned endOfPeriod;  //in months

public:
    NaturalLandmark() = default;
    NaturalLandmark(std::string,std::string,unsigned,unsigned);

    friend std::istream& operator>>(std::istream&,NaturalLandmark&);
    friend std::ostream& operator<<(std::ostream&,const NaturalLandmark&);

};

NaturalLandmark::NaturalLandmark(std::string coordinates,std::string description,unsigned start,unsigned end)
:Landmark(coordinates,description)
{
    startOfPeriod=start;
    endOfPeriod=end;
}

std::istream& operator>>(std::istream& is,NaturalLandmark& inLandmark){
    // Landmark::operator>>(is,((Landmark&)inLandmark));
    is>>((Landmark&)inLandmark);
    unsigned temp;
    is>>temp;
    inLandmark.startOfPeriod=temp;
    is>>temp;
    inLandmark.endOfPeriod=temp;
    return is;
}

std::ostream& operator<<(std::ostream& os,const NaturalLandmark& outLandmark){
    os<<((Landmark&)outLandmark);
    os<<" "<<outLandmark.startOfPeriod<<" "<<outLandmark.endOfPeriod;
    return os;
}





#endif