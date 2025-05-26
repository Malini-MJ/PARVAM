#include<iostream>
using namespace std;

class person 
{public:void introduce(){cout<<"i am a person in the uni"<<endl;}};
class student:public person
{public: void study(){cout<<"i am a studying"<<endl;}};
class graduatestudent:public student
{public: void research(){cout<<"i am researching on cats"<<endl;}};
class employee : public person
{public: void work(){cout<<"i am working at the uni"<<endl;}};
class ta : public student , public employee
{public: void assist(){cout<<"i assist and teach and study"<<endl;}};
class professor:public person
{public: void teach(){cout<<"i teach about cats"<<endl;}};
class researchprofessor : public professor , public graduatestudent
{public: void researchteach(){cout<<"i teach and research"<<endl;}};
int main()
    {
    ta t;
    t.student::introduce();
     t.employee::introduce();
     t.study();
     t.work();
     t.assist();
      
     researchprofessor r;
     r.professor::introduce();
     r.graduatestudent::introduce();
     r.study();
     r.teach();
     r.research();
     r.researchteach();
    }

