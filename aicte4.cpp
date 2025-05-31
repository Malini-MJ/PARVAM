#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

struct Student {
    string name;
    int age;
    string course;
    string email;
    string registerNumber;
    string nssCategory;
};

struct College {
    string name;
    string location;
    string collegeCode;
    vector<Student> students;
};

void displayNSSCategories() {
    cout << "\nNSS Categories:\n";
    cout << "1. Health\n";
    cout << "2. Education\n";
    cout << "3. Environment\n";
    cout << "4. Rural Development\n";
}

string getNSSCategory(int choice) {
    switch(choice) {
        case 1: return "Health";
        case 2: return "Education";
        case 3: return "Environment";
        case 4: return "Rural Development";
        default: return "Unassigned";
    }
}

int main() {
    int numColleges;
    vector<College> colleges;

    cout << "Enter the number of colleges: ";
    cin >> numColleges;
    cin.ignore(); // Clear buffer

    for (int i = 0; i < numColleges; ++i) {
        College college;
        cout << "\nEnter details for College " << i + 1 << ":\n";
        cout << "Name: ";
        getline(cin, college.name);
        cout << "Location: ";
        getline(cin, college.location);
        cout << "College Code: ";
        getline(cin, college.collegeCode);

        int numStudents;
        cout << "Enter number of students in this college: ";
        cin >> numStudents;
        cin.ignore();

        for (int j = 0; j < numStudents; ++j) {
            Student s;
            cout << "\nEnter details for Student " << j + 1 << ":\n";
            cout << "Name: ";
            getline(cin, s.name);
            cout << "Age: ";
            cin >> s.age;
            cin.ignore();
            cout << "Course: ";
            getline(cin, s.course);
            cout << "Email: ";
            getline(cin, s.email);
            cout << "Register Number: ";
            getline(cin, s.registerNumber);
            
            displayNSSCategories();
            int nssChoice;
            cout << "Enter NSS category number (1-4): ";
            cin >> nssChoice;
            cin.ignore();
            s.nssCategory = getNSSCategory(nssChoice);

            college.students.push_back(s);
        }

        colleges.push_back(college);
    }

    // Create and open output file
    ofstream outFile("aicte_output.txt");
    if (!outFile) {
        cout << " Error creating output file!\n";
        return 1;
    }

    // Write all data to file
    outFile << "========== AICTE College Approval Summary ==========\n";
    for (int i = 0; i < colleges.size(); ++i) {
        College& col = colleges[i];
        outFile << "\n--- College " << i + 1 << " ---\n";
        outFile << "Name: " << col.name << "\n";
        outFile << "Location: " << col.location << "\n";
        outFile << "College Code: " << col.collegeCode << "\n";

        for (int j = 0; j < col.students.size(); ++j) {
            Student& s = col.students[j];
            outFile << "\n  Student " << j + 1 << ":\n";
            outFile << "    Name: " << s.name << "\n";
            outFile << "    Age: " << s.age << "\n";
            outFile << "    Course: " << s.course << "\n";
            outFile << "    Email: " << s.email << "\n";
            outFile << "    Register Number: " << s.registerNumber << "\n";
            outFile << "    NSS Category: " << s.nssCategory << "\n";
        }
    }

    outFile.close();
    cout << "\n All data saved to 'aicte_output.txt' in the current folder.\n";

    return 0;
}