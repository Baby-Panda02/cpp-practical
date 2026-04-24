#include <iostream>
using namespace std;

// ========== (a) Base Class with Parameterized Constructor ==========
class Shape {
protected:
    double dim1, dim2;

public:
    static int count; // (d) Static member

    Shape(double d1, double d2) {
        dim1 = d1;
        dim2 = d2;
        count++;
    }

    // Virtual Destructor
    virtual ~Shape() {}

    // (c) Virtual function for Runtime Polymorphism
    virtual double area() {
        return 0;
    }
};

// Initialize static member
int Shape::count = 0;


// ========== (b) Derived Classes ==========
class Rectangle : public Shape {
public:
    Rectangle(double l, double b) : Shape(l, b) {}

    double area() override {
        return dim1 * dim2;
    }
};

class Triangle : public Shape {
public:
    Triangle(double b, double h) : Shape(b, h) {}

    double area() override {
        return 0.5 * dim1 * dim2;
    }
};


// ========== (e) Operator Overloading Class ==========
class Area {
public:
    double value;

    Area(double v = 0) {
        value = v;
    }

    // Overload + to add two areas
    Area operator+(const Area &a) {
        return Area(value + a.value);
    }
};


// ========== Main Function ==========
int main() {
    Rectangle r(5, 4);
    Triangle t(5, 4);

    // (c) Runtime Polymorphism
    Shape* s1 = &r;
    Shape* s2 = &t;

    double area1 = s1->area();
    double area2 = s2->area();

    // (e) Operator Overloading
    Area a1(area1), a2(area2);
    Area total = a1 + a2;

    cout << "Rectangle Area: " << area1 << endl;
    cout << "Triangle Area: " << area2 << endl;
    cout << "Total Area: " << total.value << endl;

    // (d) Static Member
    cout << "Total Shapes Created: " << Shape::count << endl;

    return 0;
}
