#include <iostream>
#include <stdexcept>
using namespace std;

class Account {
	private:
		double Balance;
	public:
		//Default Constructor
		Account(){
			Balance = 0;
		}
		// Paramatrized Constructor
		Account(double InitialBalance = 0.0) {
			if (InitialBalance < 0.0) {
				throw invalid_argument("Error: Initial balance cannot be negative.");
			}
			Balance = InitialBalance;
		}
		// Add an Amount to the Current Balance
		void Credit(double Amount) {
			if (Amount < 0.0) {
				throw invalid_argument("Error: Credit Amount cannot be negative.");
			}
			Balance = Balance + Amount;
		}
		// Withdraw Money from the Account
		void Debit(double Amount) {
			if (Amount < 0.0) {
				throw invalid_argument("Error: Debit Amount cannot be negative.");
			}
			if (Amount > Balance) {
				throw invalid_argument("Error: Debit Amount exceeds the account balance.");
			}
			Balance = Balance - Amount;
		}
		// Return the Current Balance
		double GetBalance() const {
			return Balance;
		}
};

int main() {
    try {
        Account account(1000.0);
        cout << "Initial Balance: $" << account.GetBalance() << endl;

        account.Credit(500.0);
        cout << "After crediting $500, Balance: $" << account.GetBalance() << endl;

        account.Debit(200.0);
        cout << "After debiting $200, Balance: $" << account.GetBalance() << endl;

        // Attempt To Debit An Amount Greater Than The Balance To Get An Error Message
        account.Debit(2000.0);
    } catch (const invalid_argument& e) {
        cerr << e.what() << endl;
    }
    return 0;
}
