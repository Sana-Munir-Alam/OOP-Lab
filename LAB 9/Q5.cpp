#include <iostream>
#include <string>

using namespace std;

// Abstract Class
class Car {
    protected:
        string Model;
        double Price;
    public:
        // Getters
        string GetModel() const { return Model; }
        double GetPrice() const { return Price; }

        // Setters
        void SetModel(string m) { Model = m; }
        virtual void SetPrice(double p) = 0;     // Abstract Method

        // Pure Virtual Display Function (for polymorphism)
        virtual void DisplayInfo() = 0;

        virtual ~Car() {}
};

// Derived Class 1: ColoredCar
class ColoredCar : public Car {
    private:
        string color;
    public:
        void setColor(string c) { color = c; }
        string getColor() const { return color; }

        void SetPrice(double p) override {
            if (p < 0) {
                cout << "Price cannot be negative. Setting to 0." << endl;
                Price = 0;
            } else {
                Price = p;
            }
        }

        void DisplayInfo() override {
            cout << "Car Model: " << Model << endl;
            cout << "Color: " << color << endl;
            cout << "Price: $" << Price << endl;
            cout << "--------------------------" << endl;
        }
};

// Derived Class 2: CompanyCar
class CompanyCar : public Car {
    private:
        string companyName;
    public:
        void setCompanyName(string name) { companyName = name; }
        string getCompanyName() const { return companyName; }

        void SetPrice(double p) override {
            if (p < 1000) {
                cout << "Minimum Price for company cars is $1000. Setting to $1000." << endl;
                Price = 1000;
            } else {
                Price = p;
            }
        }

        void DisplayInfo() override {
            cout << "Car Model: " << Model << endl;
            cout << "Company: " << companyName << endl;
            cout << "Price: $" << Price << endl;
            cout << "--------------------------" << endl;
        }
};

int main() {
    ColoredCar coloredCar;
    CompanyCar brandedCar;

    coloredCar.SetModel("Model X");
    coloredCar.setColor("Midnight Blue");
    coloredCar.SetPrice(27000);

    brandedCar.SetModel("Model Y");
    brandedCar.setCompanyName("BMW");
    brandedCar.SetPrice(721878);

    Car* car1 = &coloredCar;
    Car* car2 = &brandedCar;

    car1->DisplayInfo();
    car2->DisplayInfo();

    return 0;
}
