#include<iostream>
using namespace std;
class Car {

    string model;

    int year;

public:


    Car() {

        model = "Unknown";

        year = 0;

    }


    Car(string m) {

        model = m;

        year = 0;

    }


    Car(string m, int y) {

        model = m;

        year = y;

    }

    void displayInfo() {

        cout << "Model: " << model << ", Year: " << year << endl;

    }

};

int main() {

    Car car1;                   

    Car car2("Toyota");         

    Car car3("Honda", 2022);   

    car1.displayInfo();

    car2.displayInfo();

    car3.displayInfo();

    return 0;

}

      
