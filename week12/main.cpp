#include"PaymentSystem.h"



int main(){

    CommonUser c1("pesho","gosho");
    CommonUser c2("gosho","pesho");
    std::vector<std::string> dates;
    PremiumUser p1(c1,"egjnsdf,l;a;kjf",dates);
    PremiumUser p2("gosho1","pesho1","egjnsdrhgsjeakdlg",dates);
    std::cout<<CommonUser::comparePasswords(&c1,&c2)<<"\n";
    std::cout<<CommonUser::comparePasswords(&c1,&p1)<<"\n";

    




    return 0;
}