#include <iostream>
using namespace std;
/*
According to google and manuals we can't directly change the value of non-constant public attribute within a constant function.
Reason being that constant functions are designed to not modify the state of the object they are called on.
According to google the workarounds are
1- Non-Constant Function: create a non-constant function to modify the sttrubute.       [Reject as Question says CONSTANT FUNCTION]
2- Mutable Keyword: You can use the mutable keyword to allow modification of specific attributes even within a constant function. However, this should be used judiciously, as it can undermine the purpose of constant functions.              [First Time I heard about this, as we arent taught this in Uni so confused whether to use it or not, I AM USING IT AS I HAVE NO OTHER IDEA].
3- Getters and Setters: [REJECT]
*/
class Car{
    public:
        mutable  int EngineHorsePower;
        mutable  int SeatingCapacity;
        mutable  int NoOfSpeaker;
        // Constant Function Changing Data
        void UpdateDetails(int Power, int Seats, int Speakers) const {
            EngineHorsePower = Power;
            SeatingCapacity = Seats;
            NoOfSpeaker = Speakers;
        }
        void Display() const {
            cout << "Engine Horsepower: " << EngineHorsePower << endl
                 << "Seating Capacity: " << SeatingCapacity << endl
                 << "Number of Speakers: " << NoOfSpeaker << endl << endl;
        }
};

int main() {
    Car Info;
    Info.EngineHorsePower = 120;
    Info.SeatingCapacity = 25;
    Info.NoOfSpeaker = 4;

    cout << "Initial values:" << endl;
    Info.Display();

    // Modifying
    Info.UpdateDetails(180, 7, 6);
    cout << "After modification through const function:" << endl;
    Info.Display();
    return 0;
}
