#include <iostream>
using namespace std;

class FIR {
public:
    virtual void registerFIR(string name) = 0; 
};

class TheftFIR : public FIR {
public:
    void registerFIR(string name) override {
        cout << "Theft FIR registered for " << name  << endl;
        cout << "Action: Investigation started for stolen property." << endl << endl;
    }
};

class AccidentFIR : public FIR {
public:
    void registerFIR(string name) override {
        cout << "Accident FIR registered for " << name << endl;
        cout << "Action: Ambulance dispatched and accident site team notified." << endl << endl;
    }
};

class MissingPersonFIR : public FIR {
public:
    void registerFIR(string name) override {
        cout << "Missing Person FIR registered for " << name << endl;
        cout << "Action: Local patrol units alerted and investigation initiated." << endl << endl;
    }
};

int main() {
    cout << "=== FIR Registration ===" << endl;

    FIR* fir;

    fir = new TheftFIR();
    fir->registerFIR("Ravi");
    delete fir;

    fir = new AccidentFIR();
    fir->registerFIR("Sita");
    delete fir;

    fir = new MissingPersonFIR();
    fir->registerFIR("Karan");
    delete fir;

    return 0;
}