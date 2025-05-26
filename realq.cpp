#include <iostream>
using namespace std;

class person {
    protected:
        string name;
        int age;
    public:
        void setdata(string n, int a) {
            name = n;
            age = a;
        }
};

class patient : public person {
    private:
        string disease;
        float bill;
    public:
        void setdetails(string d, float b) {
            disease = d;
            bill = b;
        }
        void showdetails() {
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
            cout << "Disease: " << disease << endl;
            cout << "Amount: " << bill << endl;
            cout << "Review patient's condition: " << disease << endl;
        }
};

int main() {
    patient p;
    p.setdata("Jose", 40);
    p.setdetails("Pneumonia", 30000);
    p.showdetails();

    return 0;
}
