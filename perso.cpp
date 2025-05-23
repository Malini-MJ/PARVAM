#include <iostream>
using namespace std;
class Person {
   string name;
   int age;
public:
    Person() {
        name = "Anonymous";
        age = 0;
    }
    Person(string n, int a) {
        name = n;
        age = a;
    }
    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};
int main() {
    Person p1;
    Person p2("Alice", 25);
    p1.display();
    p2.display();
    return 0;
}