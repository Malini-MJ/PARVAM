#include <iostream>
using namespace std;

class bankaccount
{
    protected:
    double balance;
    public:
    void setbalance(double b)
{
    balance = b;
}
};
class savingaccount:public bankaccount{
    public:
    void showbalance()
    {
        cout<<"balance is:"<< balance<<endl;    }
    };
int main()
{
    savingaccount acc;
acc.setbalance(1000.50);
acc.showbalance();
return 0;
}