#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>

using namespace std;

string getCurrentTime() {
    time_t now = time(0);
    char *dt = ctime(&now);
    string timestr(dt);
    timestr.pop_back();  // Removes the newline character
    return timestr;
}

void writeLog(int userID, const string &action) {
    ofstream outfile("log.txt", ios::app);
    if (!outfile) {
        cerr << "Error: Could not open log.txt for writing.\n";
        return;
    }
    outfile << "[UserID: " << userID << "] " << action << " at " << getCurrentTime() << endl;
    outfile.close();
    cout << "Log written successfully.\n";
}

void readLogs() {
    ifstream infile("log.txt");
    if (!infile) {
        cerr << "Error: Could not open log.txt for reading.\n";
        return;
    }
    cout << "Log file contents:\n";
    string line;
    while (getline(infile, line)) {
        cout << line << endl;
    }
    infile.close();
}

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
    int choice, userID;
    string action;
    
    do {
        cout << "\nLog Management Menu\n";
        cout << "1. Write a log\n";
        cout << "2. View all logs\n";
        cout << "3. Clear log file\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter user ID: ";
                cin >> userID;
                cin.ignore();
                cout << "Enter action (e.g., Logged In, Viewed Page): ";
                getline(cin, action);
                writeLog(userID, action);
                break;
                
            case 2:
                readLogs();
                break;

            case 3:
                clearLogs();
                break;

            case 4:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);
    
    return 0;
}
