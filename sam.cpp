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
int main()
{
    customer c;
    c.name="manoj";
    c.email="manojgay@email.com";
    c.login();
    c.browseproduct();

    return 0;
}
