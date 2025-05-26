#include<iostream>
using namespace std;

class shape 
{
    public:
    void setcolor(string c)
    {
        cout<<"setting color "<<c<<endl;
    }
};

class circle : public shape
{
    public:
    void drawcircle()
    {
        cout <<"draw circle"<<endl;
    }
};

class rectangle : public shape
{
    public:
    void drawrectangle()
    {
        cout <<"drawing rectangle"<<endl;
    }
};

int main()
{
    circle c;
    rectangle r;
    
    c.setcolor("red"); 
    r.setcolor("blue"); 
    
    c.drawcircle();
    r.drawrectangle();

    return 0;
}
