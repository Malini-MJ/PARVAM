#include<iostream>
using namespace std;

void displayinventory(int *invent , int size , string ptno)
{
    cout<<"bed no's : ";

    for(int i =  0 ; i < size; i++)
    {
        cout<< *(invent + i)  <<" ";
    }
        cout<<"patientId : " <<ptno<<endl;

    cout<<endl;
}
int main()
{
    int invent [5] = { 12 , 12 , 18 , 56 , 93};
    int *ptr= invent;
    string ptno =  "p123 p231 p721 p097 p765";
 displayinventory(ptr ,5,"p123 p231 p721 p097 p765");
 *(ptr + 0) = 18;
 *(ptr + 1) = 67;
 *(ptr + 2) = 28;
 *(ptr + 3) = 6;
 *(ptr + 4) = 101;

 cout<<"updated bed no's:";
 for (int i = 0;i<5 ;i++)
 {
    cout<< invent[i]<< " ";
 }
         cout<<"patientId : " <<ptno<<endl;

         

 cout<<endl;
 return 0;



}
