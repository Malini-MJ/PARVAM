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

cout<<"name"<< name << ", age"<< age <<" , usn"<< usnum<<" , college name "<<clgname<< endl;
    }
    };
     int main()

{
    Student s1("student","1CE24AI042" ,29,"city engineering college");
    return 0;
}    