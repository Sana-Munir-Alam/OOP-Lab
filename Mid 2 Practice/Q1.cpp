#include <iostream>
#include <string>
using namespace std;

class CreditCard{
    private:
        int CardNumber;
        float Balance;
        float CreditLimit;
        string* TransactionHistory;
        int size;
    public:
        CreditCard(){   // Default Constructor
            CardNumber = 123456789;
            Balance = 0;
            CreditLimit = 500;
            size = 2;
            TransactionHistory = new string[size];
            cout << "Default Constructor Called" << endl;
        }

        CreditCard(int Num, float Bal, float Limit, int Size) : CardNumber(Num), Balance(Bal), CreditLimit(Limit), size(Size){// Paramatrized Constructor
            TransactionHistory = new string[size];
            cout << "Paramatrized Constructor Called"<< endl;

        }
        // Copy Constructor [shallow copy]
        // CreditCard(const CreditCard& other){
        //     CardNumber = other.CardNumber;
        //     Balance = other.Balance;
        //     CreditLimit = other.CreditLimit;

        //     // In shallow copy we are trying to copy the DMA stoed variable though it wil just copy the pointer rathe rthan the data.
        //     TransactionHistory = other.TransactionHistory;
        //     size = other.size;
        // }

        ~CreditCard(){
            cout << "Card object Destroyed for Card: " << CardNumber << endl;
            delete[] TransactionHistory;
        }
        // Deep Copy 
        CreditCard(const CreditCard& other){
            CardNumber = other.CardNumber;
            Balance = other.Balance;
            CreditLimit = other.CreditLimit;
            size = other.size;
            TransactionHistory = new string[size];
            for (int i = 0; i < size; i++){
                TransactionHistory[i] = other.TransactionHistory[i];
            }
            cout << "Deep Copy Constructor Called" << endl;

        }
        void setTransaction(int index, const string& data) {
            if (index >= 0 && index < size){
                TransactionHistory[index] = data;
            }
        }
        void printTransactions() const {
            cout << "Transactions for card [" << CardNumber << "]: ";
            for (int i = 0; i < size; ++i) {
                cout << TransactionHistory[i] << " ";
            }
            cout << endl;
        }
        
        
};

/*
Q4) In what real-life situation would you prefer to rely on the default constructor of CreditCard? And when would you use the parameterized one?

Default COnstructor to be used when we do not have the credit-card details yet, or we want to create a list/array of balnk credit card whose info will be filled later on. 

Paramatrized COnstructor will be used whe we already have all the data up front. You want to ensure the object is fully valid right after construction. You want to prevent invalid states like an empty card number.

*/

int main() {
    {
        CreditCard card1(43458587, 1200.0f, 5000.0f, 3);
        card1.setTransaction(0, "Amazon");
        card1.setTransaction(1, "Netflix");
        card1.setTransaction(2, "Spotify");

        cout << "Original card transactions:" << endl;
        card1.printTransactions();

        CreditCard card2 = card1;  // Deep copy here

        // Modify the original
        card1.setTransaction(1, "Apple");

        cout << "\nAfter modifying original card's second transaction:" << endl;
        cout << "Original card:" << endl;
        card1.printTransactions();

        cout << "Copied card (should be unchanged):" << endl;
        card2.printTransactions();
    }
    return 0;
}
