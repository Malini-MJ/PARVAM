#include<iostream>
using namespace std;

class camera 
{
    public:
    void takephoto()
    {
        cout<<"taking photo..........."<<endl;
    }

};
class phone 
{
    public:
    void makecall()
    {
        
cout <<"making a call"<<endl;
        
    }
};
class smartphone : public camera , public phone  
{
    public:
    void browseinternet()
    {
        
cout <<"browsing the internet"<<endl;
        
    }
};

int main()
{
    smartphone h;
    h.takephoto();
    h.makecall();
    h.browseinternet();

    return 0;
}
