#include <iostream>
#include <cmath>
using namespace std;

class DynamicArray{
	private:
		int *Array;
		int Size;
	public:
		DynamicArray(){ // Default Constructor
			Size = 0;
			Array = new int[Size];
		}
		DynamicArray(int n){ // Paramatrized Constructor
			Size = n;
			Array = new int[Size];
			for (int i = 0; i < Size; i++){
				Array[i] = 0;
			}
		}
		DynamicArray(const DynamicArray& other){ // Copy Constructor
			Size = other.Size;
			Array = new int[other.Size];
			for (int i = 0; i < other.Size; i++){
				Array[i] = other.Array[i];
			}
		}
		DynamicArray(DynamicArray&& other) noexcept : Size(other.Size), Array(other.Array){	// Move Constructor
			other.Array = nullptr;
			other.Size = 0;
		}
		DynamicArray& operator = (const DynamicArray& other){ //Copy Assignment Operator
			if (this != &other){
				delete[] Array;
				Size = other.Size;
				Array = new int[Size];
				for (int i = 0; i < Size; i++){
					Array[i] = other.Array[i];
				}
			}
			return *this;
		}
		DynamicArray& operator = (DynamicArray&& other) noexcept {
			if(this != &other){
				delete[] Array;
				Array = other.Array;
				Size = other.Size;
				other.Array = nullptr;
				other.Size = 0;
			}
			return *this;
		}
		~DynamicArray(){
			delete[] Array;
		}
		int GetSize(){
			return Size;
		}
		int& AtLocation(int Index){
			return Array[Index];
		}
		const int& AtLocation(int Index) const{
			return Array[Index];
		}
		void Resize(int NewSize){
			if (NewSize < 0){
				Size = 0;
			}
			if (NewSize == 0){
				delete[] Array;
				Array = nullptr;
				Size = 0;
				return;
			}
			int *NewArray = new int [NewSize];
			for(int i = 0; i < NewSize; i++){
				NewArray[i] = 0;
			}
			for(int i = 0; i < Size; i++){
				NewArray[i] = Array[i];
			}
			delete[] Array;
			Array = NewArray;
			Size = NewSize;
		}
		void Print() const {
			cout << "[ ";
			for (int i = 0; i < Size; i++){
				cout << Array[i] << " ";
			}
			cout << "]" << endl;
		}

};
int main(){
	DynamicArray empty;
    cout << "Testing Default Constructor" << endl << "Empty array: ";
    empty.Print();

	DynamicArray D1(5);
    D1.AtLocation(0) = 10;
    D1.AtLocation(3) = 20;
    cout << endl << "Testing Paramatrized Constructor!" << endl << "Array D1: ";
    D1.Print();

	DynamicArray D2 = D1;
	cout  << endl << "Testing Copy Constructor" << endl << "Copying D1 to D2 Array: ";
	D2.Print();

	DynamicArray D3 = move(D1);
	cout  << endl << "Testing Move Constructor" << endl;
    cout << "Array D3 (moved from D1): ";
    D3.Print();
    cout << "Original D1 after move: ";
    D1.Print(); // Printing Empty Slot

	DynamicArray D4;
    D4 = D3;
	cout  << endl << "Testing Copy Assignment Operator" << endl;
    cout << "Array D4 (copy of D3): ";
    D4.Print();

	DynamicArray D5;
    D5 = move(D3);
	cout  << endl << "Testing Move Assignment Operator" << endl;
    cout << "Array D5 (moved from D3): ";
    D5.Print();
    cout << "Original D3 after move: ";
    D3.Print(); // Printing Empty Slot;

	cout << endl << "Size of Array D5: " << D5.GetSize() << endl;
	
	D5.Resize(8);
    D5.AtLocation(5) = 50;
	cout  << endl << "Testing Resize" << endl;
    cout << "Array D5 after resize(8): ";
    D5.Print();

    D5.Resize(3);
    cout << "Array D5 after resize(3): ";
    D5.Print();

    D5.Resize(0);
    cout << "Array D5 after resize(0): ";
    D5.Print();

	return 0;
}
