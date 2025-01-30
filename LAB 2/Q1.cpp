#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
    if(argc < 2){
        cout << "Insufficent Data Entered!!";
        return 1;
    }

    int Size = argc - 1;
    int* Array = new int[Size];
    for (int i = 0; i < Size; i++){
        Array[i] = stoi(argv[i+1]);
    }
    int Sum = 0;
    int* ptr = Array;

    for (int i = 0; i < Size; i++){
        Sum = Sum + *ptr;
        ptr++;
    }
    cout << "The Sum of The Array Is: " << Sum << endl;

    delete[] Array;
    return 0;
}