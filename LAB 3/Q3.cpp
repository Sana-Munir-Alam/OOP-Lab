#include <iostream>
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
            if (LiquidLevel < 0){
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
	if (argc != 2){
		cout << "Incorrect data Entered!!" << endl << "Kindly Enter the amount of Drink intake";
		return 1;
	}
	Glass Info;
	Info.DrinkLevel(stoi(argv[1]));
	return 0;
}
