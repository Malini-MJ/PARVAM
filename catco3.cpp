#include<iostream>
using namespace std;

class payment {
protected:
    int amount;
public:
    payment(int amt) : amount(amt) {}
    virtual ~payment() {}
    virtual void pay() = 0;
};

class creditcardpayment : public payment {
public:
    creditcardpayment() : payment(280) {}
    void pay() override {
        cout << "Preprocessing credit card payment...\n";
        cout << "Payment of Rs. " << amount << " is being processed..." << endl;
    }
};

class paypalpayment : public payment {
public:
    paypalpayment() : payment(200) {}
    void pay() override {
        cout << "Preprocessing PayPal payment...\n";
        cout << "Payment of Rs. " << amount << " is being processed..." << endl;
    }
};

int main() {
    payment* paymentmethod = nullptr;
    int choice, proceed;

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

    cout << "Selected payment method.\n";
    cout << "Amount to be paid: Rs. " << (choice == 1 ? 280 : 200) << endl;

    cout << "Do you want to proceed? (1 for Yes, 0 for No): ";
    cin >> proceed;

    if (proceed == 1) {
        paymentmethod->pay();
        cout << "Payment successful\n";
    } else {
        cout << "Payment declined. Exiting...\n";
    }

    delete paymentmethod;
    return 0;
}