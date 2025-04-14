#include <iostream>
#include <string>

using namespace std;

// Wallet class
class Wallet {
    private:
        double Balance;
        double DailyDepositTotal;
        double DailyWithdrawTotal;
        static const double MAX_DAILY_Deposit;
        static const double MAX_DAILY_Withdraw;
    public:
        Wallet() {
            Balance = 0.0;
            DailyDepositTotal = 0.0;
            DailyWithdrawTotal = 0.0;
        }
        bool Deposit(double amount) {
            if (amount <= 0) {
                cout << "Deposit amount must be positive." << endl;
                return false;
            }
            if (DailyDepositTotal + amount > MAX_DAILY_Deposit) {
                cout << "Deposit failed: exceeds daily Deposit limit." << endl;
                return false;
            }
            Balance += amount;
            DailyDepositTotal += amount;
            cout << "Deposited: $" << amount << " | New Balance: $" << Balance << endl;
            return true;
        }
        bool Withdraw(double amount) {
            if (amount <= 0) {
                cout << "Withdrawal amount must be positive." << endl;
                return false;
            }
            if (amount > Balance) {
                cout << "Withdrawal failed: insufficient Balance." << endl;
                return false;
            }
            if (DailyWithdrawTotal + amount > MAX_DAILY_Withdraw) {
                cout << "Withdrawal failed: exceeds daily Withdrawal limit." << endl;
                return false;
            }
            Balance -= amount;
            DailyWithdrawTotal += amount;
            cout << "Withdrawn: $" << amount << " | Remaining Balance: $" << Balance << endl;
            return true;
        }

        double getBalance() const {
            return Balance;
        }

        void ResetDailyLimits() {
            DailyDepositTotal = 0.0;
            DailyWithdrawTotal = 0.0;
        }
};

// Defining static constants
const double Wallet::MAX_DAILY_Deposit = 1000.0;
const double Wallet::MAX_DAILY_Withdraw = 500.0;

// User class:
class User {
  private:
      string userID;
      string Name;
      Wallet wallet; // Composition
  public:
      User(string id, string userName) {
          userID = id;
          Name = userName;
      }
      void Deposit(double amount) {
          cout << "[" << Name << "] Attempting to Deposit $" << amount << endl;
          wallet.Deposit(amount);
      }
      void Withdraw(double amount) {
          cout << "[" << Name << "] Attempting to Withdraw $" << amount << endl;
          wallet.Withdraw(amount);
      }
      void ShowBalance() const {
          cout << "[" << Name << "] Current Balance: $" << wallet.getBalance() << endl;
      }
      void ResetLimits() {
          wallet.ResetDailyLimits();
      }
};

int main() {
    User user1("U001", "Richard");
    User user2("U002", "Christopher");

    cout << "\n========== Transactions for Richard ==========\n";
    user1.Deposit(300);
    user1.Withdraw(100);
    user1.ShowBalance();

    cout << "\n--- Exceeding Limits Test ---\n";
    user1.Deposit(1800); 
    user1.Withdraw(1450); 
    user1.ResetLimits(); 
    user1.Withdraw(1450);

    cout << "\n========== Transactions for Christopher ==========\n";
    cout << endl;

    user2.Deposit(2000);
    user2.Withdraw(500);
    user2.ShowBalance();
    cout << "\n==============================================\n";
    return 0;
}
