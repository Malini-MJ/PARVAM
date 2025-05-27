#include<iostream>
#include<string>
using namespace std;
class medical
{
    public:
    string conditionname;

    medical(string name) : conditionname(name) {}

    virtual void registercase()=0;
    virtual ~medical() {}
};

class fever : public medical
{
public:
fever(string name) : medical(name) {}
void registercase() override
{
    cout<<"fever symptom registered for " << conditionname <<endl;
    cout<<"action : treatment started for fever" <<endl;

}

};
class accidentcase : public medical
{
public:
accidentcase(string name) : medical(name) {}
void registercase() override
{
    cout<<" accident surgery registered for " << conditionname <<endl;
    cout<<"action : immidiate surgery process started" <<endl;

}

};
class handicaped : public medical
{
public:
handicaped(string name) : medical(name) {}
void registercase() override
{
    cout<<"handicaped case registered for " << conditionname <<endl;
    cout<<"Action:nurse arranged for daily treatment and care" <<endl;

}

};
int main()
{
    medical *c1=new fever("ravi");
        medical *c2=new accidentcase("sita");
    medical *c3=new handicaped("karan");

    cout <<"~~~~~~~~~~~~~~~~~~~condition registration ~~~~~~~~~~~~~~~~~~~"<< endl;
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