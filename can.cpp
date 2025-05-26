#include <iostream>
using namespace std;

class savingsbank
{
    protected:
    string name;
    int age;
    public:
    void setdata(string n , int a)
{
   name = n;
   age = a;
}
};
class premiumSb:public savingsbank{
    
    private:
    string plantype;
    float intrest;
    int accno;
    public:
    void setdetails(string p , float i , int no){
    plantype = p;
    intrest = i;
    accno = no;   
    }
    void showdetails()
        {
            cout<<" name:"<< name<<endl;
            cout<<" age:"<< age<<endl;
            cout<<"plantype:"<< plantype<<endl;
            cout<<"intrest:"<< intrest<<endl;
            cout<<"account no:"<< accno<<endl;
        }};
    
int main()
{
    premiumSb ps;
    ps.setdata("jose" , 40);
    ps.setdetails("premium",+10,2234);
    ps.showdetails();

return 0;
}