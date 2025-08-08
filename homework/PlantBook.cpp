#include"PlantBook.h"


void PlantBook::resize(){
    capacity*=2;
    PlantInfo *temp=new PlantInfo[capacity];
    for(int i=0;i<size;++i){
        temp[i]=plants[i];
    }
    delete[] plants;
    plants=temp;
}

void PlantBook::copying(const PlantBook& other){
    capacity=other.capacity;
    size=other.size;
    plants=new PlantInfo[capacity];
    for(int i=0;i<size;++i){
        plants[i]=other.plants[i];
    }
    strcpy(bookName,other.bookName);
}

void PlantBook::deleteing(){
    delete[] plants;
}

void PlantBook::readFromFile(){
    ifstream file(bookName);

    if(!file.is_open()){
        cout<<"File can't be opened";
        return;
    }

    PlantInfo temp;
    
    while(!file.eof()){
        file>>temp;
        addPlantType(temp);
    }

    file.close();
}

void PlantBook::writeToFile(){
    ofstream file(bookName);

    if(!file.is_open()){
        cout<<"File can't be opened";
        return;
    }

    int i=0;
    while(i<size-1){
        file<<plants[i]<<endl;
        ++i;
    }
    file<<plants[i];

    file.close();
}

PlantBook::PlantBook(){
    capacity=8;
    size=0;
    plants=new PlantInfo[capacity];
    bookName[0]='\0';
}

PlantBook::PlantBook(const PlantBook& other){
    copying(other);
}

PlantBook& PlantBook::operator=(const PlantBook& other){
    if(this!=&other){
        deleteing();
        copying(other);
    }
    return *this;
}

PlantBook::~PlantBook(){
    writeToFile();
    deleteing();
}

PlantBook::PlantBook(PlantBook&& other){
    plants=other.plants;
    capacity=other.capacity;
    size=other.size;
    strcpy(bookName,other.bookName);
    other.plants=nullptr;
}

PlantBook& PlantBook::operator=(PlantBook&& other){
    if(this!=&other){
        deleteing();
        plants=other.plants;
        capacity=other.capacity;
        size=other.size;
        strcpy(bookName,other.bookName);
        other.plants=nullptr;
    }
    return *this;
}

PlantBook::PlantBook(const char *fileName){
    if(fileName==nullptr || strlen(fileName)>=128){
        char temp[1024];
        do{
            cout<<"Invalid file name. Try again: ";
            cin.getline(temp,1024,'\n');
            cout<<endl;
        }
        while(strlen(temp)>=128);
        strcpy(bookName,temp);
    }
    else{
        strcpy(bookName,fileName);
    }
    capacity=8;
    size=0;
    plants=new PlantInfo[capacity];
    readFromFile();
}

void PlantBook::setBookName(const char *fileName){
    if(fileName==nullptr || strlen(fileName)>=128){
        char temp[1024];
        do{
            cout<<"Invalid file name. Try again: ";
            cin>>temp;
            cout<<endl;
        }
        while(strlen(temp)>=128);
        strcpy(bookName,temp);
    }
    else{
        strcpy(bookName,fileName);
    }
}


void PlantBook::addPlantType(const PlantInfo& toAdd){
    if(capacity==size){
        resize();
    }
    for(int i=0;i<size;++i){
        if(strcmp(plants[i].getPlantName(),toAdd.getPlantName())==0){
            throw std::runtime_error("Trying to add a copy of a plant!");
        }
    }
    int i=0;
    while(i<size && strcmp(toAdd.getPlantName(),plants[i].getPlantName())>0){
        ++i;
    }
    for(int j=size;j>i;--j){
        plants[j]=plants[j-1];
    }
    plants[i]=toAdd;
    ++size;
    writeToFile();
}

istream& operator>>(istream& is,PlantBook& inBook){
    char buffer[1024];
    is.getline(buffer,1024,'\n');
    inBook.setBookName(buffer);
    inBook.deleteing();
    inBook.readFromFile();
    return is;
}

ostream& operator<<(ostream& os,const PlantBook& outBook){
    for(int i=0;i<outBook.size;++i){
        cout<<"plant #"<<i+1<<": "<<outBook.plants[i].getPlantName()<<" ";
        if(outBook.plants[i].getHabitPlace()==1){
            os<<"Sunny";
        }
        else if(outBook.plants[i].getHabitPlace()){
            os<<"Shady";
        }
        else{
            os<<"Neutral";
        }
        os<<" ";
        if(outBook.plants[i].getDaysWatering()==0){
            os<<3;
        }
        else{
            os<<outBook.plants[i].getDaysWatering();
        }
        os<<"\n";
    }
    cout<<"bookName: "<<outBook.bookName;

    return os;
}

int PlantBook::isPlantPresent(const char* name){
    for(int i=0;i<size;++i){
        if(strcmp(plants[i].getPlantName(),name)==0){
            return i;
        }
    }
    return -1;
}

unsigned PlantBook::getPlantDaysWateringByIndex(const int index){
    return plants[index].getDaysWatering();
}

HabitPlace PlantBook::getPlantHabitPlaceByIndex(const int index){
    return plants[index].getHabitPlace();
}


