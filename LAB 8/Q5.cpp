#include <iostream>
using namespace std;

class Shape {
private:
    double Length, Width;  // Dimensions of the shape

public:
    // Paramatrized Constructor
    Shape(double L = 0, double W = 0) : Length(L), Width(W) {}

    double Area() const { return Length * Width; }

    // Overloading + operator to add areas of two shapes
    Shape operator+(const Shape& other) const {
        double totalArea = this->Area() + other.Area();  // Adding the areas
        return Shape(totalArea, 1); // Store total area in the Length, Width = 1
    }
    void display() const {
        cout << "Area: " << Area() << endl;
    }
};

int main() {
    Shape shape1(5, 4);  // Area = 5 * 4 = 20
    Shape shape2(3, 6);  // Area = 3 * 6 = 18

    cout << "Shape 1 ";
    shape1.display();

    cout << "Shape 2 ";
    shape2.display();

    // Using overloaded + operator
    Shape shape3 = shape1 + shape2;

    cout << "Total ";
    shape3.display(); // Output should be 20 + 18 = 38

    return 0;
}
