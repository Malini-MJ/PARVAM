#include<iostream>
using namespace std;
class Student{
public:
    string name , usnum , clgname;
    int age;
    Student (string n ,string usn ,int a, string clgn)
     {
name=n;
age = a;
usnum= usn;
clgname=clgn;
     }
     Student(const Student &s)
     {
        name = s.name;
        age = s.age;
        usnum = s.usnum;
        clgname = s.clgname;

     }
     void display()
     {

cout<<"name"<< name << ", age"<< age <<" , usn"<< usnum<<" , college name "<<clgname<< endl;

    }
};
     int main()

{
    Student s1("john", "1CE24AI043" , 27 , "CEC");
        Student s2("monalisa", "1CE24AI049" , 21 , "CEC");
    Student s3("akasheee", "1CE24AI040" , 26 , "CEC");
    Student s4("trump", "1CE24AI068" , 24 , "CEC");

    
        s1.display();
        s2.display();
        s3.display();
        s4.display();

        return 0;
}    