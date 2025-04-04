#include <iostream>
#include <string>
using namespace std;

class Vehicle {
    public:
        virtual void LoadCargo() {
            cout << "Loading cargo into the vehicle." << endl;
        }

        virtual void Deliver() {
            cout << "Delivering cargo with the vehicle." << endl;
        }

        virtual void UnloadCargo() {
            cout << "Unloading cargo from the vehicle." << endl;
        }

        virtual ~Vehicle() {}  // Virtual destructor to ensure proper cleanup of derived classes
};

class Truck : public Vehicle {
    public:
        void LoadCargo() override {
            cout << "Loading heavy cargo into the truck." << endl;
        }
    
        void Deliver() override {
            cout << "Driving the truck to deliver heavy cargo." << endl;
        }
    
        void UnloadCargo() override {
            cout << "Unloading heavy cargo from the truck." << endl;
        }
};
    
class Bicycle : public Vehicle {
    public:
        void LoadCargo() override {
            cout << "Loading small cargo onto the bicycle." << endl;
        }
    
        void Deliver() override {
            cout << "Pedaling the bicycle to deliver the cargo quickly." << endl;
        }
    
        void UnloadCargo() override {
            cout << "Unloading cargo from the bicycle." << endl;
        }
};
    
class Van : public Vehicle {
    public:
        void LoadCargo() override {
            cout << "Loading cargo into the van." << endl;
        }

        void Deliver() override {
            cout << "Driving the van to deliver the cargo." << endl;
        }

        void UnloadCargo() override {
            cout << "Unloading cargo from the van." << endl;
        }
};

// HybridVan derived Class
class ElectricVehicle {
    public:
        virtual void Charge() {
            cout << "Charging the electric vehicle." << endl;
        }
};
    
class HybridVan : public Van, public ElectricVehicle {
    public:
        void Deliver() override {
            cout << "Delivering cargo with the Hybrid Van, powered by both fuel and electricity." << endl;
        }
};

/*
Q)Show how you might integrate protected inheritance in a scenario where the base class’s public interface is not meant to be fully exposed by the derived class.
*/
class Van2 : protected Vehicle{
    public:
        void startDelivery() {
            LoadCargo();
            Deliver();
            UnloadCargo();
        }
};

/*
Q) Is there a practical case in the logistics world where you would choose to use virtual inheritance? Show or explain how you’d structure it if, say, ElectricVehicle and OffRoadVehicle both inherit from a common Vehicle ancestor, but you need to ensure only one Vehicle sub-object.
*/
class ElectricVehicle2 : virtual public Vehicle {
    public:
        virtual void Charge() {
            cout << "Charging the electric vehicle." << endl;
        }
};

class OffRoadVehicle2 : virtual public Vehicle {
    public:
        virtual void offRoadCapability() {
            cout << "This vehicle can drive off-road." << endl;
        }
};

class ElectricOffRoadVehicle : public ElectricVehicle2, public OffRoadVehicle2 {
public:
    void Deliver() override {
        Charge();
        offRoadCapability();
        cout << "The electric off-road vehicle moves through rough terrain." << endl;
    }
};

// Main function to test the code
int main() {
    // Create objects of derived classes
    Vehicle* truck = new Truck();
    Vehicle* hybridVan = new HybridVan();
    Vehicle* electricOffRoadVehicle = new ElectricOffRoadVehicle();

    // Demonstrate basic functionality for Truck
    cout << "Truck:" << endl;
    truck->LoadCargo();
    truck->Deliver();
    truck->UnloadCargo();
    cout << endl;

    // Demonstrate HybridVan (inherits from both Van and ElectricVehicle)
    cout << "HybridVan:" << endl;
    hybridVan->LoadCargo();
    hybridVan->Deliver();
    hybridVan->UnloadCargo();
    cout << endl;

    // Demonstrate ElectricOffRoadVehicle (virtual inheritance)
    cout << "ElectricOffRoadVehicle:" << endl;
    electricOffRoadVehicle->LoadCargo();
    electricOffRoadVehicle->Deliver();
    electricOffRoadVehicle->UnloadCargo();
    cout << endl;

    // Demonstrating protected inheritance (only accessible within the class)
    cout << " Displaying the protected inheritance" << endl;
    Van2* van2 = new Van2();
    van2->startDelivery();
    cout << endl;

    // Clean up memory
    delete truck;
    delete hybridVan;
    delete electricOffRoadVehicle;
    delete van2;

    return 0;
}
