#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int regno;
    string email;
};

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student* students = new Student[n];

    cout << "\nEnter student details (name regno email):\n";
    for (int i = 0; i < n; i++) {
        cout << "Student " << i + 1 << ":\n";
        cout << "  Name: ";
        cin >> students[i].name;
        cout << "  Reg No: ";
        cin >> students[i].regno;
        cout << "  Email: ";
        cin >> students[i].email;
    }

    char choice;
    do {
        string searchStr;
        int searchReg;
        bool found = false;

        cout << "\nSearch by:\n1. Name\n2. Reg No\n3. Email\nEnter choice (1/2/3): ";
        int searchOption;
        cin >> searchOption;

        for (int i = 0; i < n; i++) {
            if (searchOption == 1) {
                cout << "Enter name to search: ";
                cin >> searchStr;
                if (students[i].name == searchStr) {
                    cout << "\nStudent Found:\n";
                    cout << "  Name: " << students[i].name << "\n";
                    cout << "  Reg No: " << students[i].regno << "\n";
                    cout << "  Email: " << students[i].email << "\n";
                    found = true;
                }
            } else if (searchOption == 2) {
                cout << "Enter reg no to search: ";
                cin >> searchReg;
                if (students[i].regno == searchReg) {
                    cout << "\nStudent Found:\n";
                    cout << "  Name: " << students[i].name << "\n";
                    cout << "  Reg No: " << students[i].regno << "\n";
                    cout << "  Email: " << students[i].email << "\n";
                    found = true;
                }
            } else if (searchOption == 3) {
                cout << "Enter email to search: ";
                cin >> searchStr;
                if (students[i].email == searchStr) {
                    cout << "\nStudent Found:\n";
                    cout << "  Name: " << students[i].name << "\n";
                    cout << "  Reg No: " << students[i].regno << "\n";
                    cout << "  Email: " << students[i].email << "\n";
                    found = true;
                }
            }
        }

        if (!found) {
            cout << "\nNo student found with that detail.\n";
        }

        cout << "\nDo you want to search again? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    delete[] students;
    return 0;
}
