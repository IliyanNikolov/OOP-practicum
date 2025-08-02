#include"Sorted.hpp"


int main(){

    Sorted<int> arr1;
    arr1.addElem(5);
    arr1.addElem(15);
    arr1.addElem(20);

    arr1.print();

    Sorted<int> arr2=arr1;

    arr2.addElem(15);
    arr2.addElem(25);

    cout<<"\n\narr2:\n";
    arr2.print();

    arr2.removeElem(15);

    cout<<"\n\narr2:\n";
    arr2.print();

}