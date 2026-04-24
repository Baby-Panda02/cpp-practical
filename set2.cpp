#include <iostream>
#include <string>
using namespace std;

// ========== (a) Base Class with Parameterized Constructor ==========
class Account {
protected:
    string name;
    int account_no;
    double balance;

public:
    static int count; // (d) Static member

    // Parameterized Constructor
    Account(string n, int acc, double bal) {
        name = n;
        account_no = acc;
        balance = bal;
        count++;
    }

    // Virtual Destructor
    virtual ~Account() {}

    // (c) Virtual function for Runtime Polymorphism
    virtual void calculateInterest() {
        cout << "No Interest" << endl;
    }
};

// Initialize static member
int Account::count = 0;


// ========== (b) Derived Class with Inheritance ==========
class SavingsAccount : public Account {
    double rate;

public:
    SavingsAccount(string n, int acc, double bal, double r)
        : Account(n, acc, bal) {
        rate = r;
    }

    // Override for Runtime Polymorphism
    void calculateInterest() override {
        double interest = (balance * rate) / 100;
        cout << "Interest: " << interest << endl;
    }
};


// ========== (e) Operator Overloading Class ==========
class Amount {
public:
    double value;

    Amount(double v = 0) {
        value = v;
    }

    // Overload + operator to add balances
    Amount operator+(const Amount &a) {
        return Amount(value + a.value);
    }
};


// ========== Main Function ==========
int main() {
    // Create object
    SavingsAccount s("Suraj", 101, 1000, 5);

    // (c) Runtime Polymorphism via base pointer
    Account* acc = &s;
    acc->calculateInterest();

    // (e) Operator Overloading
    Amount a1(500), a2(300);
    Amount total = a1 + a2;
    cout << "Total Amount: " << total.value << endl;

    // (d) Static Member
    cout << "Total Accounts: " << Account::count << endl;

    return 0;
}
