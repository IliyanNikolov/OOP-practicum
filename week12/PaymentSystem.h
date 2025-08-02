#ifndef EASY_PAY_SYSTEM_HEADER
#define EASY_PAY_SYSTEM_HEADER

#include"PremiumUser.h"


class PaymentSystem{
private:
    std::vector<CommonUser> commonUsers;
    std::vector<PremiumUser> premiumUsers;
    PaymentSystem(){}

public:
    PaymentSystem(const PaymentSystem&) = delete;
    void operator=(const PaymentSystem&) = delete;
    static PaymentSystem& getInstance(){
        static PaymentSystem instance;
        return instance;
    }



    void isUserPresent(std::string,std::string);
    bool isUserPresent(const CommonUser);
    void addCommonUser(CommonUser);
    void addPremiumUser(PremiumUser);
    void commonToPremium(CommonUser,std::string,std::vector<std::string>);

};




#endif