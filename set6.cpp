#include <iostream>
#include <string>
using namespace std;

// ========== (a) Base Class ==========
class Book {
protected:
    string title;
    double price;

public:
    static int count; // (d) Static member

    Book(string t = "", double p = 0) {
        title = t;
        price = p;
        count++;
    }

    // Virtual Destructor
    virtual ~Book() {}

    // (c) Virtual function for Runtime Polymorphism
    virtual void display() {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }
};

// Initialize static member
int Book::count = 0;


// ========== (b) Derived Class ==========
class EBook : public Book {
    double fileSize;

public:
    EBook(string t, double p, double fs)
        : Book(t, p) {
        fileSize = fs;
    }

    void display() override {
        Book::display();
        cout << "File Size: " << fileSize << " MB" << endl;
    }
};


// ========== (e) Operator Overloading Class ==========
class Price {
public:
    double value;

    Price(double v = 0) {
        value = v;
    }

    // Overload + to add two prices
    Price operator+(const Price &p) {
        return Price(value + p.value);
    }
};


// ========== Main Function ==========
int main() {
    // Create object
    EBook e("C++ Programming", 500, 5);

    // (c) Runtime Polymorphism
    Book* b = &e;
    b->display();

    // (e) Operator Overloading
    Price p1(200), p2(300);
    Price total = p1 + p2;
    cout << "Total Price: " << total.value << endl;

    // (d) Static Member
    cout << "Total Books: " << Book::count << endl;

    return 0;
}
