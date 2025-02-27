#include <iostream>
#include <string>
#include <unistd.h> // For "sleep" Function

using namespace std;

class Blend {
public:
    void BlendJuice(string FruitName) {
        cout << "Blending " << FruitName << " juice..." << endl;
        for (int i = 0; i < 4; i++) {   // Loop for sleeping
            cout << "Blending..." << endl;
            sleep(1);
        }
        cout << "Blending complete!" << endl;
    }
};

class Grind {
    public:
        void GrindJuice(string FruitName) {
            cout << "Grinding " << FruitName << " juice..." << endl;
            sleep(5);
            cout << "Grinding complete!" << endl;
        }
};

class JuiceMaker {
    private:
        Blend BlendProcess;
        Grind GrindProcess;

    public:
        void MakeJuice(string FruitName) {
            BlendProcess.BlendJuice(FruitName);
            GrindProcess.GrindJuice(FruitName);
            cout << FruitName << " juice is ready!" << endl;
        }
};

int main() {
    string FruitName;
    cout << "Enter Fruit Name for Juice: ";
    cin >> FruitName;
    JuiceMaker JuiceMachine;
    JuiceMachine.MakeJuice(FruitName);
    return 0;
}
