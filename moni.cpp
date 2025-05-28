#include<iostream>
#include<iomanip>
using namespace std;
class Product
{
private:
    string name;
    double price;
    double discount;
public:
    Product(string name, double price)
    {
        this->name = name;
        this->price = price;
        this->discount = 0;
    }
    Product* setDiscount(double discount)
    {
        this->discount = discount;
        return this;
    }
    double getFinalPrice() const
    {
        return price * (1 - discount / 100);
    }
    Product* show()
    {
        cout << fixed << setprecision(2);
        cout << "Product Name: " << name << endl;
        cout << "Original Price: " << price << endl;
        cout << "Discount: " << discount << "%" << endl;
        cout << "Final Price: " << getFinalPrice() << endl;
        return this;
    }
    bool isMoreExpensiveThan(Product* other)
    {
        return this->getFinalPrice() > other->getFinalPrice();
    }

};
int main()
{
    Product* p1 = new Product("Laptop", 50000);
    Product* p2 = new Product("Tablet", 30000);
    p1->setDiscount(10)->show();
    
    cout << "------------------" << endl;
    p2->setDiscount(5)->show();
    cout << "------------------" << endl;
    if (p1->isMoreExpensiveThan(p2))
    {
        cout << p1->getFinalPrice() << " is more expensive than " << p2->getFinalPrice() << endl;
    }
    else
    {
        cout << p2->getFinalPrice() << " is more expensive than " << p1->getFinalPrice() << endl;
    }
    return 0;

}