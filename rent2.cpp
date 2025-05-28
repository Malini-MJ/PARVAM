#include <iostream>
#include <string>
using namespace std;
class vehicle
{
    private:
    string model;
    int year;
    string owner;
    public:
    vehicle(string m , int y , string o)
    {
        model = m;
        year = y;
        owner = o;
    }
    void show()
    {
        cout<<"model:"<<model<<"year:"<<year<<"owner name:"<<owner<<endl;
    }
};
int main() 
{
    int n;
    cout << "Enter number of vehicles rented: ";
    cin >> n;

    vehicle **fleet= new vehicle *[n];
        for (int i = 0; i < n; i++) 
{
    string model , owner;
    int year;
    cout << "\nEnter details for vehicles " <<( i + 1 )<< endl;
        cout << "model: ";
        cin.ignore();
        getline(cin,model);
        cout<<"year:";
        cin>>year;
        cin.ignore();
        cout<<"owner:";
              getline(cin,owner);

fleet[i] = new vehicle(model , year, owner);
}
cout<<"================================================rented vehicles=============================================";
        for (int i = 0; i < n; i++) 
        {
            fleet[i]->show();
        }
                for (int i = 0; i < n; i++) 
{
    delete fleet[i];

}
delete[] fleet;
return 0;

};