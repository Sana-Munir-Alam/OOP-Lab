#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

// Base Class
class BankAccount {
    protected:
        int AccountNumber;
        double Balance;
        string AccountHolderName;
        string AccountType;
        vector<string> Transactions;  // Store transaction history

    public:
        // Parameterized Constructor
        BankAccount(int AccNum, double Bal, string Name, string Type) : AccountNumber(AccNum), Balance(Bal), AccountHolderName(Name), AccountType(Type) {}

        // Virtual Destructor
        virtual ~BankAccount() {}

        // Deposit Money
        void Deposit(double Amount) {
            Balance += Amount;
            Transactions.push_back("Deposited $" + to_string(Amount));
            cout << fixed << setprecision(2) << "Deposited $" << Amount << " into Account " << AccountNumber << endl;
        }

        // Withdraw Money (Virtual for Overriding)
        virtual void Withdraw(double Amount) {
            if (Amount <= Balance) {
                Balance -= Amount;
                Transactions.push_back("Withdrew $" + to_string(Amount));
                cout << fixed << setprecision(2) << "Withdrawn $" << Amount << " from Account " << AccountNumber << endl;
            } else {
                cout << "Insufficient funds in Account " << AccountNumber << endl;
            }
        }

        // Virtual Interest Calculation
        virtual void CalculateInterest() {
            cout << "No specific Interest rule for this account Type." << endl;
        }

        // Print Statement
        virtual void PrintStatement() {
            cout << endl << "Transaction history for Account " << AccountNumber << ":" << endl;
            for (const auto &transaction : Transactions) {
                cout << transaction << endl;
            }
        }

        // Get Account Info
        void GetAccountInfo() const {
            cout << fixed << setprecision(2);  // Set precision to 2 decimal places
            cout << "~---------- Account Info ----------~\n";
            cout << "Account Holder Name: " << AccountHolderName << endl;
            cout << "Account Number: " << AccountNumber << endl;
            cout << "Account Type: " << AccountType << endl;
            cout << "Current Balance: $" << Balance << endl;
        }
};

// Derived class for SavingsAccount
class SavingsAccount : public BankAccount {
private:
    double InterestRate;
    double MinimumBalance;
public:
    SavingsAccount(int AccNum, double Bal, string Name, string Type, double Rate, double MinBal) : BankAccount(AccNum, Bal, Name, Type), InterestRate(Rate), MinimumBalance(MinBal) {}

    // Calculate Monthly Interest
    void CalculateInterest() override {
        double Interest = Balance * (InterestRate / 100);
        Balance += Interest;
        Transactions.push_back("Interest added: $" + to_string(Interest));
        cout << fixed << setprecision(2) << "Applied Interest of $" << Interest << " to Account " << AccountNumber << " Current Balance: $" << Balance << endl;
    }

    // Withdraw Money with Minimum Balance Restriction
    void Withdraw(double Amount) override {
        if ((Balance - Amount) >= MinimumBalance) {
            Balance -= Amount;
            Transactions.push_back("Withdrew $" + to_string(Amount));
            cout << fixed << setprecision(2) << "Withdrawn $" << Amount << " from Account " << AccountNumber << endl;
        } else {
            cout << "Transaction denied! Minimum Balance limit reached in Account " << AccountNumber << endl;
        }
    }
};

// Derived class for CheckingAccount
class CheckingAccount : public BankAccount {
    private:
        double OverdraftLimit;
        bool OverdraftAlert;
    public:
        CheckingAccount(int AccNum, double Bal, string Name, string Type, double limit) : BankAccount(AccNum, Bal, Name, Type), OverdraftLimit(limit), OverdraftAlert(false) {}

        // Withdraw with Overdraft Protection
        void Withdraw(double Amount) override {
            if (Amount <= Balance + OverdraftLimit) {
                Balance -= Amount;
                Transactions.push_back("Withdrew $" + to_string(Amount));
                cout << fixed << setprecision(2) << "Withdrawn $" << Amount << " from Account " << AccountNumber << endl;
                if (Balance < 0) {
                    OverdraftAlert = true;
                    cout << "ALERT: Overdraft Limit exceeded for Account " << AccountNumber << endl;
                }
            } else {
                cout << "Withdrawal denied. Exceeds overdraft limit for Account " << AccountNumber << endl;
            }
        }

        // Adjust Overdraft Limit
        void adjustLimit(double newLimit) {
            OverdraftLimit = newLimit;
            cout << "Overdraft limit for Account " << AccountNumber << " adjusted to $" << newLimit << endl;
        }
};

// Derived class for FixedDepositAccount
class FixedDepositAccount : public BankAccount {
    private:
        int MaturePeriod;  // in months
        double FixedInterestRate;

    public:
        FixedDepositAccount(int AccNum, double Bal, string Name, string Type, double Rate, int period) : BankAccount(AccNum, Bal, Name, Type), FixedInterestRate(Rate), MaturePeriod(period) {}

        // Calculate Compound Interest (Assuming Yearly Compound)
        void CalculateInterest() override {
            // Formula for compound interest: A = P * (1 + r/n)^(n*t)
                // where:
                // P = principal amount
                // r = annual interest rate (in decimal form)
                // n = number of times interest is compounded per year (for annually, n = 1)
                // t = time the money is invested for (in years)
            double Interest = (Balance * pow(1 + FixedInterestRate / 100, MaturePeriod / 12.0)) - Balance;
            Balance += Interest;
            Transactions.push_back("Fixed Deposit Interest added: $" + to_string(Interest));
            cout << fixed << setprecision(2) << "Applied Interest of $" << Interest << " to Account " << AccountNumber << " Current Balance: $" << Balance << endl;
        }

        // Withdraw Restriction
        void Withdraw(double Amount) override {
            cout << "Withdrawals are not allowed until maturity period is over in Account " << AccountNumber << endl;
        }
};

// Main Function for Testing
int main() {
    // Create Accounts
    SavingsAccount savAcc(1001, 5000.0, "Richard", "Savings", 3.5, 1000);
    CheckingAccount chkAcc(1002, 2000.0, "Christopher", "Checking", 500);
    FixedDepositAccount fdAcc(1003, 10000.0, "Edward", "Fixed Deposit", 5.0, 24);
    
    cout << "------------------------------------" << endl;
    savAcc.GetAccountInfo();
    cout << endl << "------------------------------------" << endl;
    
    // Perform Transactions
    savAcc.Deposit(1500);
    savAcc.Withdraw(2000);
    savAcc.CalculateInterest();
    savAcc.PrintStatement();

    cout << endl << "------------------------------------" << endl;
    chkAcc.GetAccountInfo();
    cout << endl << "------------------------------------" << endl;

    chkAcc.Deposit(3000);
    chkAcc.Withdraw(2500);
    chkAcc.Withdraw(3000);  // Overdraft limit test
    chkAcc.PrintStatement();

    cout << endl << "------------------------------------" << endl;
    fdAcc.GetAccountInfo();
    cout << endl << "------------------------------------" << endl;

    fdAcc.CalculateInterest();
    fdAcc.Withdraw(500);  // Should be restricted
    fdAcc.PrintStatement();

    return 0;
}
