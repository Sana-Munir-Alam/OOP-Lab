#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Polynomial; // Forward declaration

// Utility class for Polynomial operations
class PolynomialUtils {
    public:
        static int evaluate(const Polynomial& p, int x);    // Evaluate polynomial at a given x
        static Polynomial derivative(const Polynomial& p);  // Compute derivative of a polynomial
};

class Polynomial {
    private:
        vector<int> Coefficients;   //The index of each element represents the exponent of x

        void trim() {   // If coefficients = {3, 2, 0, 0}, after calling trim(), it becomes {3, 2}
            while (!Coefficients.empty() && Coefficients.back() == 0) {
                Coefficients.pop_back();
            }
        }
    public:
        // Friend class declaration
        friend class PolynomialUtils;

        Polynomial() {} // Default constructor

        Polynomial(const vector<int>& coeffs) : Coefficients(coeffs) {  // Paramatrized Constructor
            trim();
        }

        // Overloaded addition
        Polynomial operator+(const Polynomial& other) const {
            vector<int> result(max(Coefficients.size(), other.Coefficients.size()), 0);
            for (size_t i = 0; i < Coefficients.size(); ++i) {
                result[i] += Coefficients[i];
            }
            for (size_t i = 0; i < other.Coefficients.size(); ++i) {
                result[i] += other.Coefficients[i];
            }
            return Polynomial(result);
        }
        // Overloaded subtraction
        Polynomial operator-(const Polynomial& other) const {
            vector<int> result(max(Coefficients.size(), other.Coefficients.size()), 0);
            for (size_t i = 0; i < Coefficients.size(); ++i) {
                result[i] += Coefficients[i];
            }
            for (size_t i = 0; i < other.Coefficients.size(); ++i) {
                result[i] -= other.Coefficients[i];
            }
            return Polynomial(result);
        }
        // Overloaded multiplication
        Polynomial operator*(const Polynomial& other) const {
            vector<int> result(Coefficients.size() + other.Coefficients.size() - 1, 0);
            for (size_t i = 0; i < Coefficients.size(); ++i) {  //Uses nested loops to multiply every term in the first polynomial with every term in the second.
                for (size_t j = 0; j < other.Coefficients.size(); ++j) {
                    result[i + j] += Coefficients[i] * other.Coefficients[j];
                }
            }
            return Polynomial(result);
        }

        // Overloaded output stream operator
        friend ostream& operator<<(ostream& os, const Polynomial& p) {
            if (p.Coefficients.empty()) {
                os << "0";
                return os;
            }
            bool firstTerm = true;
            for (int i = p.Coefficients.size() - 1; i >= 0; --i) {
                int coef = p.Coefficients[i];

                if (coef == 0) continue;

                if (!firstTerm) {
                    os << (coef > 0 ? " + " : " - ");
                } else if (coef < 0) {
                    os << "-";
                }

                int absCoef = abs(coef);
                if (absCoef != 1 || i == 0) {
                    os << absCoef;
                }
                if (i > 0) {
                    os << "x";
                    if (i > 1) {
                        os << "^" << i;
                    }
                }
                firstTerm = false;
            }
            return os;
        }
};

// Implementation of PolynomialUtils
int PolynomialUtils::evaluate(const Polynomial& p, int x) {
    int result = 0;
    int power = 1; // x^0
    for (int coef : p.Coefficients) {
        result += coef * power;
        power *= x;
    }
    return result;
}

Polynomial PolynomialUtils::derivative(const Polynomial& p) {
    if (p.Coefficients.size() <= 1) {
        return Polynomial({0});
    }
    vector<int> DerivCoeffs(p.Coefficients.size() - 1);
    for (size_t i = 1; i < p.Coefficients.size(); ++i) {
        DerivCoeffs[i - 1] = p.Coefficients[i] * i;
    }
    return Polynomial(DerivCoeffs);
}

// Main function to demonstrate functionalities
int main() {
    // Creating polynomials
    Polynomial p1({3, 0, 2});  // 3 + 0x + 2x^2
    Polynomial p2({1, -1, 1}); // 1 - x + x^2

    cout << endl << "----- Polynomial Operations -----" << endl;
    cout << "P1: " << p1 << endl;
    cout << "P2: " << p2 << endl;

    // Arithmetic operations
    cout << endl << "----- Arithmetic Operations -----" << endl;
    cout << "P1 + P2 = " << (p1 + p2) << endl;
    cout << "P1 - P2 = " << (p1 - p2) << endl;
    cout << "P1 * P2 = " << (p1 * p2) << endl;

    // Evaluating polynomials
    int x = 2;
    cout << endl << "----- Polynomial Evaluation -----" << endl;
    cout << "P1(" << x << ") = " << PolynomialUtils::evaluate(p1, x) << endl;
    cout << "P2(" << x << ") = " << PolynomialUtils::evaluate(p2, x) << endl;

    // Computing derivatives
    cout << endl << "----- Derivatives -----" << endl;
    cout << "d/dx P1 = " << PolynomialUtils::derivative(p1) << endl;
    cout << "d/dx P2 = " << PolynomialUtils::derivative(p2) << endl;

    return 0;
}
