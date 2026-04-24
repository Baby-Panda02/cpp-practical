#include <iostream>
#include <string>
using namespace std;

// ========== (a) Base Class with Constructors ==========
class Student {
protected:
    string name;
    int roll;

public:
    static int count; // (d) Static member

    // Default Constructor
    Student() {
        name = "";
        roll = 0;
        count++;
    }

    // Parameterized Constructor
    Student(string n, int r) {
        name = n;
        roll = r;
        count++;
    }

    // Virtual Destructor (good practice)
    virtual ~Student() {}

    // (c) Virtual function for Runtime Polymorphism
    virtual void display() {
        cout << "Name: " << name << endl;
        cout << "Roll: " << roll << endl;
    }
};

// Initialize static member
int Student::count = 0;


// ========== (b) Derived Class with Inheritance ==========
class Result : public Student {
    int m1, m2, m3, total;

public:
    // Constructor calling base constructor
    Result(string n, int r, int a, int b, int c)
        : Student(n, r) {
        m1 = a;
        m2 = b;
        m3 = c;
        total = m1 + m2 + m3;
    }

    // Override display() for Runtime Polymorphism
    void display() override {
        Student::display();
        cout << "Total Marks: " << total << endl;
    }
};


// ========== (e) Operator Overloading Class ==========
class Marks {
public:
    int total;

    Marks(int t = 0) {
        total = t;
    }

    // Overload + operator to add marks
    Marks operator+(const Marks &m) {
        return Marks(total + m.total);
    }
};


// ========== Main Function ==========
int main() {
    // Create object
    Result r("Suraj", 1, 80, 90, 85);

    // (c) Runtime Polymorphism - base pointer calls derived display()
    Student* s = &r;
    s->display();

    // (e) Operator Overloading
    Marks m1(200), m2(150);
    Marks m3 = m1 + m2;
    cout << "Combined Marks: " << m3.total << endl;

    // (d) Static Member
    cout << "Total Students: " << Student::count << endl;

    return 0;
}
