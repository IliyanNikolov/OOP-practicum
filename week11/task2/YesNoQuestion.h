#ifndef YES_NO_QUESTION_HEADER
#define YES_NO_QUESTION_HEADER

#include"Question.h"

class YesNoQuestion: public Question{
private:
    string description;
    unsigned points;
    string givenAnswer;
    string correctAnswer;
    bool ifAsked=0;
public:
    YesNoQuestion() = default;
    
    YesNoQuestion(string description,int points,string correctAnswer)
    :description(description),points(points),correctAnswer(correctAnswer)
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
        if(givenAnswer==correctAnswer){
            return points;
        }
        return 0;
    }

    virtual Question* clone() const override{
        return new YesNoQuestion(*this);
    }


};



#endif