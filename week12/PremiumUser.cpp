#include"PremiumUser.h"

PremiumUser::PremiumUser() = default;

PremiumUser::PremiumUser(std::string name,std::string password,std::string description,std::vector<std::string> paymentDates)
:CommonUser(name,password),premiumPlanDescription(description),paymentDates(paymentDates)
{}

PremiumUser::PremiumUser(CommonUser commonPart,std::string description,std::vector<std::string> paymentDates)
:CommonUser(commonPart),premiumPlanDescription(description),paymentDates(paymentDates)
{}