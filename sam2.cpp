#include<iostream>
using namespace std;

class user 
{
    public:
    string name,email;
    void login()
    {
        cout<<name<<"logged in with email"<<email<<endl;
    }

};
class customer : public user
{
    public:
    void browseproduct()
    {
        
cout <<name<<"is browsing products "<<endl;
        
    }
};
class admin
{
    public:
    string name,salesman;
    void adname()
    {
cout<<"admin has acess to"<< name<<"and"<<salesman<<endl;
    }

};
class purchase : public user
{
    public:
    void purchaseproduct()
    {
cout<<name<<"has purchased the product"<<endl;
    }
};
int main()
{
    customer c;
    c.name="manoj";
    c.email="manojgay@email.com";
    c.browseproduct();

    return 0;
}
