#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class BigInteger {
private:
    vector<int> Digits; // Stores Digits from least to most significant
    bool IsNegative;    // Tracks if the number is negative

    // Helper function to remove leading zeros
    void trim() {
        while (Digits.size() > 1 && Digits.back() == 0)
            Digits.pop_back();
        if (Digits.size() == 1 && Digits[0] == 0)
            IsNegative = false; // Zero shouldn't be negative
    }

public:
    BigInteger() : IsNegative(false) {Digits.push_back(0); }

    // Constructor from string
    BigInteger(const string& num) {
        IsNegative = (num[0] == '-'); // Check if number is negative
        int start = (IsNegative || num[0] == '+') ? 1 : 0; // Skip sign
        
        for (int i = num.length() - 1; i >= start; --i){
            Digits.push_back(num[i] - '0'); // Store Digits in reverse order
        }
        trim(); // Remove leading zeros
    }

    // Overloaded addition operator
    BigInteger operator+(const BigInteger& other) const {
        if (IsNegative == other.IsNegative) {
            // Same sign, perform normal addition
            BigInteger result;
            result.IsNegative = IsNegative;
            result.Digits.clear();
            
            int carry = 0, sum = 0;
            int maxSize = max(Digits.size(), other.Digits.size());
            
            for (int i = 0; i < maxSize || carry; i++) {
                int d1 = (i < Digits.size()) ? Digits[i] : 0;
                int d2 = (i < other.Digits.size()) ? other.Digits[i] : 0;
                
                sum = d1 + d2 + carry;
                carry = sum / 10;
                result.Digits.push_back(sum % 10);
            }
            result.trim();
            return result;
        }
        // Different signs, perform subtraction
        return (*this) - (-other);
    }

    // Overloaded subtraction operator
    BigInteger operator-(const BigInteger& other) const {
        if (IsNegative != other.IsNegative)
            return *this + (-other); // Convert to addition

        if (*this == other)
            return BigInteger("0"); // Subtracting the same number

        // Determine which number is larger
        bool resultNegative = (*this < other);
        const BigInteger &larger = resultNegative ? other : *this;
        const BigInteger &smaller = resultNegative ? *this : other;

        BigInteger result;
        result.IsNegative = resultNegative;
        result.Digits.clear();

        int borrow = 0, diff = 0;
        for (size_t i = 0; i < larger.Digits.size(); ++i) {
            int d1 = larger.Digits[i];
            int d2 = (i < smaller.Digits.size()) ? smaller.Digits[i] : 0;

            diff = d1 - d2 - borrow;
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }

            result.Digits.push_back(diff);
        }
        result.trim();
        return result;
    }

    // Overloaded multiplication operator
    BigInteger operator*(const BigInteger& other) const {
        BigInteger result;
        result.Digits = vector<int>(Digits.size() + other.Digits.size(), 0);
        result.IsNegative = (IsNegative != other.IsNegative);

        for (size_t i = 0; i < Digits.size(); ++i) {
            int carry = 0;
            for (size_t j = 0; j < other.Digits.size() || carry; ++j) {
                int d1 = Digits[i];
                int d2 = (j < other.Digits.size()) ? other.Digits[j] : 0;
                int sum = result.Digits[i + j] + d1 * d2 + carry;
                carry = sum / 10;
                result.Digits[i + j] = sum % 10;
            }
        }
        result.trim();
        return result;
    }

    // Overloaded negation operator (-)
    BigInteger operator-() const {
        BigInteger negated = *this;
        if (*this != BigInteger("0")) {
            negated.IsNegative = !IsNegative;
        }
        return negated;
    }

    // Comparison operators
    bool operator==(const BigInteger& other) const {
        return (Digits == other.Digits && IsNegative == other.IsNegative);
    }

    bool operator!=(const BigInteger& other) const {
        return !(*this == other);
    }

    bool operator<(const BigInteger& other) const {
        if (IsNegative != other.IsNegative) {return IsNegative;}

        if (Digits.size() != other.Digits.size()) {return (Digits.size() < other.Digits.size()) ^ IsNegative; }

        for (int i = Digits.size() - 1; i >= 0; --i) {
            if (Digits[i] != other.Digits[i]) {
                return (Digits[i] < other.Digits[i]) ^ IsNegative;
            }
        }
        return false;
    }

    bool operator>(const BigInteger& other) const {
        return other < *this;
    }

    bool operator<=(const BigInteger& other) const {
        return !(*this > other);
    }

    bool operator>=(const BigInteger& other) const {
        return !(*this < other);
    }

    // Overloaded input operator (>>)
    friend istream& operator>>(istream& in, BigInteger& num) {
        string input;
        in >> input;
        num = BigInteger(input);
        return in;
    }

    // Overloaded output operator (<<)
    friend ostream& operator<<(ostream& out, const BigInteger& num) {
        if (num.IsNegative){
            out << "-";
        }
        for (int i = num.Digits.size() - 1; i >= 0; --i){
            out << num.Digits[i];
        }
        return out;
    }
};

// Main function for testing
int main() {
    BigInteger num1, num2;
    cout << "Enter first large number: ";
    cin >> num1;
    cout << "Enter second large number: ";
    cin >> num2;

    cout << "Sum: " << (num1 + num2) << endl;
    cout << "Difference: " << (num1 - num2) << endl;
    cout << "Product: " << (num1 * num2) << endl;
    cout << "Comparison: " << ((num1 > num2) ? "num1 is greater" : "num2 is greater or equal") << endl;

    return 0;
}
