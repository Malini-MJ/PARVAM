#include<iostream>
#include<string>
using namespace std;
class booking
{
    public:
    string customerName;
    int seats;
     
    booking(string name = "", int s = 1) : customerName(name) , seats(s) {}

    virtual void bookticket() = 0;
    virtual ~booking() {}
};
 class flightbooking : public booking{
    public:
    flightbooking(string name, int s ):booking(name,s) {}
    void bookticket() override{
        cout<<"flight ticket booked for " << customerName<<"with" << seats<<"seats(s)" << endl;
    }
 };
 class trainbooking : public booking{
    public:
    trainbooking(string name, int s ):booking(name,s) {}
    void bookticket() override{
        cout<<"train ticket booked for " << customerName<<"with" << seats<<"seats(s)" << endl;
    }
 };
class carbooking : public booking{
    public:
    carbooking(string name, int s ):booking(name,s) {}
    void bookticket() override{
        cout<<"car ticket booked for " << customerName<<"with" << seats<<"seats(s)" << endl;
    }
 };
class bookingmanager
{
    public:
    void confirmbooking(string name)
    {
        cout<<"booking confirned for :" << name<<endl;
    }
    void confirmbooking(string name , int seats)
    {
        cout<<"booking confirned for :" << name<<"with"<<seats<<"seat(s)"<<endl;
    }
    void confirmbooking(string name , int seats, string date)
    {
        cout<<"booking confirned for :" << name<<"with"<<seats<<"seat(s)"<<date<<"date"<<endl;
    }
};
class groupbooking
{
    public:
    int totalseats;
    groupbooking(int seats=0):totalseats(seats){}
    groupbooking operator+(const groupbooking &other)
    {
        return groupbooking(this-> totalseats + other.totalseats);
    }
    void display()
    {
        cout<<"total group seats booked:"<<totalseats<<endl;
    }
};

int main()
{
    booking *b1 = new flightbooking("alice",2);
        booking *b2 = new flightbooking("bob",3);
    booking *b3 = new flightbooking("charlie",6);

    cout<<" ==== runtime polymorphism ==="<<endl;
    b1->bookticket();
        b2->bookticket();
    b3->bookticket();

    cout<<"=== fnction overloading ===" <<endl;
    bookingmanager manager;
    manager.confirmbooking("bavid");
        manager.confirmbooking("emma",4);
    manager.confirmbooking("frankquee",5,"2-06-2025");

cout<<"=== operator overloading ===" <<endl;
  groupbooking group1(4);
    groupbooking group2(6);
  groupbooking totalgroup = group1 + group2;
totalgroup.display();

delete b1;
delete b2;
delete b3;
return 0;
}








