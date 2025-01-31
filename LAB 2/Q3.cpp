#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char* argv[]){
    
	int* Array = new int[5];
    if (argc < 6){
    	int Size = argc - 1;
    	cout << "Without Resizing Array: " << endl;
    	for (int i= 0; i < Size; i++){
    		Array[i] = stoi(argv[i+1]);
		}
		for (int i= 0; i < Size; i++){
    		cout << Array[i] << " ";
		}
		cout << endl;
	
	}else{
		int Size = argc - 1;
		int* NewArray = new int[10];
		memcpy(NewArray, Array, 5 * sizeof(int));
		delete[] Array; //Free Old Memory
		Array = NewArray;
		
		for (int i = 5; i < Size; i++){
    		NewArray[i] = stoi(argv[i+1]);
		}
		
		//Final resize to the max capacity of Elements
		int* FinalNew = new int[Size];
		memcpy(FinalNew, NewArray, (Size) * sizeof(int));
		delete[] Array;
		Array = FinalNew;
		cout << "Resized array: " << endl;
		for (int i = 0; i < Size; i++){
    		cout << Array[i] << " ";
		}
		cout << "\n";
	}
	
	delete[] Array;
	return 0;
}

///////////////////////////////////////
#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char* argv[]){
    
	int* Array = new int[5];
    if (argc < 6){
    	cout << "Without Resizing Array: " << endl;
    	for (int i= 0; i < argc - 1; i++){
    		Array[i] = stoi(argv[i+1]);
		}
		for (int i= 0; i < argc - 1; i++){
    		cout << Array[i] << " ";
		}
		cout << endl;
	}else{
		int* NewArray = new int[10];
		memcpy(NewArray, Array, 5 * sizeof(int));
		delete[] Array; //Old Array Deleted
		Array = NewArray;
		for (int i= 5; i < argc - 1; i++){
    		Array[i] = stoi(argv[i+1]);
		}
		
		//Final resize to the max capacity of Elements
		int* FinalNew = new int[argc - 1];
		memcpy(NewArray, Array, (argc - 1) * sizeof(int));
		delete[] Array;
		Array = FinalNew;
		cout << "Resized array: " << endl;
		for (int i = 0; i < argc - 1; i++){
    		cout << Array[i] << " ";
		}
		cout << "\n";
	}
	
	delete[] Array;
	return 0;
}
