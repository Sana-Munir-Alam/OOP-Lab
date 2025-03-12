#include <iostream>
#include <string>
using namespace std;

// Base class for Employee
class Employee {
    protected:
        int EmployeeID;
        string EmployeeName;

    public:
        Employee(int ID, const string& Name) : EmployeeID(ID), EmployeeName(Name) {
            // Paramatrized Constructor
        }

        virtual ~Employee() {}

        virtual void DisplayInfo() const {
            cout << "Employee ID: " << EmployeeID << endl << "Employee Name: " << EmployeeName << endl;
        }
};

// Abstract interface for taking Orders
class IOrderTaker {
    public:
        virtual ~IOrderTaker() {}
        virtual void TakeOrder(const string& Order) = 0; // Pure virtual function
};

// Abstract interface for preparing Orders
class IOrderPreparer {
    public:
        virtual ~IOrderPreparer() {}
        virtual void PrepareOrder(const string& Order) = 0; // Pure virtual function
};

// Abstract interface for generating bills
class IBiller {
    public:
        virtual ~IBiller() {}
        virtual void GenerateBill(double amount) = 0; // Pure virtual function
};

// Waiter class (implements IOrderTaker)
class Waiter : public Employee, public IOrderTaker {
    public:
        Waiter(int ID, const string& Name) : Employee(ID, Name) {
            // Paramatrized Constructor that also calls Parent Constructor
        }
        void TakeOrder(const string& Order) override {
            cout << "Waiter " << EmployeeName << " is taking Order: " << Order << endl;
        }
};

// Chef class (implements IOrderPreparer)
class Chef : public Employee, public IOrderPreparer {
    public:
        Chef(int ID, const string& Name) : Employee(ID, Name) {
            // Paramatrized Constrcutor that also calls Parent Constructor
        }
        void PrepareOrder(const string& Order) override {
            cout << "Chef " << EmployeeName << " is preparing Order: " << Order << endl;
        }
};

// Cashier class (implements IBiller)
class Cashier : public Employee, public IBiller {
    public:
        Cashier(int ID, const string& Name) : Employee(ID, Name) {
            // Paramatrized Constrcutor that also calls Parent Constructor
        }
        void GenerateBill(double amount) override {
            cout << "Cashier " << EmployeeName << " is generating a bill for $" << amount << endl;
        }
};

// Manager class (implements both IOrderTaker and IBiller)
class Manager : public Employee, public IOrderTaker, public IBiller {
    public:
        Manager(int ID, const string& Name) : Employee(ID, Name) {
            // Paramatrized Constrcutor that also calls Parent Constructor
        }

        void TakeOrder(const string& Order) override {
            cout << "Manager " << EmployeeName << " is taking Order: " << Order << endl;
        }
        void GenerateBill(double amount) override {
            cout << "Manager " << EmployeeName << " is generating a bill for $" << amount << endl;
        }
};

// Base class for Menu
class Menu {
    protected:
        string MenuName;
    public:
        Menu(const string& Name) : MenuName(Name) {
            // Paramatrized Constructor
        }
        virtual ~Menu() {}

        virtual double CalculateTotalCost(const string* Items, int ItemCount) const = 0; // Pure virtual function
};

// FoodMenu class (inherits from Menu)
class FoodMenu : public Menu {
    public:
        FoodMenu(const string& Name) : Menu(Name) {
            // Paramatrized Constructor that also calls Parent Constructor
        }
        double CalculateTotalCost(const string* Items, int ItemCount) const override {
            double TotalCost = ItemCount * 10.0; // $10 per item
            cout << "Calculating total cost for food Items: $" << TotalCost << endl;
            return TotalCost;
        }
};

// BeverageMenu class (inherits from Menu)
class BeverageMenu : public Menu {
    public:
        BeverageMenu(const string& Name) : Menu(Name) {
            // Paramatrized Constrcutor that also calls Parent Constructor
        }
        double CalculateTotalCost(const string* Items, int ItemCount) const override {
            double TotalCost = ItemCount * 5.0; // $5 per item
            double tax = TotalCost * 0.10; // 10% tax
            TotalCost += tax;
            cout << "Calculating total cost for beverage Items (including 10% tax): $" << TotalCost << endl;
            return TotalCost;
        }
};

int main() {
    // Create Employees
    Waiter waiter(1, "John");
    Chef chef(2, "Alice");
    Cashier cashier(3, "Bob");
    Manager manager(4, "Eve");

    // Create Menus
    FoodMenu foodMenu("Lunch Menu");
    BeverageMenu beverageMenu("Drinks Menu");

    // Scenario 1: Regular workflow (Waiter -> Chef -> Cashier)
    cout << endl << "===== Regular Order Processing =====" << endl << endl;
    string* FoodOrder = new string[2]{"Burger", "Fries"};

    waiter.TakeOrder("Burger & Fries");
    chef.PrepareOrder("Burger & Fries");
    double FoodCost = foodMenu.CalculateTotalCost(FoodOrder, 2);
    cashier.GenerateBill(FoodCost);

    delete[] FoodOrder; // Clean up dynamic memory
    
    cout << endl <<"===== Manager Special Order =====" << endl << endl;
    // Scenario 2: Manager handles complex order (Food + Beverages)
    string* ManagerFoodOrder = new string[1]{"Pizza"};
    string* ManagerBeverageOrder = new string[2]{"Wine", "Water"};
    
    manager.TakeOrder("Pizza with Wine & Water");
    chef.PrepareOrder("Pizza with Wine & Water");
    
    // Calculate Costs
    double ManagerFoodCost = foodMenu.CalculateTotalCost(ManagerFoodOrder, 1);
    double ManagerBeverageCost = beverageMenu.CalculateTotalCost(ManagerBeverageOrder, 2);
    double TotalCost = ManagerFoodCost + ManagerBeverageCost;
    
    // Manager generates combined bill
    manager.GenerateBill(TotalCost);
    
    // Clean up dynamic memory
    delete[] ManagerFoodOrder;
    delete[] ManagerBeverageOrder;
    return 0;
}
