#include"myString.h"

void String::deleteing(){
    delete[] str;
}

void String::copying(const String& other){
    size=other.size;
    str=new char[size+1];
    strcpy(str,other.str);
}

String::String(){
    size=0;
    str=nullptr;
}

String::String(const String& other){
    copying(other);
}

String& String::operator=(const String& other){
    if(this!=&other){
        deleteing();
        copying(other);
    }
    return *this;
}

String::~String(){
    deleteing();
}

String::String(String&& other){
    str=other.str;
    size=other.size;
    other.str=nullptr;
}

String& String::operator=(String&& other){
    if(this!=&other){
        deleteing();
        str=other.str;
        size=other.size;
        other.str=nullptr;
    }
    return *this;
}

String::String(const char *src){
    if(src==nullptr){
        size=0;
        str=new char[size+1];
        str[size]='\0';
    }
    else{
        size=strlen(src);
        str=new char[size+1];
        strcpy(str,src);
    }
}

String& String::operator=(const char* src){
    if(src==nullptr){
        return *this;
    }
    deleteing();
    size=strlen(src);
    str=new char[size+1];
    strcpy(str,src);
    return *this;
}

char String::operator[](const int index){
    if(index>size-1 && index<0){
        assert("the index is invalid");
    }
    return str[index];
}

String& String::operator+=(const String& other){
    // if(this==&other){
    //     char *temp=str;
    //     int sizeStr=size;
    //     size*=2;
    //     str=new char[size+1];
    //     strcpy(str,temp);
    //     for(int i=sizeStr;i<size;++i){
    //         str[i]=temp[i-sizeStr];
    //     }
    //     str[size]='\0';
    //     delete[] temp;
    //     return *this;
    // }
    char *temp=str;
    int sizeStr=size;
    size=size+other.size;
    str=new char[size+1];
    strcpy(str,temp);
    for(int i=sizeStr;i<size;++i){
        str[i]=other.str[i-sizeStr];
    }
    str[size]='\0';
    delete[] temp;
    return *this;
}

String& String::operator+=(const char* rhs){
    if(rhs==nullptr){
        return *this;
    }
    char *temp=str;
    int sizeStr=strlen(str);
    int sizeRhs=strlen(rhs);
    size=sizeStr+sizeRhs;
    str=new char[size+1];
    strcpy(str,temp);
    for(int i=sizeStr;i<size;++i){
        str[i]=rhs[i-sizeStr];
    }
    str[size]='\0';
    delete[] temp;
    return *this;
}


bool String::operator==(const String& rhs){
    if(size!=rhs.size){
        return false;
    }
    for(int i=0;i<size;++i){
        if(str[i]!=rhs.str[i]){
            return false;
        }
    }
    return true;
}

bool String::operator!=(const String& rhs){
    return !(this->operator==(rhs));
}

bool String::operator<(const String& rhs){
    int temp=strcmp(str,rhs.str);
    if(temp==-1){
        return true;
    }
    return false;
}

bool String::operator<=(const String& rhs){
    return (this->operator==(rhs) || this->operator<(rhs));
}

bool String::operator>(const String& rhs){
    int temp=strcmp(str,rhs.str);
    if(temp==1){
        return true;
    }
    return false;
}

bool String::operator>=(const String& rhs){
    return (this->operator==(rhs) || this->operator>(rhs));
}


bool String::operator==(const char* rhs){
    if(size!=strlen(rhs)){
        return false;
    }
    for(int i=0;i<size;++i){
        if(str[i]!=rhs[i]){
            return false;
        }
    }
    return true;
}

bool String::operator!=(const char* rhs){
    return !(this->operator==(rhs));
}

bool String::operator<(const char* rhs){
    int temp=strcmp(str,rhs);
    if(temp==-1){
        return true;
    }
    return false;
}

bool String::operator<=(const char* rhs){
    return (this->operator==(rhs) || this->operator<(rhs));
}

bool String::operator>(const char* rhs){
    int temp=strcmp(str,rhs);
    if(temp==1){
        return true;
    }
    return false;
}

bool String::operator>=(const char* rhs){
    return (this->operator==(rhs) || this->operator>(rhs));
}


std::ostream& operator<<(std::ostream& os, const String& outstr) {
    os << outstr.str;
    return os;
}

std::istream& operator>>(std::istream& is,String& instr){
    delete[] instr.str;
    char buffer[256];
    is>>buffer;
    instr.size=strlen(buffer);
    instr.str=new char[instr.size+1];
    strcpy(instr.str,buffer);
    return is;
}

unsigned String::length(){
    return size;
}

bool String::empty(){
    return size==0;
}

const char* String::c_str(){
    return str;
}





String operator+(const String& lhs,const char* rhs){
    String toReturn(lhs);
    toReturn+=rhs;
    return toReturn;
}

String operator+(const String& lhs,const String& rhs){
    String toReturn(lhs);
    toReturn+=rhs;
    return toReturn;
}

String operator+(const char* lhs,const String& rhs){
    String toReturn(lhs);
    toReturn+=rhs;
    return toReturn;
}

bool operator!=(const char* lhs,const String& rhs){
    String temp(lhs);
    return temp!=rhs;
}
bool operator==(const char* lhs,const String& rhs){
    String temp(lhs);
    return temp==rhs;
}
bool operator<=(const char* lhs,const String& rhs){
    String temp(lhs);
    return temp<=rhs;
}
bool operator<(const char* lhs,const String& rhs){
    String temp(lhs);
    return temp<rhs;
}
bool operator>(const char* lhs,const String& rhs){
    String temp(lhs);
    return temp>rhs;
}
bool operator>=(const char* lhs,const String& rhs){
    String temp(lhs);
    return temp>=rhs;
}














