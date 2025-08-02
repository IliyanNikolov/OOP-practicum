#ifndef USER_SYSTEM_HEADER
#define USER_SYSTEM_HEADER


#include"User.h"
#include<fstream>

class UserSystem{
private:
    User *users;
    unsigned capacity;
    unsigned size;
    char* fileName;
    void resize();
    void copying(const UserSystem&);
    void deleteing();
    void readFromFile();
    void writeToFile();
public:
    UserSystem();
    UserSystem(const UserSystem&);
    UserSystem& operator=(const UserSystem&);
    ~UserSystem();

    UserSystem(UserSystem&&);
    UserSystem& operator=(UserSystem&&);

    void addUser(const User);
    UserSystem(const char*);

    friend ostream& operator<<(ostream&,const UserSystem&);

};









#endif