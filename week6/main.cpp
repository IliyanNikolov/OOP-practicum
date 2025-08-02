#include"myString.h"

int main(){
    String s1;
    std::cin>>s1;
    String s2("123456789");
    String s3=s1+s2;
    String s4=s2;
    s4+=s1;
    s4+="_987654321";
    std::cout<<std::endl<<s1<<std::endl<<s2<<std::endl<<s3<<std::endl<<s4;




}