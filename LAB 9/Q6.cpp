#include <iostream>
#include <string>

using namespace std;

// Abstract Base Class
class Person {
    protected:
        string Name;
        double Salary;
    public:
        virtual void GetData() {
            cout << "Enter Name: ";
            getline(cin, Name);
            cout << "Enter Salary: ";
            cin >> Salary;
            cin.ignore();
        }

        virtual void DisplayData() {
            cout << "Name: " << Name << endl;
            cout << "Salary: $" << Salary << endl;
        }

        virtual void CalculateBonus() = 0;
        virtual ~Person() {}
};

// Admin Class
class Admin : virtual public Person {
    protected:
        string DepartmentName;
    public:
        void GetData() override {
            Person::GetData(); // Call base class to get common data
            cout << "Enter Department Name: ";
            getline(cin, DepartmentName);
        }

        void DisplayData() override {
            Person::DisplayData(); // Show common data
            cout << "Department: " << DepartmentName << endl;
        }

        void CalculateBonus() override {
            double bonus = 0.15 * Salary;
            cout << "Admin Bonus: $" << bonus << endl;
        }
};

// Account Class
class Account : virtual public Person {
    protected:
        string AccountCode;

    public:
        void GetData() override {
            Person::GetData();
            cout << "Enter Account Code: ";
            getline(cin, AccountCode);
        }

        void DisplayData() override {
            Person::DisplayData();
            cout << "Account Code: " << AccountCode << endl;
        }

        void CalculateBonus() override {
            double bonus = 0.12 * Salary;
            cout << "Account Bonus: $" << bonus << endl;
        }
};

// Master Class with Multiple Inheritance
class Master : public Admin, public Account {
    private:
        string PositionTitle;
    public:
        void GetData() override {
            Person::GetData(); // Common fields
            cout << "Enter Department Name: ";
            getline(cin, DepartmentName);
            cout << "Enter Account Code: ";
            getline(cin, AccountCode);
            cout << "Enter Position Title: ";
            getline(cin, PositionTitle);
        }

        void DisplayData() override {
            Person::DisplayData();
            cout << "Department: " << DepartmentName << endl;
            cout << "Account Code: " << AccountCode << endl;
            cout << "Position Title: " << PositionTitle << endl;
        }

        void CalculateBonus() override {
            double bonus = 0.20 * Salary;
            cout << "Master Bonus: $" << bonus << endl;
        }
};

int main() {
    Person* Employee = nullptr;
    int Choice;

    cout << "Select Employee Type:\n";
    cout << "1. Admin\n2. Account\n3. Master\nChoice: ";
    cin >> Choice;
    cin.ignore();

    switch (Choice) {
        case 1:
            Employee = new Admin();
            break;
        case 2:
            Employee = new Account();
            break;
        case 3:
            Employee = new Master();
            break;
        default:
            cout << "Invalid choice.\n";
            return 1;
    }

    cout << "\n--- Enter Employee Data ---" << endl;
    Employee->GetData();

    cout << "\n--- Employee Details ---" << endl;
    Employee->DisplayData();

    cout << "\n--- Calculating Bonus ---" << endl;
    Employee->CalculateBonus();

    delete Employee;
    return 0;
}
