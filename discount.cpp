#include <iostream>
using namespace std;

class Product {
private:
    int quantity;            
    float pricePerItem;
    float discountAmount; // Discount as a fixed amount

public:
    void setProduct(int q, float price, float discount = 0) {
        if (q > 0 && price > 0 && discount >= 0) {
            quantity = q;
            pricePerItem = price;
            discountAmount = discount;
        } else {
            cout << "Invalid quantity, price, or discount!" << endl;
        }
    }

    float getTotalPrice() {
        float totalPrice = (quantity * pricePerItem) - discountAmount; // Direct discount amount subtraction
        return totalPrice;
    }

    int getQuantity() {
        return quantity;
    }

    float getUnitPrice() {
        return pricePerItem;
    }

    float getDiscountAmount() {
        return discountAmount;
    }
};

int main() {
    Product p;
    p.setProduct(3, 499.99, 100); 
    cout << "Items bought: " << p.getQuantity() << endl;
    cout << "Price per Item: " << p.getUnitPrice() << endl;
    cout << "Discount Amount: " << p.getDiscountAmount() << endl;
    cout << "Total Price after Discount: " << p.getTotalPrice() << endl;

    return 0;
}
