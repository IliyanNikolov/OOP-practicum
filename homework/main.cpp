#include"GardenSystem.h"


int main(){

    // PlantInfo p1;
    // cin>>p1;
    // cout<<p1;

    // PlantInfo plant("sdfds",Sunny,5);
    // cout<<plant;

    // PlantBook p1("katalog.txt");
    // cout<<p1;






    PlantBook bookOfPlants("katalog.txt");

    /*
    
    katalog.txt should look like this:
6 cvete1 Sunny 10
6 cvete2 Sunny 125
6 cvete3 Neutral 8
6 cvete4 Shady 5
6 cvete5 Shady 5
6 cvete6 Shady 1
    
    */


    GardenSystem IO1(bookOfPlants,15,30,40);
    IO1.printBookOfPlants();

    Plant sunnyFlower("cvete1");
    Plant neutralFlower("cvete3");
    Plant shadyFlower("cvete4");

    for(int i=0;i<19;++i){
        IO1.addPlantToTheGreenhouse(sunnyFlower);
    }
    for(int i=0;i<21;++i){
        IO1.addPlantToTheGreenhouse(neutralFlower);
    }
    for(int i=0;i<50;++i){
        IO1.addPlantToTheGreenhouse(shadyFlower);
    }
    
    cout<<"\n\n";
    IO1.getGreenhousePlantStatistics();

}