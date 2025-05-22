#include<iostream>
using namespace std;
class Employee
{
    private:
    int salary;
    public:
   void setSalary(int b){
    salary = b;
   }
   int getSalary(){
    return salary;
   }

};
int main()
{
    Employee emp;
    emp.setSalary(18000);
    cout<<"employee salary is   "<<emp.getSalary()<<endl;
    return 0;
}



