#include <iostream>
#include <cstring>
using namespace std;

void ResizeArray(int*& Arr, int& Capacity, int NewCapacity) {
    int* NewArr = new int[NewCapacity];
    memcpy(NewArr, Arr, Capacity * sizeof(int)); // Copy existing elements
    delete[] Arr; // Free old memory
    Arr = NewArr;
    Capacity = NewCapacity;
}

int main(int argc, char* argv[]){
	if (argc < 2){
		cout << "Insufficent Data Entered!!";
	}

	int InitialSize = 5;
	int CurrentSize = InitialSize;
	int *Array = new int [CurrentSize];
	
	// Double Resize
	if (argc - 1 > InitialSize) {
        CurrentSize = InitialSize * 2;
        ResizeArray(Array, CurrentSize, CurrentSize);
        cout << "Array Resized To " << CurrentSize << " Elements." << endl;
    }

	for (int i = 0; i < argc - 1; i++) {
        Array[i] = stoi(argv[i+1]);
    }

	// Final Resize of The Array
	if (argc - 1 < CurrentSize) {
        ResizeArray(Array, CurrentSize, argc - 1);
        cout << "Array resized to " << argc - 1 << " elements." << endl;
    }
		
	// Final Output
	cout << "Displaying Resized Array: " << endl;
	cout << "Array: [";
	for (int i = 0; i < argc - 1; i++) {
		cout << Array[i];
		if (i < argc - 2) {
			cout << ", ";
		}
	}
	cout << "]" << endl;
	delete[] Array;
		
	return 0;	
}
