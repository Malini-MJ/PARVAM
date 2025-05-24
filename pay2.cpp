#include<iostream>
using namespace std;

class payment {
public:
    virtual ~payment() {}
    virtual void pay(int amount) = 0;
};

class creditcardpayment : public payment {
public:
    void pay(int amount) override {
        cout << "Processing credit card payment of Rs. " << amount << "..." << endl;
    }
};

class paypalpayment : public payment {
public:
    void pay(int amount) override {
        cout << "Processing PayPal payment of Rs. " << amount << "..." << endl;
    }
};

int main() {
    payment *paymentmethod = nullptr;
    int choice, amountChoice, amount = 0;

    cout << "Choose a payment method:\n";
    cout << "1. Credit Card\n";
    cout << "2. PayPal\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    switch(choice) {
        case 1:
            paymentmethod = new creditcardpayment();
            break;
        case 2:
            paymentmethod = new paypalpayment();
            break;
        default:
            cout << "Invalid choice. Exiting..." << endl;
            return 1;
    }

    cout << "Select amount to pay:\n";
    cout << "1. Rs. 200\n";
    cout << "2. Rs. 280\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> amountChoice;

    switch(amountChoice) {
        case 1:
            amount = 200;
            break;
        case 2:
            amount = 280;
            break;
        default:
            cout << "Invalid amount choice. Exiting..." << endl;
            delete paymentmethod;
            return 1;
    }

    paymentmethod->pay(amount);
    delete paymentmethod;

    return 0;
}