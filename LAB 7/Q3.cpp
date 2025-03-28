#include <iostream>
#include <iomanip>
using namespace std;

// Base Currency Class
class Currency {
    protected:
        double Amount;
        string CurrencyCode;
        string CurrencySymbol;
        double ExchangeRate; // Relative to USD (base currency)

    public:
        Currency(double amount, string code, string symbol, double rate) : Amount(amount), CurrencyCode(code), CurrencySymbol(symbol), ExchangeRate(rate) {}

        virtual ~Currency() {}

        // Convert to USD (Base Currency)
        virtual double convertToBase() const {
            return Amount * ExchangeRate;
        }

        // Convert to a target currency
        double convertTo(const Currency& targetCurrency) const {
            double baseAmount = convertToBase();
            return baseAmount / targetCurrency.ExchangeRate;
        }

        virtual void displayCurrency() const {
            cout << CurrencySymbol << fixed << setprecision(2) << Amount << " (" << CurrencyCode << ")" << endl;
        }
};

// Derived class: Dollar
class Dollar : public Currency {
    public:
        Dollar(double amount) : Currency(amount, "USD", "$", 1.0) {} // USD is the base

        double convertToBase() const override {
            return Amount; // USD itself is the base
        }

        void displayCurrency() const override {
            cout << "USD: " << CurrencySymbol << fixed << setprecision(2) << Amount << endl;
        }
};

// Derived class: Euro
class Euro : public Currency {
    public:
        Euro(double amount) : Currency(amount, "EUR", "€", 1.10) {} // Example: 1 EUR = 1.10 USD

        void displayCurrency() const override {
            cout << "Euro: " << CurrencySymbol << fixed << setprecision(2) << Amount << endl;
        }
};

// Derived class: Rupee
class Rupee : public Currency {
    public:
        Rupee(double amount) : Currency(amount, "INR", "₹", 0.012) {} // Example: 1 INR = 0.012 USD

        void displayCurrency() const override {
            cout << "Indian Rupee: " << CurrencySymbol << fixed << setprecision(2) << Amount << endl;
        }
};

// Main Function
int main() {
    // Create currency objects
    Dollar usd(100);  // 100 USD
    Euro eur(50);     // 50 EUR
    Rupee inr(5000);  // 5000 INR

    // Display original values
    cout << endl << "Original Currency Amounts:" << endl;
    usd.displayCurrency();
    eur.displayCurrency();
    inr.displayCurrency();

    // Convert and display results
    cout << endl << "Conversions:" << endl;
    cout << "100 USD to EUR: " << usd.convertTo(eur) << " EUR" << endl;
    cout << "50 EUR to USD: " << eur.convertTo(usd) << " USD" << endl;
    cout << "5000 INR to USD: " << inr.convertTo(usd) << " USD" << endl;

    return 0;
}
