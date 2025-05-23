#include<iostream>
using namespace std;
class Book{
    string title;
    string authour;
    float price;
public:
Book(string t , string a , float p)
{
    
title = t ;
authour = a ;
price = p;

cout<<"title"<< title << ", authour"<< authour <<" , price"<< price<< endl;
}
};
int main()
{
    Book b("souls in time" , "naresh D" , 300.50);
    return 0;
}