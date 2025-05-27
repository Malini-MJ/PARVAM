#include<iostream>
#include<string>
using namespace std;

class booking {
public:
    string customerName;
    int seats;

    booking(string name = "", int s = 1) : customerName(name), seats(s) {}

    virtual void bookticket() = 0;
    virtual ~booking() {}
};

class flightbooking : public booking {
public:
    flightbooking(string name, int s) : booking(name, s) {}
    void bookticket() override {
        cout << "flight ticket booked for " << customerName << " with " << seats << " seat(s)" << endl;
    }
};

class trainbooking : public booking {
public:
    trainbooking(string name, int s) : booking(name, s) {}
    void bookticket() override {
        cout << "train ticket booked for " << customerName << " with " << seats << " seat(s)" << endl;
    }
};

class carbooking : public booking {
public:
    carbooking(string name, int s) : booking(name, s) {}
    void bookticket() override {
        cout << "car ticket booked for " << customerName << " with " << seats << " seat(s)" << endl;
    }
};

class bookingmanager {
public:
    void confirmbooking(string name) {
        cout << "booking confirmed for: " << name << endl;
    }
    void confirmbooking(string name, int seats) {
        cout << "booking confirmed for: " << name << " with " << seats << " seat(s)" << endl;
    }
    void confirmbooking(string name, int seats, string date) {
        cout << "booking confirmed for: " << name << " with " << seats << " seat(s) on " << date << endl;
    }
};

class groupbooking {
public:
    int totalseats;
    groupbooking(int seats = 0) : totalseats(seats) {}

    groupbooking operator+(const groupbooking &other) {
        return groupbooking(this->totalseats + other.totalseats);
    }

    void displayy() {
        cout << "total group seats booked: " << totalseats << endl;
    }
};

int main() {
    booking *b1 = new flightbooking("Alice", 2);
    booking *b2 = new flightbooking("Bob", 3);
    booking *b3 = new flightbooking("Charlie", 6);

    cout << "==== Runtime Polymorphism ====" << endl;
    b1->bookticket();
    b2->bookticket();
    b3->bookticket();

    cout << "=== Function Overloading ===" << endl;
    bookingmanager manager;
    manager.confirmbooking("David");
    manager.confirmbooking("Emma", 4);
    manager.confirmbooking("Frankquee", 5, "02-06-2025");

    cout << "=== Operator Overloading ===" << endl;
    groupbooking group1(4);
    groupbooking group2(6);
    groupbooking totalgroup = group1 + group2;
    totalgroup.displayy();

    delete b1;
    delete b2;
    delete b3;

    return 0;
}
