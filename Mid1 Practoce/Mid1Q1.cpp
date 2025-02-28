#include <iostream>
using namespace std;

class Account{
	private:
		int AccountNumber;
		string AccountHolderName;
		string AccountType;
		double Balance;
	public:
		Account() {
			// Default Constructor
			 AccountNumber = 0; 
			 AccountHolderName = " "; 
			 Balance = 0.0; 
			 AccountType = " ";
		}
		Account(int Num, string Name, double balance, string Type) : AccountNumber(Num), AccountHolderName(Name), Balance(balance), AccountType(Type){
			// Paramatrized Constructor
		}
		Account(const Account& other){ // Copy Constructor
			AccountNumber = other.AccountNumber;
			AccountHolderName = other.AccountHolderName;
			Balance = other.Balance;
			AccountType = other.AccountType;
		}
		void DepositMoney(double Money){
			Balance += Money;
			cout << "$" << Money << " deposited successfully" << endl;
		}
		void WithdrawMoney(double Money){
			if (Money <= Balance){
				Balance -= Money;
				cout << "$" << Money << " withdrawn successfully" << endl;
			}else{
				cout << "Insufficnet Balance" << endl;
			}
		}
		void CheckBalance(){
			cout << "Your Current Balance: $" << Balance << endl;
		}
		void MiniStatement(){
			cout << "Account Number: " << AccountNumber << endl;
			cout << "Account Holder Name: " << AccountHolderName << endl;
			cout << "Balance: $" << Balance << endl;
			cout << "Account Type: " << AccountType << endl;
		}
};

int main(){
	Account a1(123456, "Sana", 2345.00, "Saving");
	cout << "===== Original Account =====" << endl;
	a1.CheckBalance();
	a1.DepositMoney(55);
	a1.CheckBalance();
	a1.WithdrawMoney(20);
	a1.MiniStatement();
	cout << endl << "===== Copied Account =====" << endl;
	Account a2(a1);
	a2.CheckBalance();
	a2.DepositMoney(55);
	a1.CheckBalance();
	a2.WithdrawMoney(20);
	a2.MiniStatement();
	

}
