#include <iostream>
#include <string>
using namespace std;

// ========== (a) Base Class ==========
class Employee {
protected:
    string name;
    int id;

public:
    static int count; // (d) Static member

    Employee(string n, int i) {
        name = n;
        id = i;
        count++;
    }

    // Virtual Destructor
    virtual ~Employee() {}

    // (c) Virtual function for Runtime Polymorphism
    virtual double calculateSalary() {
        return 0;
    }
};

// Initialize static member
int Employee::count = 0;


// ========== (b) Derived Class ==========
class Manager : public Employee {
    double baseSalary;
    double bonus;

public:
    Manager(string n, int i, double bs, double b)
        : Employee(n, i) {
        baseSalary = bs;
        bonus = b;
    }

    double calculateSalary() override {
        return baseSalary + bonus;
    }
};


// ========== (e) Operator Overloading Class ==========
class Salary {
public:
    double amount;

    Salary(double a = 0) {
        amount = a;
    }

    // Overload + to combine salaries
    Salary operator+(const Salary &s) {
        return Salary(amount + s.amount);
    }
};


// ========== Main Function ==========
int main() {
    // Create object
    Manager m("Suraj", 101, 20000, 5000);

    // (c) Runtime Polymorphism
    Employee* e = &m;
    double sal = e->calculateSalary();

    // (e) Operator Overloading
    Salary s1(sal), s2(3000);
    Salary total = s1 + s2;

    cout << "Employee Salary: " << sal << endl;
    cout << "Total Combined Salary: " << total.amount << endl;

    // (d) Static Member
    cout << "Total Employees: " << Employee::count << endl;

    return 0;
}
