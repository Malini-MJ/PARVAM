#include<iostream>
#include<string>
using namespace std;
int binarysearch(int arr[] , int size , int key)
{
    int left = 0 , right = size - 1;
    while (left <= right)
    {
        int mid =(left + right ) / 2;
        if (arr[mid]==key)
        return mid;
        else if(arr[mid]< key)
        left = mid + 1;
        else right = mid - 1;
    }
    return -1;

}
void displaybooks(int arr[] , const string* titles , int size)
{
    cout<<"available books:";
        for (int i = 0; i < size; i++)
        cout<<"id"<<arr[1]<<"-"<<titles[i]<<endl;
    }
    int main()
{const int size = 7;
    int bookid[size] = {1001 , 1002 , 1003 , 1004 , 1006, 1014 ,1019};
    string booktitle[size] ={"coma" , "drama" ,"catoma" ,"herione" , "nachos" ,"madpapita" ,"chickenfeet"};
    displaybooks(bookid,booktitle,size);
    int searchID;
        cout<<"enter book id to search:";
        cin>>searchID;
        int index = binarysearch(bookid , size , searchID);
if(index != -1)
    {
    cout<<"book found" << booktitle[index] << "bookid" << bookid[index]<<endl;
    }
    else
    {
        cout<<"book not ound  " << endl;
        return 0;

}
}