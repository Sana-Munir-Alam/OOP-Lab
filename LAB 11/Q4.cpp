#include <iostream>
using namespace std;

// Base class template
template<typename T>
class Base {
    protected:
        T a, b;
    public:
        Base(T x, T y) : a(x), b(y) {}

        // Method to multiply base class variables
        T multiplyBase() const {
            return a * b;
        }

        void displayBaseProduct() const {
            cout << "Base Class Product (a * b): " << multiplyBase() << endl;
        }
};

// Derived class template inheriting from Base<T>
template<typename T>
class Derived : public Base<T> {
    private:
        T c, d;
    public:
        // Constructor - initializes base and derived members
        Derived(T x, T y, T m, T n) : Base<T>(x, y), c(m), d(n) {}

        // Method to multiply derived class variables
        T multiplyDerived() const {
            return c * d;
        }

        void displayDerivedProduct() const {
            cout << "Derived Class Product (c * d): " << multiplyDerived() << endl;
        }
        void displayAllProducts() const {
            this->displayBaseProduct();
            displayDerivedProduct();
        }
};

int main() {
    try {
        Derived<int> obj(2, 3, 4, 5);
        cout << "Multiplication Results:" << endl;
        obj.displayAllProducts();
    } catch (const exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }
    return 0;
}
