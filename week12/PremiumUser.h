#ifndef PREMIUM_SYSTEM_USER_HEADER
#define PREMIUM_SYSTEM_USER_HEADER

#include"CommonUser.h"


class PremiumUser: public CommonUser{
private:
    std::string premiumPlanDescription;
    std::vector<std::string> paymentDates;

public:
    PremiumUser();
    PremiumUser(std::string,std::string,std::string,std::vector<std::string>);
    PremiumUser(CommonUser,std::string,std::vector<std::string>);


};







#endif