#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
    if (argc < 2){
        cout << "Atleast Enter Few Numbers Pls!!" << endl;
        return 1;
    }
    int Sum = 0;
    int *ptr;
    for (int i = 1; i < argc; i++){
        int Num = stof(argv[i]);
        ptr = &Num;
        Sum = Sum + *ptr;
    }
    cout << "Sum of Array Elements is: "<< Sum <<endl;
    return 0;
}
