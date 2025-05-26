#include<iostream>
using namespace std;

class animal 
{
    public:
    void breathe()
    {
        cout<<"animal is breathing"<<endl;
    }

};
class mamal : public animal
{
    public:
    void feedmilk()
    {
        
cout <<"mamal is feeding milk to baabies"<<endl;
        
    }
};
class dog : public mamal
{
    public:
    void bark()
    {
        
cout <<"dog is barking"<<endl;
        
    }
};
int main()
{
    dog d;
    d.breathe();
    d.feedmilk();
        d.bark();

    return 0;
}
