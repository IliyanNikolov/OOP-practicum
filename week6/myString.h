#ifndef MY_STRING_H
#define MY_STRING_H

#include<iostream>
#include<cassert>
#include<cstring>

class String{
private:
    char *str;
    unsigned size;
    void deleteing();
    void copying(const String&);
public:
    String();
    String(const String&);
    String& operator=(const String&);
    ~String();
    String(String&&);
    String& operator=(String&&);
    String(const char*);
    String& operator=(const char*);
    char operator[](const int);
    String& operator+=(const String&);
    String& operator+=(const char*);

    bool operator==(const String&);
    bool operator!=(const String&);
    bool operator<= (const String&);
    bool operator< (const String&);
    bool operator> (const String&);
    bool operator>= (const String&);

    bool operator==(const char*);
    bool operator!=(const char*);
    bool operator<= (const char*);
    bool operator< (const char*);
    bool operator> (const char*);
    bool operator>= (const char*);

    friend std::ostream& operator<<(std::ostream&,const String&);
    friend std::istream& operator>>(std::istream&,String&);

    unsigned length();
    bool empty();
    const char* c_str();
    


};

String operator+(const String&,const char*);
String operator+(const String&,const String&);
String operator+(const char*,const String&);

bool operator!=(const char*,const String&);
bool operator==(const char*,const String&);
bool operator<= (const char*,const String&);
bool operator< (const char*,const String&);
bool operator> (const char*,const String&);
bool operator>= (const char*,const String&);



#endif