#include<iostream>
using namespace std;

class Account {
private:
    double balance = 5000;
    int pin = 1234;
    string cardno = "9880183027"; // Changed to string

    bool verifyCredentials(int enteredPin, string enteredCard) { 
        return (enteredCard == cardno && enteredPin == pin);
    }

public:
    void withdrawCash(int enteredPin, string enteredCard, double amount) {
        if (verifyCredentials(enteredPin, enteredCard)) {
            if (amount <= balance) {
                balance -= amount;
                cout << "Withdrawal successful. Remaining balance: " << balance << endl;
            } else {
                cout << "Insufficient balance." << endl;
            }
        } else {
            cout << "Invalid credentials" << endl;
        }
    }

    void checkBalance(int enteredPin, string enteredCard) {
        if (verifyCredentials(enteredPin, enteredCard)) {
            cout << "Your balance is: " << balance << endl;
        } else {
            cout << "Invalid credentials" << endl;
        }
    }
};

int main() {
    Account myAcc;

    myAcc.withdrawCash(1234, "9880183027", 1000);  
    myAcc.withdrawCash(1234, "9880183027", 6000);  
    myAcc.withdrawCash(1111, "9880183027", 500);   
    myAcc.checkBalance(1234, "9880183027");       
    myAcc.withdrawCash(1234, "9999999999999999", 500); // No more overflow!

    return 0;
}
