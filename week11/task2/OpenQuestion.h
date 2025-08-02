#ifndef OPEN_QUESTION_HEADER
#define OPEN_QUESTION_HEADER

#include"Question.h"

class OpenQuestion: public Question{
private:
    string description;
    unsigned points;
    string givenAnswer;
    bool ifAsked=0;

public:
    OpenQuestion() = default;
    
    OpenQuestion(string description,int points)
    :description(description),points(points)
    {}

    virtual void ask() override{
        cout<<description;
        cout<<endl;
        cin>>givenAnswer;
        ifAsked=1;
    }

    virtual int grade() override{
        if(!ifAsked){
            return 0;
        }
        cout<<"question's description: "<<description<<"\n"<<"given answer: "<<givenAnswer<<"\n";
        int percents;
        do{
            cin>>percents;
        }while(percents<0 || percents>100);
        return (percents*points)/100;
    }

    virtual Question* clone() const override{
        return new OpenQuestion(*this);
    }


};









#endif