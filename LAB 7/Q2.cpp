#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// Base Shape class
class Shape {
    protected:
        string Color;
        double BorderThickness;
    public:
        Shape(string c, double bt) : Color(c), BorderThickness(bt) {}
        virtual ~Shape() {}
        
        virtual void Draw() const = 0;
        virtual double CalculateArea() const = 0;
        virtual double CalculatePerimeter() const = 0;
};

// Circle class
class Circle : public Shape {
    private:
        double Radius;
    public:
        Circle(double r, string c, double bt) : Shape(c, bt), Radius(r) {}
        void Draw() const override {
            cout << "Drawing a Circle with Radius " << Radius << ", Color " << Color << " and border thickness " << BorderThickness << endl;
        }
        double CalculateArea() const override {
            return M_PI * Radius * Radius;
        }
        double CalculatePerimeter() const override {
            return 2 * M_PI * Radius;
        }
};

// Rectangle class
class Rectangle : public Shape {
    private:
        double Width, Height;
    public:
        Rectangle(double w, double h, string c, double bt) : Shape(c, bt), Width(w), Height(h) {}
        void Draw() const override {
            cout << "Drawing a Rectangle with Width " << Width << ", Height " << Height << " and Color " << Color << endl;
        }
        double CalculateArea() const override {
            return Width * Height;
        }
        double CalculatePerimeter() const override {
            return 2 * (Width + Height);
        }
};

// Triangle class
class Triangle : public Shape {
    private:
        double a, b, c;
    public:
        Triangle(double side1, double side2, double side3, string col, double bt) : Shape(col, bt), a(side1), b(side2), c(side3) {}
        void Draw() const override {
            cout << "Drawing a Triangle with sides " << a << ", " << b << ", " << c << " and Color " << Color << endl;
        }
        double CalculateArea() const override {
            double s = (a + b + c) / 2;
            return sqrt(s * (s - a) * (s - b) * (s - c));
        }
        double CalculatePerimeter() const override {
            return a + b + c;
        }
};

// Polygon class
class Polygon : public Shape {
    private:
        vector<double> sides;
    public:
        Polygon(vector<double> s, string col, double bt) : Shape(col, bt), sides(s) {}
        void Draw() const override {
            cout << "Drawing a Polygon with " << sides.size() << " sides and Color " << Color << endl;
        }
        double CalculateArea() const override {
            cout << "Area calculation for a  polygon is complex and depends on vertices." << endl;
            return 0;
        }
        double CalculatePerimeter() const override {
            double perimeter = 0;
            for (double side : sides) {
                perimeter += side;
            }
            return perimeter;
        }
};

int main() {
    Circle c(5, "Red", 2);
    Rectangle r(10, 5, "Blue", 1.5);
    Triangle t(3, 4, 5, "Green", 1);
    Polygon p({4, 5, 6, 7}, "Yellow", 2);

    Shape* shapes[] = {&c, &r, &t, &p};
    
    for (Shape* shape : shapes) {
        shape->Draw();
        cout << "Area: " << shape->CalculateArea() << endl;
        cout << "Perimeter: " << shape->CalculatePerimeter() << endl;
        cout << "----------------------------------" << endl;
    }
    
    return 0;
}
