#include<iostream>
using namespace std;

class product
{
private:
    string name;
    double price;

    public:
    product ( string name,double price)
    {
        this-> name = name ;
                this-> price = price ;

    }
    void show()
    {
        cout << "product name :" << this-> name <<" price " << price << endl;
    }
};
int main()
{
    product c("hoodie" , 699);
    c.show();
    return 0;
}