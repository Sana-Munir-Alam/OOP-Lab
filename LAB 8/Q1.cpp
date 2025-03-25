#include <iostream>

using namespace std;

class Fraction {
    private:
        int Numerator;
        int Denominator;

        // Helper function to compute GCD
        int FindGCD(int a, int b) {
            while (b != 0) {
                int temp = b;
                b = a % b;
                a = temp;
            }
            return a;
        }
        // Function to Simplify the fraction
        void Simplify() {
            int g = FindGCD(abs(Numerator), abs(Denominator));
            Numerator /= g;
            Denominator /= g;
            // Ensuring Denominator is positive
            if (Denominator < 0) {
                Numerator = -Numerator;
                Denominator = -Denominator;
            }
        }
    public:
        // Constructor
        Fraction(int num = 0, int denom = 1) {
            if (denom == 0) {   // Handling an edge case
                throw invalid_argument("Denominator cannot be zero");
            }
            Numerator = num;
            Denominator = denom;
            Simplify();
        }
        // Arithmetic operators
        Fraction operator+(const Fraction& other) const {
            return Fraction(Numerator * other.Denominator + other.Numerator * Denominator, Denominator * other.Denominator);
        }
        Fraction operator-(const Fraction& other) const {
            return Fraction(Numerator * other.Denominator - other.Numerator * Denominator, Denominator * other.Denominator);
        }
        Fraction operator*(const Fraction& other) const {
            return Fraction(Numerator * other.Numerator, Denominator * other.Denominator);
        }
        Fraction operator/(const Fraction& other) const {
            if (other.Numerator == 0) {
                throw invalid_argument("Cannot divide by zero");
            }
            return Fraction(Numerator * other.Denominator, Denominator * other.Numerator);
        }

        // Relational operators
        bool operator==(const Fraction& other) const {
            return Numerator == other.Numerator && Denominator == other.Denominator;
        }
        bool operator!=(const Fraction& other) const {
            return !(*this == other);
        }
        bool operator<(const Fraction& other) const {
            return Numerator * other.Denominator < other.Numerator * Denominator;
        }
        bool operator>(const Fraction& other) const {
            return Numerator * other.Denominator > other.Numerator * Denominator;
        }
        bool operator<=(const Fraction& other) const {
            return !(*this > other);
        }
        bool operator>=(const Fraction& other) const {
            return !(*this < other);
        }

        // Input and output stream operators
        friend ostream& operator<<(ostream& os, const Fraction& f) {
            os << f.Numerator;
            if (f.Denominator != 1) {
                os << "/" << f.Denominator;
            }
            return os;
        }

        friend istream& operator>>(istream& is, Fraction& f) {
            char slash;
            is >> f.Numerator >> slash >> f.Denominator;
            if (f.Denominator == 0) {
                throw invalid_argument("Denominator cannot be zero");
            }
            f.Simplify();
            return is;
        }
};

int main() {
    Fraction f1, f2;
    cout << "Enter two fractions in the form 'a/b': ";
    cin >> f1 >> f2;

    // Displaying the fractions
    cout << "\n----- Input and Output -----" << endl;
    cout << "Fraction 1: " << f1 << endl;
    cout << "Fraction 2: " << f2 << endl;

    // Arithmetic Operations
    cout << "\n----- Arithmetic Operations -----" << endl;
    cout << f1 << " + " << f2 << " = " << (f1 + f2) << endl;
    cout << f1 << " - " << f2 << " = " << (f1 - f2) << endl;
    cout << f1 << " * " << f2 << " = " << (f1 * f2) << endl;
    cout << f1 << " / " << f2 << " = " << (f1 / f2) << endl;

    // Relational Comparisons
    cout << "\n----- Relational Comparisons -----" << endl;
    cout << f1 << " == " << f2 << " ? " << (f1 == f2 ? "True" : "False") << endl;
    cout << f1 << " != " << f2 << " ? " << (f1 != f2 ? "True" : "False") << endl;
    cout << f1 << " < " << f2 << " ? " << (f1 < f2 ? "True" : "False") << endl;
    cout << f1 << " > " << f2 << " ? " << (f1 > f2 ? "True" : "False") << endl;
    cout << f1 << " <= " << f2 << " ? " << (f1 <= f2 ? "True" : "False") << endl;
    cout << f1 << " >= " << f2 << " ? " << (f1 >= f2 ? "True" : "False") << endl;

    return 0;
}
