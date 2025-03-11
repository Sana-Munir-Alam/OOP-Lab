#include <iostream>
#include <string>
using namespace std;

// Base class for BankAccount
class BankAccount {
    protected:
        string AccountNumber;
        double Balance;
        bool IsFrozen;
    public:
        BankAccount(string AccNum, double balance) : AccountNumber(AccNum), Balance(balance) , IsFrozen(false){}

        virtual ~BankAccount() {}

        // Common functionality
        void Deposit(double Amount) {
            if (IsFrozen) {
                cout << "Account " << AccountNumber << " is frozen. Deposit denied." << endl;
                return;
            }
            Balance += Amount;
            cout << "Deposited $" << Amount << " into Account " << AccountNumber << endl;
        }

        virtual void Withdraw(double Amount) {
            if (IsFrozen) {
                cout << "Account " << AccountNumber << " is frozen. Withdrawl denied." << endl;
                return;
            }
            if (Amount <= Balance) {
                Balance -= Amount;
                cout << "Withdrawn $" << Amount << " from Account " << AccountNumber << endl;
            } else {
                cout << "Insufficient funds in Account " << AccountNumber << endl;
            }
        }

        void DisplayBalance() const {
            cout << "Account " << AccountNumber << " balance: $" << Balance << endl;
        }

        // Freeze/Unfreeze Account
        void FreezeAccount() {
            IsFrozen = true;
            cout << "Account " << AccountNumber << " has been frozen." << endl;
        }
        void UnfreezeAccount() {
            IsFrozen = false;
            cout << "Account " << AccountNumber << " has been unfrozen." << endl;
        }
        bool IsAccountFrozen() const {
            return IsFrozen;
        }

        // Adjust Account limits (for Manager)
        virtual void AdjustLimit(double newLimit) {
            cout << "Account " << AccountNumber << " does not support limit adjustments." << endl;
        }
};

// Derived class for SavingsAccount
class SavingsAccount : public BankAccount {
    private:
        double InterestRate;
    public:
        SavingsAccount(string AccNum, double balance, double Rate) : BankAccount(AccNum, balance), InterestRate(Rate) {
            // Paramatrized Constructor which also calls the Parent class constructor
        }

        void ApplyMonthlyInterest() {
            if (IsFrozen) {
                cout << "Account " << AccountNumber << " is frozen. Deposit denied." << endl;
                return;
            }
            double Interest = Balance * InterestRate / 100;
            Balance += Interest;
            cout << "Applied monthly Interest of $" << Interest << " to Account " << AccountNumber << endl;
            cout << "Your Balance after Monthly interest is : $" << Balance << endl;
        }
};

// Derived class for CheckingAccount
class CheckingAccount : public BankAccount {
    private:
        double OverdraftLimit;
        bool OverdraftAlert;
    public:
        CheckingAccount(string AccNum, double balance, double Limit) : BankAccount(AccNum, balance), OverdraftLimit(Limit), OverdraftAlert(false) {
            // Paramatrized Constructor which also calls the Parent class constructor
        }
        
        // I am going along with an fixed amount of over draft system the bank uses like they can go max upto $[Money] when their actual balance is 0.
        void Withdraw(double Amount) override {
            if (IsFrozen) {
                cout << "Account " << AccountNumber << " is frozen. Withdrawl denied." << endl;
                return;
            }
            if (Amount <= Balance + OverdraftLimit) {
                Balance -= Amount;
                cout << "Withdrawn $" << Amount << " from Account " << AccountNumber << endl;
                if (Balance < 0) {  // This means that now the user Account money is empty and they are currently taking loan from the bank to continue paying.
                    OverdraftAlert = true;
                    cout << "ALERT: Overdraft Limit exceeded for Account " << AccountNumber << endl;
                }
            } else {    // When the withdraw money is greater than even the Over Limit money than the system stops the transaction.
                cout << "Withdrawal denied. Exceeds overdraft Limit for Account " << AccountNumber << endl;
            }
        }
        void AdjustLimit(double NewLimit) override {
            OverdraftLimit = NewLimit;
            cout << "Overdraft Limit for Account " << AccountNumber << " adjusted to $" << NewLimit << endl;
        }
};

