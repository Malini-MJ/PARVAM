#include <iostream>
using namespace std;

class Student {
public:
    string name, usnum, clgname;
    int age;

    // Using initializer list
    Student(string n, string usn, int a, string clgn) 
        : name(n), usnum(usn), age(a), clgname(clgn) 
    {
        cout << "Name: " << name << ", Age: " << age
             << ", USN: " << usnum << ", College Name: " << clgname << endl;
    }
};

int main() {
    Student s1("Student" ,"1CE24AI042",29, "City Engineering College");
    return 0;
}
