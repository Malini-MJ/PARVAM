#include<iostream>
#include<string>
using namespace std;

struct employee {
    string name;
    string shift;
};

int main() {
    int n;
    cout << "Enter number of employees checked in today: ";
    cin >> n;

    employee* employees = new employee[n];

    int morning = 0, afternoon = 0, night = 0;

    for (int i = 0; i < n; i++) {
        cout << "Enter details for employee " << (i + 1) << endl;
        cout << "Name: ";
        cin >> employees[i].name;
        cout << "Shift (morning/afternoon/night): ";
        cin >> employees[i].shift;

        // Counting shifts
        if (employees[i].shift == "morning") {
            morning++;
        } else if (employees[i].shift == "afternoon") {
            afternoon++;
        } else if (employees[i].shift == "night") {
            night++;
        }
    }

    // Displaying shift counts
    cout << "Morning shift: " << morning << endl;
    cout << "Afternoon shift: " << afternoon << endl;
    cout << "Night shift: " << night << endl;

    // Free allocated memory
    delete[] employees;

    return 0;
}