// Derived class for BusinessAccount
class BusinessAccount : public BankAccount {
    private:
        double CorpoRateTaxRate;
    public:
        BusinessAccount(string AccNum, double balance, double TaxRate) : BankAccount(AccNum, balance), CorpoRateTaxRate(TaxRate) {
            // Paramatrized Constructor which also calls the Parent class constructor
        }

        void Deposit(double Amount) {
            if (IsFrozen) {
                cout << "Account " << AccountNumber << " is frozen. Deposit denied." << endl;
                return;
            }
            double Tax = Amount * CorpoRateTaxRate / 100;
            Balance += (Amount - Tax);
            cout << "Deposited $" << Amount << " into Account " << AccountNumber << " (CorpoRate Tax: $" << Tax << ")" << endl;
        }


};

// Base class for UserRole
class UserRole {
    public:
        virtual ~UserRole() {}
        virtual void PerformActions(BankAccount& Account) = 0; // Pure virtual function
};

class Customer : public UserRole {
    public:
        void PerformActions(BankAccount& Account) override {
            cout << endl << "Customer Actions:" << endl;
            Account.Deposit(100);
            Account.Withdraw(50);
            Account.DisplayBalance();
        }
};
    
// Base class for Employee
class Employee : public UserRole {
    public:
        virtual void FreezeAccount(BankAccount& Account) {
            Account.FreezeAccount();
        }
        virtual void UnfreezeAccount(BankAccount& Account) {
            Account.UnfreezeAccount();
        }
};

// Derived class for Teller
class Teller : public Employee {
    public:
        void PerformActions(BankAccount& Account) override {
            cout << endl << "Teller Actions:" << endl;
            Account.Deposit(500);
            Account.Withdraw(100);
            FreezeAccount(Account); // Teller can freeze Accounts
            Account.DisplayBalance();
            Account.Withdraw(100);
        }
};

// Derived class for Manager
class Manager : public Employee {
    public:
        void PerformActions(BankAccount& Account) override {
            cout << endl << "Manager Actions:" << endl;
            Account.Deposit(500);
            Account.Withdraw(300);
            FreezeAccount(Account); // Manager can freeze Accounts
            UnfreezeAccount(Account); // Manager can unfreeze Accounts
            Account.AdjustLimit(500); // Manager can adjust Account limits for CHECKING ACCOUNT this function works as only that account has limit in it.
            Account.DisplayBalance();
        }
};

int main() {
    SavingsAccount Savings("SAV001", 1000, 1.5);     // Account Number, Current Amount, Interest Rate
    CheckingAccount Checking("CHK002", 500, 200);    // Account Number, Current Balance, Over Draft Limit
    BusinessAccount Business("BUS003", 2000, 10);    // Account Number, Current Balance, Tax Rate.

    cout << endl << "~--------------Saving Account--------------~" << endl << endl;
    Savings.Deposit(150);
	Savings.DisplayBalance();
	Savings.ApplyMonthlyInterest();
	cout << endl << "~--------------Saving Account--------------~" << endl << endl;

    cout << endl << "~--------------Checking Account--------------~" << endl << endl;
    Checking.Withdraw(200);
	Checking.DisplayBalance();
	Checking.Withdraw(400);     // ALert message will be displayed as now the user account is 0 and bank is giving them Over draft
    Checking.DisplayBalance();
    Checking.Withdraw(400);     // Withdraw WILL NOT BE ALLOWED as even Over draft limit has been exceeded.
	cout << endl << "~--------------Checking Account--------------~" << endl <<endl;

    cout << endl << "~--------------Business Account--------------~" << endl << endl;
	Business.DisplayBalance();
	Business.Deposit(400);     // Money is deposited now the tax will be deducted based upon the tax rate that is applicable on the account
    Business.DisplayBalance();
    Business.Withdraw(400);
    Business.DisplayBalance();
	cout << endl << "~--------------Business Account--------------~" << endl <<endl;

    // Create user roles
    Customer customer;
    Teller teller;
    Manager manager;

    // Perform actions for each role
    customer.PerformActions(Savings);
    teller.PerformActions(Business);
    manager.PerformActions(Checking);
    return 0;
}