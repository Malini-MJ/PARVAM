#include<iostream>
using namespace std;
class Book
{
    public:
    string title;
    string author;
    void display()
    {
        cout<<"title:"<<title<<"           "<<"author"<<author<<endl;
    }

};
int main()
{
    Book bk;
    bk.author="alisa";
    bk.title="borderland";
    bk.display();
    return 0;





}