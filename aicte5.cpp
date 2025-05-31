#include <iostream>
#include <string>
#include <vector>
#include <fstream> 

using namespace std;

struct student {
    string name;
    int age;
    string course;
    string mail;
    string regno;
    string nsscategory;
};

struct college {
    string name;
    vector<student> students;
};

void displaycategories() {
    cout << "1. Blood Donation Camp" << endl;
    cout << "2. Rural Development Drives" << endl;
    cout << "3. Environmental Awareness Program" << endl;
    cout << "4. Backward Literacy Program" << endl;
}

string getcategory(int choice) {
    switch (choice) {
        case 1: return "Blood Donation Camp";
        case 2: return "Rural Development Drives";
        case 3: return "Environmental Awareness Program";
        case 4: return "Backward Literacy Program";
        default: return "Unassigned";
    }
}

void displayStudent(const student& s, const string& collegeName, ostream& out) {
    out << "-----------------------------\n";
    out << "Name: " << s.name << endl;
    out << "Age: " << s.age << endl;
    out << "College: " << collegeName << endl;
    out << "Course: " << s.course << endl;
    out << "Mail ID: " << s.mail << endl;
    out << "Register No: " << s.regno << endl;
    out << "NSS Category: " << s.nsscategory << endl;
}

int main() {
    vector<college> colleges;
    int nocolleges;

    cout << "Enter number of colleges: ";
    cin >> nocolleges;
    cin.ignore();

    for (int i = 0; i < nocolleges; i++) {
        college c;
        cout << "======= Enter Details for College " << i + 1 << " =======" << endl;
        cout << "College Name: ";
        getline(cin, c.name);

        int nostudents;
        cout << "Enter number of students in " << c.name << ": ";
        cin >> nostudents;
        cin.ignore();

        for (int j = 0; j < nostudents; j++) {
            student s;
            cout << "---- Enter Details for Student " << j + 1 << " ----" << endl;
            cout << "Name: ";
            getline(cin, s.name);

            cout << "Age: ";
            cin >> s.age;
            cin.ignore();

            cout << "Course: ";
            getline(cin, s.course);

            cout << "Mail ID: ";
            getline(cin, s.mail);

            cout << "Register No: ";
            getline(cin, s.regno);

            displaycategories();
            int nsschoice;
            cout << "Enter NSS category (1-4): ";
            cin >> nsschoice;
            cin.ignore();

            s.nsscategory = getcategory(nsschoice);
            if (s.nsscategory == "Unassigned") {
                cout << "Invalid category. Assigned as 'Unassigned'." << endl;
            }

            c.students.push_back(s);
        }

        colleges.push_back(c);
    }

   
    ofstream outfile("output.txt"); 
    int choice;
    do {
        cout << "\n=========== Search Menu ===========" << endl;
        cout << "1. Search by Student Name" << endl;
        cout << "2. Search by Mail ID" << endl;
        cout << "3. Search by NSS Category" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string name;
            cout << "Enter student name to search: ";
            getline(cin, name);

            bool found = false;
            for (const auto& c : colleges) {
                for (const auto& s : c.students) {
                    if (s.name == name) {
                        displayStudent(s, c.name, cout);
                        displayStudent(s, c.name, outfile);
                        found = true;
                    }
                }
            }
            if (!found) {
                cout << "No student found with that name." << endl;
                outfile << "No student found with name: " << name << endl;
            }
        }
        else if (choice == 2) {
            string mail;
            cout << "Enter student mail ID to search: ";
            getline(cin, mail);

            bool found = false;
            for (const auto& c : colleges) {
                for (const auto& s : c.students) {
                    if (s.mail == mail) {
                        displayStudent(s, c.name, cout);
                        displayStudent(s, c.name, outfile);
                        found = true;
                    }
                }
            }
            if (!found) {
                cout << "No student found with that Mail ID." << endl;
                outfile << "No student found with Mail ID: " << mail << endl;
            }
        }
        else if (choice == 3) {
            string category;
            cout << "Enter NSS category (case sensitive): ";
            getline(cin, category);

            bool found = false;
            for (const auto& c : colleges) {
                for (const auto& s : c.students) {
                    if (s.nsscategory == category) {
                        displayStudent(s, c.name, cout);
                        displayStudent(s, c.name, outfile);
                        found = true;
                    }
                }
            }
            if (!found) {
                cout << "No students found in that NSS category." << endl;
                outfile << "No students found in category: " << category << endl;
            }
        }
        else if (choice == 4) {
            cout << "Exiting program." << endl;
        }
        else {
            cout << "Invalid choice." << endl;
        }

    } while (choice != 4);

    outfile.close();
    cout << "\nSearch results saved to 'output.txt' \n";
    return 0;
}