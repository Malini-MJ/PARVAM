#include<iostream>
using namespace std;

class Distance
{
    public:
   int meters;
   Distance(int m=0)
    {
       meters = m;
    }

Distance operator+(const Distance &d)
    {
 return Distance(meters+d.meters);
        }
        void display()

{
 cout<<"distance:"<<meters<<"meters"<<endl;
        }
};
int main()
{
  Distance d1(10),d2(15);
  Distance d3=d1+d2;
  d3.display();
    return 0;
}