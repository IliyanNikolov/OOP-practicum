#ifndef MULTIPLE_CHOICE_QUESTION_HEADER
#define MULTIPLE_CHOICE_QUESTION_HEADER

#include"Question.h"


class MultipleChoice: public Question{
private:
    string description;
    unsigned points;
    string givenAnswer;
    vector<string> correctAnswers;
    bool ifAsked=0;

public:
    MultipleChoice() = default;
    
    MultipleChoice(string description,int points,vector<string> correctAnswers)
    :description(description),points(points),correctAnswers(correctAnswers)
    {}

    virtual void ask() override{
        cout<<description;
        cout<<endl;
        cin>>givenAnswer;
        ifAsked=1;
    }

    virtual int grade() override{
        if(!ifAsked){
            throw runtime_error("there is no given answer to the question");
        }
        bool b=0;
        for(int i=0;i<correctAnswers.size();++i){
            if(givenAnswer==correctAnswers[i]){
                b=1;
            }
        }
        if(b){
            return points;
        }
        int negativePoints=-points;
        return points;
    }

    virtual Question* clone() const override{
        return new MultipleChoice(*this);
    }
    
};





#endif