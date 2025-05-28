#include<iostream>

using namespace std;
class cat
{
    public:
    void purr()
    {
        cout<<"meow"<<endl;

    }
};
int main()
{
    cat *c = new cat();
    c-> purr();
    delete c;
    return 0;
}