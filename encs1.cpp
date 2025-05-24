#include<iostream>
using namespace std;
class Person
{
    private:
    string name;
    int age;

    public :
         void setData(string n ,int a){
name = n;
age = a;
}
void displayData()
{
    cout<<"name: " << name << " age: " << age <<endl;
}
};
int main(){
    Person p;
    p.setData("malini" , 20);
    p.displayData();
    return 0;
}
