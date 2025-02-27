#include <iostream>
using namespace std;

class Engine{	// Component Class
	private:
		bool IsRunning;
	public:
		Engine(): IsRunning(false){
			cout << "Engine Constructor Called!" << endl;
		}
		~Engine() {
	        cout << "Engine destructed!" << endl;
	    }
		void Start(){
			if (IsRunning == false){
				IsRunning = true;
				cout << "Engine Started" << endl;
			}else {
            	cout << "Engine is already running." << endl;
        	}
		}
		void Stop(){
			if (IsRunning == true){
				IsRunning = false;
				cout << "Engine Stopped" << endl;
			}else {
            	cout << "Engine is already stopped." << endl;
        	}
		}
};

class Car{	// Owner CLass
	private:
		Engine Info;	// Composition Member
	public:
		Car(){
			cout << "Car Constructor Called!" << endl;
		}
		~Car() {
	        cout << "Car destructed!" << endl;
	    }
		void StartCar(){
			Info.Start();
		}
		void StopCar(){
			Info.Stop();
		}
};
int main() {
    cout << "===== Car Engine Demonstration =====" << endl;
    {
        cout << endl << "Creating car object..." << endl;
        Car Toyota;
        
        cout << "\nOperating car:" << endl;
        Toyota.StartCar();
        Toyota.StopCar();
        
        cout << endl << "Car going out of scope..." << endl;
    }
    cout << endl << "Program ending..." << endl;
    return 0;
}
