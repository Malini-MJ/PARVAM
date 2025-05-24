//method that retrives a private valuse,fetches a private variable and returns it 
//to set means to modify that value 
#include<iostream>
using namespace std;
class Student
{
    private:
    int rollNumber;

    public:
    void setRollNumber(int r)
    {
        rollNumber = r;
    }
    int getRollNumber()
    {
        return rollNumber;
    }

};
int main()
{
    Student s1;
    s1.setRollNumber(101);
    cout<< s1.getRollNumber() << endl ;
    return 0;
}