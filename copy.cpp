#include<iostream>
using namespace std;
class Student{
public:
int *marks;
int size;
Student(int s)
{
    size = s;
    marks = new int[size];
}
Student(const Student& s)
{
    size =s.size;
    marks = new int[size];
    for(int i=0;i<size;i++)
    {
        marks[i] = s.marks[i];
    }
}
    ~Student()
    {
       delete[] marks;

    }
    void display()
    {
        for(int i=0 ; i<size ; i++)
        {
            cout<<marks[i]<<"  ";
        }
        cout<<endl;
    }
};
int main()
{
    Student s1(3);
    s1.marks[0]=80  ;
    s1.marks[1]=90  ;
    s1.marks[2]=85  ;
    Student s2=s1;
    s2.display();
    return 0;


}