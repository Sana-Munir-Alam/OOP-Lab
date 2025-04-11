#include <iostream>
#include <string>

using namespace std;

// Wallet class: fully encapsulated
class Wallet {
private:
    double balance;
    double dailyDepositTotal;
    double dailyWithdrawTotal;
    static const double MAX_DAILY_DEPOSIT;
    static const double MAX_DAILY_WITHDRAW;

public:
    Wallet() {
        balance = 0.0;
        dailyDepositTotal = 0.0;
        dailyWithdrawTotal = 0.0;
    }

    bool deposit(double amount) {
        if (amount <= 0) {
            cout << "Deposit amount must be positive." << endl;
            return false;
        }
        if (dailyDepositTotal + amount > MAX_DAILY_DEPOSIT) {
            cout << "Deposit failed: exceeds daily deposit limit." << endl;
            return false;
        }
        balance += amount;
        dailyDepositTotal += amount;
        cout << "Deposited: $" << amount << " | New Balance: $" << balance << endl;
        return true;
    }

    bool withdraw(double amount) {
        if (amount <= 0) {
            cout << "Withdrawal amount must be positive." << endl;
            return false;
        }
        if (amount > balance) {
            cout << "Withdrawal failed: insufficient balance." << endl;
            return false;
        }
        if (dailyWithdrawTotal + amount > MAX_DAILY_WITHDRAW) {
            cout << "Withdrawal failed: exceeds daily withdrawal limit." << endl;
            return false;
        }
        balance -= amount;
        dailyWithdrawTotal += amount;
        cout << "Withdrawn: $" << amount << " | Remaining Balance: $" << balance << endl;
        return true;
    }

    double getBalance() const {
        return balance;
    }

    void resetDailyLimits() {
        dailyDepositTotal = 0.0;
        dailyWithdrawTotal = 0.0;
    }
};

// Define static constants
const double Wallet::MAX_DAILY_DEPOSIT = 1000.0;
const double Wallet::MAX_DAILY_WITHDRAW = 500.0;

// User class: interfaces with Wallet securely
class User {
  private:
      string userID;
      string name;
      Wallet wallet;
  public:
      User(string id, string username) {
          userID = id;
          name = username;
      }

      void deposit(double amount) {
          cout << "[" << name << "] Attempting to deposit $" << amount << endl;
          wallet.deposit(amount);
      }

      void withdraw(double amount) {
          cout << "[" << name << "] Attempting to withdraw $" << amount << endl;
          wallet.withdraw(amount);
      }

      void showBalance() const {
          cout << "[" << name << "] Current Balance: $" << wallet.getBalance() << endl;
      }

      void resetLimits() {
          wallet.resetDailyLimits();
      }
};

// Demonstration
int main() {
    User user1("U001", "Richard");
    User user2("U002", "Christopher");

    user1.deposit(300);
    user1.withdraw(100);
    user1.showBalance();

    user1.deposit(1800); 
    user1.withdraw(1450); 
    user1.resetLimits(); 
    user1.withdraw(1450);

    cout << endl;

    user2.deposit(2000);
    user2.withdraw(500);
    user2.showBalance();

    return 0;
}
