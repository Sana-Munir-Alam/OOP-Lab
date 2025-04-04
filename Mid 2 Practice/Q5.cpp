#include <iostream>
#include <string>
#include <vector>
using namespace std;

class MenuItem{
    public:
        virtual void CalculatePrepTime() const = 0;  // Pure virtual function
        virtual void Display() const = 0;
        /*
        Discuss how you would incorporate a virtual destructor in MenuItem and why it’s crucial when using pointers to base class objects.
        */
        virtual ~MenuItem(){
            cout << "MenuItem destroyed" << endl;
        }
        /*
        Q)Show an example of a memory leak that could occur if MenuItem did not have a virtual destructor, and how adding the virtual destructor fixes it.
        
        If you run this code without the virtual ~MenuItem() in the base class, the destructor for Dessert won’t be called, and the memory for the Dessert object won't be properly freed. 
        int main() {
            MenuItem* item = new Dessert();
            delete item;  // Without virtual destructor, this may cause a memory leak
            return 0;
        }
        Fix: Adding the virtual destructor in the MenuItem class ensures the correct destructor chain is called.
        */
};
// Derived class MainCourse
class MainCourse : public MenuItem {
    public:
        void CalculatePrepTime() const override {
            cout << "Main Course preparation time: 30 minutes" << endl;
        }
    
        void Display() const override {
            cout << "Main Course: Steak with potatoes" << endl;
        }
    
        ~MainCourse() {
            cout << "MainCourse destroyed" << endl;
        }
};
    
// Derived class Beverage
class Beverage : public MenuItem {
    public:
        void CalculatePrepTime() const override {
            cout << "Beverage preparation time: 5 minutes" << endl;
        }
    
        void Display() const override {
            cout << "Beverage: Coffee" << endl;
        }
    
        ~Beverage() {
            cout << "Beverage destroyed" << endl;
        }
};
    
// Derived class Dessert
class Dessert : public MenuItem {
    public:
        void CalculatePrepTime() const override {
            cout << "Dessert preparation time: 15 minutes" << endl;
        }

        void Display() const override {
            cout << "Dessert: Ice Cream" << endl;
        }

        ~Dessert() {
            cout << "Dessert destroyed" << endl;
        }
};

/*
Q) Suppose the restaurant needs a special item that is both a beverage and a dessert (e.g., a “milkshake dessert”). Would multiple inheritance make sense here, or would a different design (composition or multi-level inheritance) be more appropriate? Explain.

I would say we use composition as multiple inheritance can lead to diamond problem which can create issues/complexities in the code. with composition we dont have to worry about inheritance conflict
When multiple inheritance is used, the order in which constructors and destructors are called becomes crucial. The derived class needs to ensure that the constructors for all its base classes are called correctly, and similarly, destructors must be invoked in the reverse order of inheritance. Failure to manage this properly can lead to memory leaks, resource mismanagement, and other issues.
*/
class MilkshakeDessert {
    private:
        Beverage beverage;
        Dessert dessert;
    public:
        void calculatePrepTime() {
            beverage.CalculatePrepTime();  // Add beverage prep time
            dessert.CalculatePrepTime();   // Add dessert prep time
        }
    
        void display() {
            beverage.Display();
            dessert.Display();
        }
};

// Main function demonstrating polymorphism and memory leak issue
int main() {
    // Creating MenuItem pointers in a vector
    vector<MenuItem*> menuItems;

    // Adding different items to the vector
    menuItems.push_back(new MainCourse());
    menuItems.push_back(new Beverage());
    menuItems.push_back(new Dessert());

    // Polymorphism: Calling calculatePrepTime and display
    for (auto item : menuItems) {
        item->CalculatePrepTime();
        item->Display();
    }
    cout << endl <<"---Destructors---" << endl;
    // Example of a potential memory leak without a virtual destructor
    // Delete MenuItem objects
    for (auto item : menuItems) {
        delete item;  // Virtual destructor ensures proper cleanup
    }
    cout << endl << "---MilkshakeDessert---" << endl;
    // Creating MilkshakeDessert object (composition)
    MilkshakeDessert milkshakeDessert;
    milkshakeDessert.calculatePrepTime();
    milkshakeDessert.display();

    return 0;
}
