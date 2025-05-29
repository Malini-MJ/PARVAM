#include <iostream>
using namespace std;
int main() {
    try {
        int age = 15;
        if (age < 18) {
            throw age;
        } else {
            std::cout << "Access granted.\n";
        }
    } catch (int myNum) {
        std::cout << "Access denied. Age " << myNum << "\n";
    }
    return 0;
}