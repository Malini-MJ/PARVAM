#include<iostream>
using namespace std;

class human 
{
    public:
    void dance()
    {
        cout<<"human is diya"<<endl;
    }

};
class diya : public human
{
    public:
    void sing()
    {
        
cout <<"diya is singing "<<endl;
        
    }
};
int main()
{
    diya h;
    h.dance();
    h.sing();
    return 0;
}
