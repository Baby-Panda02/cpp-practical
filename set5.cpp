#include <iostream>
using namespace std;

// ========== (a) Base Class ==========
class Distance {
protected:
    int feet, inches;

public:
    static int count; // (d) Static member

    Distance(int f = 0, int i = 0) {
        feet = f;
        inches = i;
        count++;
    }

    // Virtual Destructor
    virtual ~Distance() {}

    // (c) Virtual function for Runtime Polymorphism
    virtual void convert() {
        cout << "Base conversion" << endl;
    }

    // (e) Overload + operator to add two distances
    Distance operator+(const Distance &d) {
        int f = feet + d.feet;
        int i = inches + d.inches;

        // Normalize inches to feet
        f += i / 12;
        i = i % 12;

        return Distance(f, i);
    }

    void display() {
        cout << feet << " feet " << inches << " inches" << endl;
    }
};

// Initialize static member
int Distance::count = 0;


// ========== (b) Derived Class ==========
class DistanceConverter : public Distance {
public:
    DistanceConverter(int f, int i) : Distance(f, i) {}

    void convert() override {
        double meters = (feet * 12 + inches) * 0.0254;
        cout << "Distance in meters: " << meters << endl;
    }
};


// ========== Main Function ==========
int main() {
    DistanceConverter d1(5, 10);
    DistanceConverter d2(3, 8);

    // (c) Runtime Polymorphism
    Distance* d = &d1;
    d->convert();

    // (e) Operator Overloading
    Distance d3 = d1 + d2;
    cout << "Total Distance: ";
    d3.display();

    // (d) Static Member
    cout << "Total Distance Objects: " << Distance::count << endl;

    return 0;
}
