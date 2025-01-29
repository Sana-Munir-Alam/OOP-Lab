#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
    if (argc != 21){
        cout <<"Enter Exactly 20 Float Numbers!!";
        return 1;
    }
    float Array[20];
    //Copying array that is taken from Powershell into a new array
    for (int i = 1; i < argc; i++){
        Array[i-1] = stof(argv[i]);
    }
    float *FirstMax = nullptr;
    float *SecondMax = nullptr;

    for (float *ptr = Array; ptr < (Array + 20); ptr++){
        if (FirstMax == nullptr || *ptr > *FirstMax){
            SecondMax = FirstMax;
            FirstMax = ptr;
        }else if (SecondMax == nullptr || (*ptr > *SecondMax && *ptr != *FirstMax)) {
            SecondMax = ptr;
        }
    }
    if (SecondMax != nullptr) {
        cout << "The second highest number is: " << *SecondMax << endl;
    } 
    return 0;
}
