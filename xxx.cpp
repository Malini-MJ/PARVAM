#include<iostream>
using namespace std;
int binarysearcg(int arr[] , int size , int key)
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
int main()
{
    int arr[] = {2,5,10,15,10,25};
    int key = 15;
    int size = sizeof(arr) / sizeof(arr[0]);
    int result = binarysearcg(arr , size , key);
    if(result != -1)
    cout<<"element found at insex " << result << endl;
    else
        cout<<"element not found  " << result << endl;
        return 0;

}