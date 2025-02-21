#include <iostream>
#include <vector>
using namespace std;

class Car{
	public:
		string Name;
		int ID;
		Car(){
			// Default Constructor
			cout << "Car Constructor Called!" << endl;
		}
		Car(int CarID, string CarName) : Name(CarName), ID(CarID){
			// Parmatrized Constructor
		}
		~Car() {
	        cout << "Car destructed!" << endl;
	    }
		void Display() const {
			cout << "Car ID: " << ID << endl << "Car Name: " << Name << endl;
		}
};

class Garage{
	private:
		string GarageName;
		vector<Car*> Info;
	public:
		Garage(){
			// Default Constructor
			cout << "Garage Constructor Called!" << endl;
		}
		Garage(string Name) : GarageName(Name){
			// Paramatrzed Constructor
			cout << "Garage Constructor Called!" << endl;
		}
		~Garage() {
	        cout << "Garage Destructed!" << endl;
	    }
		void ParkCar(Car * C){
			Info.push_back(C);
		}
		void ListCars() const {
			cout << "Garage Name: " << GarageName << endl;
			for (auto car : Info){
				car -> Display();
			}
		}
};

int main(){
	Car C1(123, "Toyota");
	Car C2(321, "City");
	Car C3(394, "Vigo");
	Garage Info("Sunshine Garage");
	Info.ParkCar(&C1);
	Info.ParkCar(&C2);
	Info.ParkCar(&C3);
	Info.ListCars();
}
