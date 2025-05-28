#include<iostream>
#include<string>
using namespace std;
class vehicle
{
    private:
    string model;
    int year;
    public:
    vehicle(string m , int y)
    {
        model = m;
        year = y;
    }
    void show()
    {
        cout<<"model:" << model<<"year"<<year<<endl;
    }

};
int main()
{
    vehicle *v1 = new vehicle("toyota carry" , 2022);
        vehicle *v2 = new vehicle("tesla model 3" , 2028);

        v1-> show();
        v2->show();
        delete v1 , v2 ;
        return 0;


}