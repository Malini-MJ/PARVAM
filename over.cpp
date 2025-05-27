#include <iostream>

using namespace std;

class Item {

private:

    int quantity;

    float price;

public:

    Item(int q = 0, float p = 0.0f) : quantity(q), price(p) {}

    // Overload + to combine quantity and price

    Item operator+(const Item& other) {

        return Item(this->quantity + other.quantity, this->price + other.price);

    }

    // Overload == to compare quantity and price

    bool operator==(const Item& other) {

        return (this->quantity == other.quantity && this->price == other.price);

    }

    // Overload << to print item details

    friend ostream& operator<<(ostream& out, const Item& item) {

        out << "Item -> Quantity: " << item.quantity << ", Price: $" << item.price;

        return out;

    }

};

int main() {

    Item item1(10, 150.25f);

    Item item2(5, 200.50f);

    Item item3(10, 150.25f);

    Item item4 = item1 + item2;

    cout << item4 << endl;

    if (item1 == item3) {

        cout << "item1 and item3 are same in quantity and price." << endl;

    } else {

        cout << "item1 and item3 are different." << endl;

    }

    return 0;

}