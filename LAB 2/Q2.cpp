#include <iostream>
using namespace std;

void* Add(void* Array, void* Size, void* ValueToAdd){
    //We need the array first element address so we aren't going to dereference right now.
    int* intArray = static_cast<int*>(Array);
    //We need these values not their Address so we are going to dereference it.
    int ASize = *static_cast<int*>(Size);
    int AddValue = *static_cast<int*>(ValueToAdd);

    for (int i = 0; i < ASize; i++){
        intArray[i] += AddValue;
    }
    return static_cast<void*>(intArray);
}

int main(int argc, char *argv[]){
    if(argc < 3){
        cout << "Insufficent Data Entered!!";
        return 1;
    }

    int ValueToAdd = stoi(argv[1]);
    int Size = argc - 1;
    int* Array = new int[Size];
    for (int i = 0; i < Size; i++){
        Array[i] = stoi(argv[i+1]);
    }
    void* ReturnedArray = Add(static_cast<void*>(Array), static_cast<void*>(&Size), static_cast<void*>(&ValueToAdd)); 

    int* FinalArray = static_cast<int*>(ReturnedArray);

    cout << "The Array Elements After Adding " << ValueToAdd << " To Each Element: "<< endl;
    for (int i = 0; i < Size; i++){
        cout << FinalArray[i] << " ";
    }
    cout << endl;

    delete[] Array;
    return 0;
}
