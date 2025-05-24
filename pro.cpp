#include <iostream>
using namespace std;
class Product {
private:
    int quantity;            
public:
    float pricePerItem;     
    void setProduct(int q, float price) {
        if (q > 0 && price > 0) {
            quantity = q;
            pricePerItem = price;
        } else {
            cout << "Invalid quantity or price!" << endl;
        }
    }
    float getTotalPrice() {
        return quantity * pricePerItem;
    }
    int getQuantity() {
        return quantity;
    }
    
    int getUnitprice()
    {
        return pricePerItem;
    }
};
int main() {
    Product p;
    p.setProduct(3,499.99);
    cout << "items brought: " << p.getQuantity() << endl;
    cout << "Price per Item: " << p.pricePerItem << endl;
    cout << "Total Price: " << p.getTotalPrice() << endl;
    return 0;
}
