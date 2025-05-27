#include<iostream>
using namespace std;

class print
{
    public:
    void display(int num)
    {
        cout<<"printing number:"<<num<<endl;
    }

void display(string name)
    {
        cout<<"printing name:"<<name<<endl;
    }
};
int main()
{
    print obj;
    obj.display(10);
    obj.display("alice");
    return 0;
}