#include <iostream>
using namespace std;

class Engine{	// Component Class
	private:
		bool IsRunning;
	public:
		Engine(): IsRunning(false){
			// Default COnstructor
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
		void StartCar(){
			Info.Start();
		}
		void StopCar(){
			Info.Stop();
		}
};

int main(){
	Car Toyota;
	Toyota.StartCar();
	Toyota.StopCar();
	return 0;
}