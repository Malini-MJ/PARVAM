#include<iostream>
using namespace std;
class Car{
    public:
    string brand;
    void start(){
        cout<<brand<<" "<<"car started!"<<endl;
    }

};
int main(){  
    Car c1,c2,c3,c4;
    c1.brand="toyota";
    c2.brand="BMW";
    c3.brand="OMINI";
    c4.brand="PORSCHE";

    c1.start();
    c2.start();
    c3.start();
    c4.start();


    return 0;

}