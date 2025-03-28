#include <iostream>
#include <cmath>
using namespace std;

// Base Class
class BankAccount{
	protected:
		int AccountNumbers;
		double Balance;
		string AccountHolderName;
		string AccountType;
	public:
		BankAccount(int AccNum, double Bal, string Name, string Type): AccountNumbers(AccNum), Balance(Bal), AccountHolderName(Name), AccountType(Type){
			// Paramatrized Constructor
		}
		
		// Deposit Money
        void Deposit(double Amount) {
            Balance += Amount;
            cout << "Deposited $" << Amount << " into Account " << AccountNumbers << endl;
        }
		// Withdraw Money
        virtual void Withdraw(double Amount) {
            if (Amount <= Balance) {
                Balance -= Amount;
                cout << "Withdrawn $" << Amount << " from Account " << AccountNumbers << endl;
            } else {
                cout << "Insufficient funds in Account " << AccountNumbers << endl;
            }
        }
        // Calculate Interest
		virtual void CalculateInterest(double rate){
			cout << "Calculating Interest" << endl;
		}
		// Print Statement NEED TO FIND LOGIC
		virtual void PrintStatement(){
			cout << "Printing Mini Statement" << endl;
		}
		// Get Account Info
        void getAccountInfo() const {
        	cout << "~----------Account Info----------~" << endl;
            cout << "Account Holder Name: " << AccountHolderName <<endl;
			cout << "Account Number: " << AccountNumbers << endl;
			cout << "Account Type: " << AccountType << endl;
        }
};

// Derived class for SavingsAccount
class SavingsAccount : public BankAccount {
    private:
        double InterestRate;
        double MinimumBalance;
    public:
        SavingsAccount(int AccNum, double Bal, string Name, string Type, double Rate, double Min) : BankAccount(AccNum, Bal, Name, Type), InterestRate(Rate), MinimumBalance(Min) {
            // Paramatrized Constructor which also calls the Parent class constructor
        }
        void CalculateInterest() override { // This is a monthly interest code calculation
            double Interest = Balance * InterestRate / 100;
            Balance += Interest;
            cout << "Applied monthly Interest of $" << Interest << " to Account " << AccountNumber << endl;
            cout << "Your Balance after Monthly interest is : $" << Balance << endl;
    	}
        void Withdraw(double Amount) override{
        	if ((Balance - Amount) >= MinBalance && Amount <= Balance) {
                Balance -= Amount;
                cout << "Withdrawn $" << Amount << " from Account " << AccountNumbers << endl;
            } else if(Amount >= Balance) {
                cout << "Insufficient funds in Account" << AccountNumbers << endl;
            } else if((Balance - Amount) <= MinBalance) {
                cout << "You have reached your Minimum Blance Limit, You can't withdraw further money.'" << AccountNumbers << endl;
		}
};

// Derived class for CheckingAccount
class CheckingAccount : public BankAccount {
    private:
        double OverdraftLimit;
        bool OverdraftAlert;
    public:
        CheckingAccount(int AccNum, double Bal, string Name, string Type, double Limit) : BankAccount(AccNum, Bal, Name, Type), OverdraftLimit(Limit), OverdraftAlert(false) {
            // Paramatrized Constructor which also calls the Parent class constructor
        }
        // I am going along with an fixed amount of over draft system the bank uses like they can go max upto $[Money] when their actual balance is 0.
        void Withdraw(double Amount) override {
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

// Derived class for FixedDepositAccount
class FixedDepositAccount{
	private:
		int MaturityDate;
		double FixedInterestRate;
	public:
		FixedDepositAccount(int AccNum, double Bal, string Name, string Type, double Rate, int Date) : BankAccount(AccNum, Bal, Name, Type), FixedInterestRate(Rate), MaturityDate(Date){
			// Paramatrized Constructor which also calls the Parent class constructor
		}
		void CalculateInterest() override { // This is a monthly interest code calculation
			// Formula for compound interest: A = P * (1 + r/n)^(n*t)
		    // where:
	    	// P = principal amount
		    // r = annual interest rate (in decimal form)
	    	// n = number of times interest is compounded per year (for annually, n = 1)
	    	// t = time the money is invested for (in years)
            double Amount = Balance * pow(1+FixedInterestRate, MaturityDate);
            double Interest = Amount - Balance;  // Interest earned is total amount - principal
            Balance += Interest; // Total Money now after interest
            cout << "Applied Compound Interest of $" << Interest << " to Account " << AccountNumber << " for time of "<< MaturityDate << " days." <<endl;
            cout << "Your Balance after Fixed Interest is : $" << Balance << endl;
    	}
		void Withdraw() override{
		
		}	
};
