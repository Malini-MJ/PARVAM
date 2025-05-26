#include<iostream>
using namespace std;

class person 
{
    public:
    void introduce()
    {
        cout<<"i am a person"<<endl;
    }

};
class student : public person 
{
    public:
    void study()
    {
        
cout <<"studying"<<endl;
        
    }
};
class employee : public person 
{
    public:
    void work()
    {
        
cout <<"working"<<endl;
        
    }
};
class workingstudent : public student , public employee
   { public:
    
    void manage()
        {
        
cout <<"managing work and studies"<<endl;
        
    }
};

int main()
{
   workingstudent ws;
   ws.student::introduce();
   ws.employee::introduce();
ws.study();
ws.work();
ws.manage();
    return 0;
}
