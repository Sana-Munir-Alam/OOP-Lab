#include <iostream>
using namespace std;

//Base Class
class BankAccount{
	protected:
		double Balance;
	public:
		int AccountNumber;
		BankAccount(){
			// Default Constructor
			AccountNumber = 0;
			Balance = 0.0;
		}
		BankAccount (int Num, double Money) : AccountNumber(Num) , Balance(Money){
			// Paramatrized Constructor
			cout << "Parent Constructor Called" << endl;
		}
		void DepositMoney(double Money){
			Balance += Money;
			cout << "$" << Money << " deposited successfully" << endl;
		}
		int WithdrawMoney(double Money){
			if (Money <= Balance){
				Balance -= Money;
				cout << "$" << Money << " withdrawn successfully" << endl;
				return 0;
			}else{
				return 1;
			}
		}
		void CheckBalance(){
			cout << "Your Current Balance: $" << Balance << endl;
		}
		
};
// Derived Class
class SavingsAccount : public BankAccount{
	public:
		SavingsAccount(int Num, double Money) : BankAccount (Num, Money) {
			// Child Constructor Calling Base Constructor
			cout << "Child Constructor Called" << endl;
		}
		void MonthlyInterest(double Rate){
			Balance = Balance + (Balance * Rate/100);
			cout << "Your Balance after Monthly interest of " << Rate << "% is : $" << Balance << endl;
		}	
};

// Derived Class
class CheckingAccount : public BankAccount{
	public:
		CheckingAccount(int Num, double Money) : BankAccount (Num, Money) {
			// Child Constructor Calling Base Constructor
			cout << "Child Constructor Called" << endl;
		}
		void WithdrawMoney(double Money){
			if(BankAccount::WithdrawMoney(Money)){
				cout << "Alert Logged" <<endl;
				cout << "$" << Money << " withdrawn successfully!" << endl;
				Balance = Balance - Money;
			}
		}
};

int main(){
	cout << "~--------------Saving Account--------------~" << endl;
	SavingsAccount Info(12345, 2500);
	Info.DepositMoney(10);
	Info.WithdrawMoney(140);
	Info.CheckBalance();
	Info.MonthlyInterest(1.5);
	cout << "~--------------Saving Account--------------~" << endl <<endl;
	
	cout << "~--------------Checking Account--------------~" << endl;
	CheckingAccount Info1(12345, 1500);
	Info1.WithdrawMoney(1400);
	Info1.DepositMoney(1500);
	Info1.WithdrawMoney(2400);
	Info1.CheckBalance();
	cout << "~--------------Checking Account--------------~" << endl <<endl;

	
	return 0;
}
