#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 4){
        cout << "Insufficent Data Entered!!";
        return 1;
    }

    int CustomerID = stoi(argv[1]);
    string CustomerName = argv[2];
    int UnitsConsumed = stoi(argv[3]);
    double ChargePerUnit = 0.0, NetAmount = 0.0, BillAmount = 0.0,Surcharge = 0.0;

    if (UnitsConsumed <= 199){
        ChargePerUnit = 16.2;
    }else if (UnitsConsumed >= 200 && UnitsConsumed < 300){
        ChargePerUnit = 20.1;
    }else if (UnitsConsumed >= 300 && UnitsConsumed < 500){
        ChargePerUnit = 27.1;
    }else{
        ChargePerUnit = 35.9;
    }
    BillAmount = UnitsConsumed * ChargePerUnit;
    
    if (BillAmount > 18000){
        Surcharge = BillAmount * 0.15;
        NetAmount = BillAmount + Surcharge;
    }else{
         NetAmount = BillAmount;
    }

    cout << "Customer ID : " << CustomerID << endl;
    cout << "Customer Name: " << CustomerName << endl;
    cout << "Units Consumed : " << UnitsConsumed << endl;
    cout << "Amount Charges @Rs. " << ChargePerUnit << " per unit: " << BillAmount << endl;
    cout << "Surcharge Amount: " << Surcharge << endl;
    printf("Net Amount Paid by the Customer: %.2f", NetAmount);
    return 0;
}
