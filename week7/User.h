#ifndef USER_WHATEVER
#define USER_WHATEVER

#include<iostream>
#include<cstring>
using namespace std;

class User{
private:
    char* name;
    char* password;
    void copying(const User&);
    void deleteing();
public:
    User();
    User(const User&);
    User& operator=(const User&);
    ~User();

    User(User&&);
    User& operator=(User&&);

    User(const char*,const char*);

    friend istream& operator>>(istream&,User&);
    friend ostream& operator<<(ostream&,const User&);

};




#endif