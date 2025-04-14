#include <iostream>
#include <string>

using namespace std;

// Abstract Class
class Shape{
    public:
        virtual float GetArea() = 0; // Pure Virtual Function
};

// Derived Class 1
class Rectangle : public Shape{
    private:
        float Width;
        float Height;
    public:
        Rectangle (float width, float height) : Width(width), Height(height){
            // Paramatrized Constructor
        }
        float GetArea() override {
            return Width * Height;
        }
};

// Derived Class 2
class Triangle : public Shape{
    private:
        float Base;
        float Height;
    public:
        Triangle (float base, float height) : Base(base), Height(height){
            // Paramatrized Constructor
        }
        float GetArea() override {
            return (Base * Height) / 2;
        }
};

int main(){
    Rectangle rect(10,20);
    Triangle tri(18,5);

    cout << "Area of Rectangle: " << rect.GetArea() << endl;
    cout << "Area of Triangle: " << tri.GetArea() << endl;

    return 0;
}
