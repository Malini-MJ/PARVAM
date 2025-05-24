#include <iostream>
using namespace std;

class Product {
private:
    int quantity;            
    float pricePerItem;
    float discountAmount; // Fixed discount amount
    float discountThreshold; // Minimum amount required for discount

public:
    void setProduct(int q, float price, float threshold) {
        if (q > 0 && price > 0 && threshold >= 0) {
            quantity = q;
            pricePerItem = price;
            discountThreshold = threshold;
        } else {
            cout << "Invalid quantity, price, or discount threshold!" << endl;
        }
    }

    float getTotalPrice() {
        float totalPrice = quantity * pricePerItem;

        // Apply 10% discount only if total price exceeds the threshold
        if (totalPrice > discountThreshold) {
            discountAmount = totalPrice * 0.1; // 10% of total price
        } else {
            discountAmount = 0; // No discount applied
        }

        return totalPrice - discountAmount;
    }

    int getQuantity() {
        return quantity;
    }

    float getUnitPrice() {
        return pricePerItem;
    }

    float getDiscountThreshold() {
        return discountThreshold;
    }

    float getDiscountAmount() {
        return discountAmount;
    }
};

int main() {
    Product p;
    float threshold = 1000; // Setting threshold to ₹1000
    p.setProduct(3, 895.80 , threshold); // Buying 3 items at ₹499.99 each

    cout << "Items bought: " << p.getQuantity() << endl;
    cout << "Price per Item: ₹" << p.getUnitPrice() << endl;
    cout << "Discount Threshold: ₹" << p.getDiscountThreshold() << endl;
    cout << "Discount Applied: ₹" << p.getDiscountAmount() << endl;
    cout << "Total Price after Discount: ₹" << p.getTotalPrice() << endl;

    return 0;
}
