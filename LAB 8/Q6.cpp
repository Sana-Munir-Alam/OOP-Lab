#include <iostream>
#include <string>
using namespace std;

// Base Class
class Person {
    protected:
        int EmpID;  // Employee ID
    public:
        void getData() {
            cout << "Enter Employee ID: ";
            cin >> EmpID;
        }
        void DisplayData() {
            cout << "Employee ID: " << EmpID << endl;
        }
};

// Derived Class: Admin
class Admin : public Person {
    private:
        string Name;
        double MonthlyIncome;
    public:
        void getData() {
            Person::getData();  // Call base class function
            cin.ignore();
            cout << "Enter Name: ";
            getline(cin, Name);
            cout << "Enter Monthly Income: ";
            cin >> MonthlyIncome;
        }

        // Function to calculate and return the annual bonus
        double bonus() {
            return (MonthlyIncome * 12) * 0.05;  // 5% of annual salary
        }

        // Function to display admin details
        void DisplayData() {
            Person::DisplayData();
            cout << "Name: " << Name << endl;
            cout << "Monthly Income: $" << MonthlyIncome << endl;
            cout << "Annual Bonus: $" << bonus() << endl;
        }
};

// Derived Class: Accounts
class Accounts : public Person {
    private:
        string Name;
        double MonthlyIncome;
    public:
        // Function to get account details
        void getData() {
            Person::getData();
            cin.ignore();
            cout << "Enter Name: ";
            getline(cin, Name);
            cout << "Enter Monthly Income: ";
            cin >> MonthlyIncome;
        }
        // Function to calculate and return the annual bonus
        double bonus() {
            return (MonthlyIncome * 12) * 0.05;  // 5% of annual salary
        }
        // Function to display account details
        void DisplayData() {
            Person::DisplayData();
            cout << "Name: " << Name << endl;
            cout << "Monthly Income: $" << MonthlyIncome << endl;
            cout << "Annual Bonus: $" << bonus() << endl;
        }
};

// Main function
int main() {
    Admin adminEmp;
    Accounts accEmp;

    cout << endl << "Enter details for Admin Employee:" << endl;
    adminEmp.getData();

    cout << endl << "Enter details for Accounts Employee:" << endl;
    accEmp.getData();

    cout << endl << "Displaying Employee Details:\n" << endl;

    cout << "Admin Employee:" << endl;
    adminEmp.DisplayData();
    
    cout << endl << "Accounts Employee:" << endl;
    accEmp.DisplayData();

    return 0;
}
