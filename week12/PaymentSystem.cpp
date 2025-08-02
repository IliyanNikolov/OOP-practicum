#include"PaymentSystem.h"

bool PaymentSystem::isUserPresent(CommonUser toCheck){
    for(int i=0;i<commonUsers.size();++i){
        if(CommonUser::comparePasswords(&toCheck,&commonUsers[i]) && toCheck.getName()==commonUsers[i].getName()){
            return true;
        }
    }
    for(int i=0;i<commonUsers.size();++i){
        if(CommonUser::comparePasswords(&toCheck,&premiumUsers[i]) && toCheck.getName()==premiumUsers[i].getName()){
            return true;
        }
    }
    return false;
}

void PaymentSystem::isUserPresent(std::string nameToCheck,std::string passwordToCheck){
    CommonUser temp(nameToCheck,passwordToCheck);
    for(int i=0;i<commonUsers.size();++i){
        if(CommonUser::comparePasswords(&temp,&commonUsers[i]) && temp.getName()==commonUsers[i].getName()){
            std::cout<<"The user is present!";
            return;
        }
    }
    for(int i=0;i<commonUsers.size();++i){
        if(CommonUser::comparePasswords(&temp,&premiumUsers[i]) && temp.getName()==premiumUsers[i].getName()){
            std::cout<<"The user is present!";
            return;
        }
    }
    std::cout<<"The user isn't present!";
}

void PaymentSystem::addCommonUser(CommonUser toAdd){
    for(int i=0;i<commonUsers.size();++i){
        if(CommonUser::comparePasswords(&toAdd,&commonUsers[i]) && toAdd.getName()==commonUsers[i].getName()){
            return;
        }
    }
    commonUsers.push_back(toAdd);
}

void PaymentSystem::addPremiumUser(PremiumUser toAdd){
    for(int i=0;i<commonUsers.size();++i){
        if(CommonUser::comparePasswords(&toAdd,&commonUsers[i]) && toAdd.getName()==commonUsers[i].getName()){
            return;
        }
    }
    commonUsers.push_back(toAdd);
}

void PaymentSystem::commonToPremium(CommonUser toChange,std::string description,std::vector<std::string> paymentDates){
    for(int i=0;i<commonUsers.size();++i){
        if(CommonUser::comparePasswords(&toChange,&commonUsers[i]) && toChange.getName()==commonUsers[i].getName()){
            PremiumUser temp(toChange,description,paymentDates);
            addPremiumUser(temp);
            for(int j=i;j<commonUsers.size()-1;++j){
                commonUsers[j]=commonUsers[j+1];
            }
        }
    }
}