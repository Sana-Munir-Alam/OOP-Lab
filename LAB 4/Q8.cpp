#include <iostream>
#include <string>
using namespace std;

struct MenuItem {
    string Item;
    string Type;
    double Price;
};

class CoffeeShop {
private:
    string Name;
    MenuItem* Menu;
    int MenuSize;
    string* Orders;
    int OrdersSize;

public:
    // Parmatrized Constructor
    CoffeeShop(const string& ShopName, const MenuItem* menuItems, int menuSize) 
        : Name(ShopName), MenuSize(menuSize), Orders(nullptr), OrdersSize(0) {
        Menu = new MenuItem[MenuSize];
        for (int i = 0; i < MenuSize; ++i) {
            Menu[i] = menuItems[i];
        }
    }

    // Destructor
    ~CoffeeShop() {
        delete[] Menu;
        delete[] Orders;
    }

    // AddOrder Method
    string AddOrder(const string& ItemName) {
        bool exists = false;
        for (int i = 0; i < MenuSize; ++i) {
            if (Menu[i].Item == ItemName) {
                exists = true;
                break;
            }
        }
        if (!exists) {
            return "This item '" + ItemName + "' is currently unavailable";
        }
        // Resize Orders array
        string* NewOrders = new string[OrdersSize + 1];
        for (int i = 0; i < OrdersSize; ++i) {
            NewOrders[i] = Orders[i];
        }
        NewOrders[OrdersSize] = ItemName;
        
        delete[] Orders;
        Orders = NewOrders;
        OrdersSize++;
        return "";
    }

    // FulfillOrder Method
    string FulfillOrder() {
        if (OrdersSize == 0) {
            return "All orders have been fulfilled";
        }
        string ReadyItem = Orders[0];
        
        // Removing Elements as Orders are getting fullfilled
        if (OrdersSize == 1) { // Only One item remains in the Order List
            delete[] Orders;
            Orders = nullptr;
            OrdersSize = 0;
        } else {	// Multiple Items in the Order List
            string* NewOrders = new string[OrdersSize - 1];
            for (int i = 1; i < OrdersSize; ++i) {
                NewOrders[i-1] = Orders[i];
            }
            delete[] Orders;
            Orders = NewOrders;
            OrdersSize--;
        }
        return "The " + ReadyItem + " is ready";
    }

    // ListOrders Method
    string* ListOrders(int& Size) const {
        Size = OrdersSize;
        if (Size == 0){
			return nullptr;
		}
        string* OrderList = new string[Size];
        for (int i = 0; i < Size; ++i) {
            OrderList[i] = Orders[i];
        }
        return OrderList;
    }

    // DueAmount Method
    double DueAmount() const {
        double Total = 0.0;
        for (int i = 0; i < OrdersSize; ++i) {
            for (int j = 0; j < MenuSize; ++j) {
                if (Orders[i] == Menu[j].Item) {
                    Total += Menu[j].Price;
                    break;
                }
            }
        }
        return Total;
    }

    // CheapestItem Method
    string CheapestItem() const {
        if (MenuSize == 0){
			return "";
		}
        string Cheapest = Menu[0].Item;
        double MinPrice = Menu[0].Price;
        
        for (int i = 1; i < MenuSize; ++i) {
            if (Menu[i].Price < MinPrice) {
                MinPrice = Menu[i].Price;
                Cheapest = Menu[i].Item;
            }
        }
        return Cheapest;
    }

    // DrinksOnly Method
    string* DrinksOnly(int& Count) const {
        Count = 0;
        for (int i = 0; i < MenuSize; ++i) {
            if (Menu[i].Type == "drink"){
				Count++;
			}
		}
        if (Count == 0){
			return nullptr;
		}	
        
        string* Drinks = new string[Count];
        int Index = 0;
        for (int i = 0; i < MenuSize; ++i) {
            if (Menu[i].Type == "drink") {
                Drinks[Index++] = Menu[i].Item;
            }
        }
        return Drinks;
    }

    // FoodOnly Method
    string* FoodOnly(int& Count) const {
        Count = 0;
        for (int i = 0; i < MenuSize; ++i) {
            if (Menu[i].Type == "food"){
				Count++;
			}
        }
        if (Count == 0) {
			return nullptr;
		}
        string* Foods = new string[Count];
        int Index = 0;
        for (int i = 0; i < MenuSize; ++i) {
            if (Menu[i].Type == "food") {
                Foods[Index++] = Menu[i].Item;
            }
        }
        return Foods;
    }
};

int main() {
    // Create menu items
    MenuItem Items[] = {
		{"Iced Cofee", "drink", 8.0},
        {"Cappuccino", "drink", 5.0},
        {"Latte", "drink", 4.5},
        {"Sandwich", "food", 8.0},
        {"Croissant", "food", 3.5},
		{"Pasteries", "food", 5.5},
    };

    CoffeeShop Shop("Novel & Nibble", Items, 6);
	cout << "~-------------------------~" <<endl;
	cout << "Welcome to Novel & Nibble. Enjoy a warm cup of Coffee while reading your favourite Novel" << endl;
	cout << "~-------------------------~" <<endl;
	cout << "Displaying Novel & Nibble Menu Type Wise" << endl << endl; 
    
	// Test DrinksOnly
    int DrinkCount;
    string* Drinks = Shop.DrinksOnly(DrinkCount);
    cout << "Drinks (" << DrinkCount << "):" << endl;
    for (int i = 0; i < DrinkCount; ++i) {
        cout << " - " << Drinks[i] << endl;
    }
    delete[] Drinks;

    // Test FoodOnly
    int FoodCount;
    string* Foods = Shop.FoodOnly(FoodCount);
    cout << endl << "Foods (" << FoodCount << "):" << endl;
    for (int i = 0; i < FoodCount; ++i) {
        cout << " - " << Foods[i] << endl;
    }
    delete[] Foods;

	cout << "-------------------------" <<endl;
	cout << "Presenting You the Cheapest Item In Our Menu!" << endl;
    cout << "Cheapest Item: " << Shop.CheapestItem() << endl;
	cout << "-------------------------" <<endl;
    
	// Testing AddOrder to the Order List Based On Current Menu
	cout << "-------------------------" <<endl;
	cout << "Taking Your Order";
    cout << Shop.AddOrder("Latte") << endl;
    cout << Shop.AddOrder("Croissant") << endl;
    cout << Shop.AddOrder("Tea") << endl;

    // ListOrders
	cout << "-------------------------" <<endl;
	cout << "Displaying Your Order" << endl << endl;
    int OrderCount;
    string* Orders = Shop.ListOrders(OrderCount);
    cout << "Current Orders (" << OrderCount << "):" << endl;
    for (int i = 0; i < OrderCount; ++i) {
        cout << " - " << Orders[i] << endl;
    }
    delete[] Orders;

	cout << "-------------------------" <<endl;
	cout << "Total Due: $" << Shop.DueAmount() << endl;
	cout << "-------------------------" <<endl;
	cout << "Order Status:" << endl;
    cout << " - " << Shop.FulfillOrder() << endl;	// Latte ready
    cout << " - " << Shop.FulfillOrder() << endl;	// Croissant ready
    cout << " - " << Shop.FulfillOrder() << endl;	// All orders fulfilled

    return 0;
}
