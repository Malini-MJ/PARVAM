#include<iostream>
#include<string>
using namespace std;
class fir
{
    public:
    string complaintname;

    fir(string name) : complaintname(name) {}

    virtual void registercase()=0;
    virtual ~fir() {}
};

class theftcase : public fir
{
public:
theftcase(string name) : fir(name) {}
void registercase() override
{
    cout<<"theft fir registered for" << complaintname <<endl;
    cout<<"action : investigation started for stolen property" <<endl;

}

};
class accidentcase : public fir
{
public:
accidentcase(string name) : fir(name) {}
void registercase() override
{
    cout<<"theft fir registered for" << complaintname <<endl;
    cout<<"action : ambulance dispatched and accident site team notified" <<endl;

}

};
class missingpersoncase : public fir
{
public:
missingpersoncase(string name) : fir(name) {}
void registercase() override
{
    cout<<"theft fir registered for" << complaintname <<endl;
    cout<<"Action: Local patrol units alerted and investigation initiated." <<endl;

}

};
int main()
{
    fir *c1=new theftcase("ravi");
        fir *c2=new accidentcase("sita");
    fir *c3=new missingpersoncase("karan");

    cout <<"~~~~~~~~~~~~~~~~~~~fir registration ~~~~~~~~~~~~~~~~~~~"<< endl;
    c1-> registercase();
    cout<<endl;
     c2-> registercase();
    cout<<endl;
     c3-> registercase();
    cout<<endl;

delete c1;
delete c2;
delete c3;


}