#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Employee
{
    string name;
    string shift;
};
int main() 
{
    int n;
    cout << "Enter number of employees who checked in today: ";
    cin >> n;
    vector<Employee> employees(n);
    int morningCount = 0, afternoonCount = 0, nightCount = 0;
    for (int i = 0; i < n; ++i) 
    {
        cout << "\nEnter details for employee " << i + 1 << endl;
        cout << "Name: ";
        cin.ignore();
        getline(cin, employees[i].name);
        cout << "Shift (Morning/Afternoon/Night): ";
        getline(cin, employees[i].shift);
        if (employees[i].shift == "Morning" || employees[i].shift == "morning")
            morningCount++;
        else if (employees[i].shift == "Afternoon" || employees[i].shift == "afternoon")
            afternoonCount++;
        else if (employees[i].shift == "Night" || employees[i].shift == "night")
            nightCount++;
        else
            cout << "Invalid shift entered!" << endl;
    }

    cout << "\n--- Employee Shift List ---\n";
    for (int i = 0; i < n; ++i) 
    {
        cout << "Name: " << employees[i].name << ", Shift: " << employees[i].shift << endl;
    }
    
    cout << "\n--- Shift Count ---\n";
    cout << "Morning Shift  : " << morningCount << endl;
    cout << "Afternoon Shift: " << afternoonCount << endl;
    cout << "Night Shift    : " << nightCount << endl;
    return 0;
}