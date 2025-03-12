#include <iostream>
#include <string>
using namespace std;

//Base Class
class Vehicles{
    protected:
        double VehiclePrice;
    public:
        Vehicles(double Price) : VehiclePrice(Price){
            // Paramatrized Constrcutor
        }
        virtual void Display() const {
            cout << "Price: $" << VehiclePrice << endl;
        }
};

// Derived Class 1
class Car : public Vehicles{
    protected:
        int SeatingCapacity;
        int NumberOfDoors;
        string FuelType;
    public:
        Car(double Price, int Seat, int Door, string Type) : Vehicles(Price), SeatingCapacity(Seat), NumberOfDoors(Door), FuelType(Type){
            // Paramatrized Constrcutor that calls the Parent Constructor
        }
        void Display() const override{
            cout << "Seating Capacity: " << SeatingCapacity << endl;
            cout << "Number of Doors: " << NumberOfDoors << endl;
            cout << "Fuel Type: " << FuelType << endl;
            Vehicles::Display();
        }
};
// Derived Class 2
class Motorcycle : public Vehicles{
    protected:
        int NumberOfCylinders;
        int NumberOfGears;
        int NumberOfWheels;
    public:
    Motorcycle(double Price, int Cylinders, int Gear, int Wheels) : Vehicles(Price), NumberOfCylinders(Cylinders), NumberOfGears(Gear), NumberOfWheels(Wheels){
            // Paramatrized Constrcutor that calls the Parent Constructor
        }
        void Display() const override{
            cout << "Number of Cylinders: " << NumberOfCylinders << endl;
            cout << "Number of Gears: " << NumberOfGears << endl;
            cout << "Number of Wheels: " << NumberOfWheels << endl;
            Vehicles::Display();
        }
};

// Deriving Sub Class 1
class Audi : public Car{
    private:
        string ModelType;
    public:
        Audi(double Price, int Seat, int Door, string Type, string Model) : Car(Price, Seat, Door, Type), ModelType(Model){
            // Paramatrized Constrcutor that calls the Parent Constructor
        }
        void Display() const override {
            cout << "-------------------------" << endl;
            cout << "Audi Car Details:" << endl << endl;
            cout << "Model Type: " << ModelType << endl;
            Car::Display(); // Call Car's displayDetails to show common car details
            cout << "-------------------------" << endl;
        }
};
// Deriving Sub Class 2
class Yamaha : public Motorcycle{
    private:
        string MakeType;
    public:
        Yamaha(double Price, int Cylinders, int Gear, int Wheels, string Make) : Motorcycle(Price, Cylinders, Gear, Wheels), MakeType(Make){
            // Paramatrized Constrcutor that calls the Parent Constructor
        }
        void Display() const override {
            cout << "-------------------------" << endl;
            cout << "Yamaha Bike Details:" << endl << endl;
            cout << "Make Type: " << MakeType << endl;
            Motorcycle::Display(); // Call Motorcycle displayDetails to show common Motorcycle details
            cout << "-------------------------" << endl;
        }
};

int main() {
    Audi audi(50000, 5, 4, "Petrol", "A4");
    Yamaha yamaha(12000, 4, 5, 2, "YZF-R1");

    audi.Display();
    yamaha.Display();

    return 0;
}
