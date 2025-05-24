#include<iostream>
using namespace std;

class Account {
private:
    double balance = 5000;
    int pin = 1234;
    long long cardNumber = 1234567890123456; // Example card number

    bool verifyCredentials(long long enteredCard, int enteredPin) {
        return (enteredCard == cardNumber && enteredPin == pin);
    }

public:
    void withdrawCash(long long enteredCard, int enteredPin, double amount) {
        if (verifyCredentials(enteredCard, enteredPin)) {
            if (amount <= balance) {
                balance -= amount;
                cout << "Withdrawal successful. Remaining balance: " << balance << endl;
            } else {
                cout << "Insufficient balance." << endl;
            }
        } else {
            cout << "Invalid card number or PIN" << endl;
        }
    }

    void checkBalance(long long enteredCard, int enteredPin) {
        if (verifyCredentials(enteredCard, enteredPin)) {
            cout << "Your balance is: " << balance << endl;
        } else {
            cout << "Invalid card number or PIN" << endl;
        }
    }
};

int main() {
    Account myAcc;

    long long validCard = 1234567890123456;
    int validPin = 1234;

    // Case 1: Correct card and PIN
    myAcc.withdrawCash(validCard, validPin, 1000);

    // Case 2: Correct card and PIN, but insufficient balance
    myAcc.withdrawCash(validCard, validPin, 6000);

    // Case 3: Incorrect card
    myAcc.withdrawCash(9999999999999999, validPin, 500);

    // Case 4: Incorrect PIN
    myAcc.withdrawCash(validCard, 1111, 500);

    // Check final balance
    myAcc.checkBalance(validCard, validPin);

    return 0;
}