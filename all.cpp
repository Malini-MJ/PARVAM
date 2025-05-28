#include<iostream>
#include<string>
using namespace std;

class student
{
private:
    string name;
   int *marks;
   int *id;

    public:
    student ( string name,int marks , int id)
    {
        this-> name = name ;
                this-> marks =new int(marks) ;
                this-> id =new int(id) ;

    }
    void addbonus(int bonus)
    {
        *marks += bonus;
    }
    void display()
    {
            cout << "student:" << name <<" | ID" << *id <<" | marks" << *marks<< endl;
    }
    ~student()
    {
        cout<<"deleting student:" << name<<endl;
        delete marks;
        delete id;

    }
};
int main()
{
    int scores[]= {90 , 85 , 78};
    int *pScores= scores;
    cout<<"scores";
        for (int i =0 ; i<3 ;i++)
    cout<<*(pScores + i )<< " ";
    cout<< endl;
    student *s1 = new student("alice" ,90 , 10001);
        student *s2 = new student("amogos" ,85 , 10002);

        s1->addbonus(5);
        s2->addbonus(10);

        s1->display();
        s2->display();
        delete s1;
        delete s2;
         return 0;
}




