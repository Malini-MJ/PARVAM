#include<iostream>
using namespace std;

void displayinventory(int *invent , int size)
{
    cout<<"warehouse inventory items : ";
    for(int i =  0 ; i < size; i++)
    {
        cout<< *(invent + i)  <<" ";
    }
    cout<<endl;
}
int main()
{
    int invent [5] = {50 , 30 , 20 , 40 , 10};
    int *ptr= invent;
 displayinventory(ptr , 5);
 *(ptr + 2) = 25;
 cout<<"updated inventory :";
 for (int i = 0;i<5 ;i++)
 {
    cout<< invent[i]<< "   ";
 }
 cout<<endl;
 return 0;


}
