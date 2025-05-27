#include<iostream>
using namespace std;

class print
{
    public:
    void display()
    {
        cout<<"generating invoice for product ID:101:"<<endl;
        cout<<"default quantity :1 | no discount applied"<<endl;
    
         cout<<"generating invoice for product ID:102:"<<endl;
        cout<<"default quantity :3 | no discount applied"<<endl;
cout<<"generating invoice for product ID:103:"<<endl;
        cout<<"default quantity :5 | discount applied : 10.5 "<<endl;

    }
};
int main()
{
    print obj;
    obj.display();
    obj.display();
    return 0;
}