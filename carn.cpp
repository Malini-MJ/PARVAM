#include<iostream>
using namespace std;

class vehicle 
{
    public:
    void start()
    {
        cout<<"vehicle has starteed"<<endl;
    }

};
class car : public vehicle
{
    public:
    void honk()
    {
        
cout <<"car is honking "<<endl;
        
    }
};
int main()
{
    car mycar;
    mycar.start();
    mycar.honk();
    return 0;
}
