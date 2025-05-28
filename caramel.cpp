#include<iostream>
#include<iostream>
using namespace std;
int main()
{
    int n ;
    cout<<"enter no of employes:";
    cin>>n;

    string *employees = new string[n];
    for (int i =0 ; i<n ;i++)
    {
        cout<<"enter employee" <<(i+1) <<"name:"<<endl;
        cin>> employees[i];
    }
    cout<<" employee list:" ;
       for (int i =0 ; i<n ;i++)
         {
        cout<<(i+1) <<"."<<employees[i]<<endl;
       
    }
    delete[] employees;
    return 0;
 
}