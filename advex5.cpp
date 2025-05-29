#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <exception>

using namespace std;

// Custom Exception Classes
class InsufficientFundsException : public exception {
public:
    const char *what() const noexcept override {
        return "Withdrawal failed: Insufficient funds.";
    }
};

class AccountLockedException : public exception {
public:
    const char *what() const noexcept override {
        return "Account is locked due to 3 failed withdrawal attempts.";
    }
};

// Helper to get current time
string getCurrentTime() {
    time_t now = time(0);
    char *dt = ctime(&now);
    string timeStr(dt);
    timeStr.pop_back(); // Remove newline character
    return timeStr;
}

// Log function
void logAction(const string &message) {
    ofstream logFile("log.txt", ios::app);
    if (logFile) {
        logFile << "[" << getCurrentTime() << "] " << message << endl; // Fixed missing ()
        logFile.close();
    }
}

// Save balances to file
void saveBalances(double balances[], int size) {
    ofstream outFile("balances.txt");
    for (int i = 0; i < size; ++i) {
        outFile << balances[i] << endl;
    }
    outFile.close();
}

// Load balances from file
void loadBalances(double balances[], int size) {
    ifstream inFile("balances.txt");
    for (int i = 0; i < size && inFile; ++i) {
        inFile >> balances[i];
    }
    inFile.close();
}

// Clear log file
void clearLogs() {
    ofstream outfile("log.txt", ios::trunc);
    if (!outfile) {
        cerr << "Error: Could not open log.txt to clear.\n";
        return;
    }
    outfile.close();
    cout << "All logs have been cleared.\n";
}

int main() {
    const int USER_COUNT = 3;
    double balances[USER_COUNT] = {1000.0, 800.0, 1200.0}; // Default balance
    int failedAttempts[USER_COUNT] = {0};

    loadBalances(balances, USER_COUNT); // Load existing balances

    int userID;
    cout << "Enter user ID (0-2): ";
    cin >> userID;

    if (userID < 0 || userID >= USER_COUNT) {
        cout << "Invalid user ID.\n";
        return 1;
    }

    char choice;
    do {
        cout << "\n1. Check Balance\n2. Deposit\n3. Withdraw\n4. Clear Logs\n5. Exit\nEnter option: ";
        int option;
        cin >> option;

        try {
            switch (option) {
                case 1:
                    cout << "Balance: $" << balances[userID] << endl;
                    logAction("User " + to_string(userID) + " checked balance.");
                    break;

                case 2: {
                    double depositAmount;
                    cout << "Enter deposit amount: ";
                    cin >> depositAmount;
                    if (depositAmount <= 0) throw invalid_argument("Invalid deposit amount.");
                    balances[userID] += depositAmount;
                    cout << "Deposited $" << depositAmount << endl;
                    logAction("User " + to_string(userID) + " deposited $" + to_string(depositAmount));
                    break;
                }

                case 3: {
                    if (failedAttempts[userID] >= 3) throw AccountLockedException();

                    double withdrawAmount;
                    cout << "Enter withdraw amount: ";
                    cin >> withdrawAmount;

                    if (withdrawAmount < 0) throw invalid_argument("Invalid withdrawal amount.");
                    if (withdrawAmount > balances[userID]) {
                        failedAttempts[userID]++;
                        logAction("User " + to_string(userID) + " failed withdrawal attempt.");
                        if (failedAttempts[userID] >= 3) throw AccountLockedException();
                        throw InsufficientFundsException();
                    }

                    balances[userID] -= withdrawAmount;
                    cout << "Withdrawn $" << withdrawAmount << endl;
                    logAction("User " + to_string(userID) + " withdrew $" + to_string(withdrawAmount));
                    failedAttempts[userID] = 0; // Reset failed attempts on success
                    break;
                }

                case 4:
                    clearLogs();
                    break;

                case 5:
                    cout << "Exiting...\n";
                    break;

                default:
                    cout << "Invalid choice.\n";
            }
        }
        catch (const AccountLockedException &ex) {
            cout << "Error: " << ex.what() << endl;
            logAction("User " + to_string(userID) + " locked out.");
        }
        catch (const exception &ex) {
            cout << "Exception: " << ex.what() << endl;
            logAction("Exception for user " + to_string(userID) + ": " + ex.what());
        }

        saveBalances(balances, USER_COUNT); // Save balances after each transaction

        if (option != 5) {
            cout << "Do you want to continue (y/n)? ";
            cin >> choice;
        } else {
            choice = 'n'; // Exit program
        }

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
