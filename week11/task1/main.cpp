#include"MyVector.hpp"

double addOne(double& a) {
    return ++a;
}

double multBy6(double& a){
    return a*6;
}

int main() {
    MyVector<double> arr;

    arr.addElement(5.5);
    arr.addElement(5.7);
    arr.addElement(4.2);
    arr.addElement(9.3);

    arr.map(&addOne);

    for (int i = 0; i < 4; i++) {
        std::cout << arr[i] << " ";
    }

    arr.addElement(100.36);
    arr.addElement(126.56);
    arr.addElement(215.36);
    arr.addElement(1486.3);
    arr.addElement(6565.786);

    arr.map(&multBy6);
    cout<<"\n";

    for(int i=0;i<9;++i){
        cout<<arr[i]<<" ";
    }



    return 0;
}