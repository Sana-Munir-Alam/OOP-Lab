#include <iostream>
#include <string>
using namespace std;

class Glass{
	public:
		int LiquidLevel;
		
		Glass (){
            LiquidLevel = 200;
        }
		void RefillDrink(){
			LiquidLevel = 200;
			cout << "Your Glass Has been Refilled to 200ml...Enjoy!" << endl;
		}
		
		void DrinkLevel(int millilitres){
            if (millilitres < 0){
                cout << "Invalid Input! Please Enter A Positive Value!!" << endl;
                return;
            }
            LiquidLevel = LiquidLevel - millilitres;
			if ((LiquidLevel) < 100){
				cout << "Your Glass level has dropped below 100ml. Allow me to Refill!" <<endl;
				RefillDrink();
			}else{
				cout << "No need to refill, you still have " << LiquidLevel << "ml left...Enjoy!"<< endl;
			}
		}
};

int main(int argc, char* argv[]){
    string UserInput;
	Glass Info;
	
    cout << "Hola, Welcome to the Robotic Glass Refiller!" << endl;
    cout << "Your Glass Initially Has 200ml of liquid...Enjoy!" << endl;
    cout << "Enter the Amount of liquid you drank in ml OR type 'Exit' to Quit: " << endl;
    
    while (1){
        cout << "> ";
        cin >> UserInput;
        if (UserInput == "Exit"){
            cout << "Adios, Exiting Program..." << endl;
            break;
        }
        Info.DrinkLevel(stoi(UserInput));
    }
    return 0;
}
