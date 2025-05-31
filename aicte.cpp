#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct college {
   string name;
};
struct student{
    string name;
    int age;
    string college;
    string course;
    string mail;
    string regno;
    string nsscategory;
};
void displaycategories()
{
    cout<<"blood donation camp"<<endl;
        cout<<"rural development drives"<<endl;
    cout<<"environmental awareness progeram"<<endl;
    cout<<"backward literacy program"<<endl;

}
string getcategory(int choice)
{switch(choice)
{
case 1 : return "blood donation camp";
case 2 : return "rural development drives";
case 3 : return "environmental awareness progeram";
case 4 : return "backward literacy program";
default : return "invalid category"; 
}}
int main()
{
     college c;
     vector<student> students;
     int nostudents;
     cout <<"=======enter college details=======";
     cout<<"college name";
     getline(cin , c.name);
     cout<<"enter number of students to input";
     cin>>nostudents;
     for(int i = 0 ; i < nostudents ; i++)
     {
        student s;
        cout<<"=================enter student details=================="<< (i+1);
        cout <<"name";
        getline(cin , s.name);
        cout <<"age";
        cin>>s.age;
        cout <<"college";
        getline(cin , s.college);
        cout <<"course";
        getline(cin , s.course);
        cout <<"mail-id";
        getline(cin , s.mail);
        cout <<"register no";
        getline(cin , s.regno);
        displaycategories();
        int nsschoice;
        cout<<"enter nss category(1-4)";
        cin>>nsschoice;
        s.nsscategory = getcategory(nsschoice);
       if (s.nsscategory == "invalid"){
        cout<<"invalid category";
        s.nsscategory="unassigned";

       }
     }
     // to display all data 
    cout<<"================college and student info====================";
    cout<<"college :"<<c.name<<endl;
    for(int i = 0 ; i< students.size();++i)
    {
        student& s = students[i];
        cout<<"student details"<<i+1<<endl;
cout <<"name"<<s.name<<endl;
cout <<"age"<<s.age<<endl;
cout <<"college"<<s.college<<endl;
cout <<"course"<<s.course<<endl;
cout <<"mail-id"<<s.mail<<endl;
cout <<"register no"<<s.regno<<endl;
cout <<"nss category"<<s.nsscategory<<endl;
return 0;

    }

}
