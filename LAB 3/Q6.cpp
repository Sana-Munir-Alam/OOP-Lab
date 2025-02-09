/* Notes:
When a problem is found, the throw keyword raises an exception, allowing us to build a custom error.

An exception handler is used by a program to catch an exception. It's added to the area of a program where you'll be dealing with the issue. The catch keyword is used to accomplish this.

The try block identifies the code block for which exceptions will be triggered; one or more catch blocks should be placed after it.

cerr is used to display eros while cout is used for standard output.
*/

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Matrix{
	private:
		int Rows;
        int Coloumns;
        int **MatrixArray;
	public:
		// Default Constructor
		Matrix(){ 
			Rows = 2;
			Coloumns = 2;
			MatrixArray = new int*[Rows];
			for (int i = 0; i < Rows; i++){
				MatrixArray[i] = new int[Coloumns];
			}
			for (int i = 0; i < Rows; i++){
				for (int j = 0; j < Coloumns; j++){
					MatrixArray[i][j] = 0;
				}
			}
		}

		// Paramatrized Constructor
		Matrix(int Rows, int Coloumns){ 
			this -> Rows = Rows;
			this -> Coloumns = Coloumns;
			
			/* Validation Check {Learned something new here Try-Throw-Catch}
			'throw' keyword is used to raise an exception.
			'invalid_argument' is a standard exception class defined in the <stdexcept> header.
			The dialogue in the speech mark is sent to the invalid_argument constructor, detailing the reason for the exception. This can be printed using what() command to fetch it in the catch() part.
			*/
			if (Rows <= 0 || Coloumns <=0){
				throw invalid_argument("Matrix dimensions must be positive integers.");
			}
			
			// Creating that 2D Array dynamically based upon Uswer Input
			MatrixArray = new int*[Rows];
			for (int i = 0; i < Rows; i++){
				MatrixArray[i] = new int[Coloumns];
			}
			// Now initialising all those Matrix elemnts to 0 (so no garbage value).
			for (int i = 0; i < Rows; i++){
				for (int j = 0; j < Coloumns; j++){
					MatrixArray[i][j] = 0;
				}
			}
		}

		// Destructor (Preventing any Memory Leaks due to DMA)
		~Matrix(){ 
			for (int i = 0; i < Rows; i++){
				delete[] MatrixArray[i]; // Freeing the Column First
			}
			delete[] MatrixArray; // Now Freeing the whole Matrix
		}

		int GetRows(){
			return Rows;
		}
		int GetColoumns(){
			return Coloumns;
		}
		void SetElements(int i, int j, int Value){
			if (i < 0 || i >= Rows || j < 0 || j >= Coloumns){
				throw out_of_range("Invalid matrix indices.");
			}
			MatrixArray[i][j] = Value;
		}

		// Add Matrix (The current matrix is M1, while the one that is passed in the argument through Reference is M2)
		Matrix* AddMatrix(const Matrix& other) const{
			if (Rows != other.Rows || Coloumns != other.Coloumns){
				return nullptr;
			}
			// Creating A DMA to store the sum of Matrix
			Matrix* Result = new Matrix(Rows, Coloumns);
			for (int i = 0; i < Rows; i++){
				for(int j = 0; j < Coloumns; j++){
					Result->MatrixArray[i][j] =MatrixArray[i][j] + other.MatrixArray[i][j];
				}
			}
			return Result;
		}

		// Multiply Matrix (The current matrix is M1, while the one that is passed in the argument through Reference is M2)
		Matrix* MultiplyMatrix(const Matrix& other) const{
			if (Coloumns != other.Rows){
				return nullptr;
			}
			// Creating A DMA to store the sum of Matrix
			Matrix* Result = new Matrix(Rows, other.Coloumns);
			for (int i = 0; i < Rows; i++){
				for(int j = 0; j < other.Coloumns; j++){
					for (int k = 0; k < Coloumns; k++){
						Result->MatrixArray[i][j] += MatrixArray[i][k] * other.MatrixArray[k][j];
					}
				}
			}
			return Result;
		}

		// Print Matrix
		void PrintMatrix() const {
			for (int i = 0; i < Rows; i++) {
				for (int j = 0; j < Coloumns; j++) {
					cout << MatrixArray[i][j] << " ";
				}
				cout << endl;
			}
		}
};

int main(int argc, char* argv[]){
    if (argc < 5){
		cerr << "Error: Insufficient Arguments be passed. Kindly write first the Row1 Coloumn1 <Elements of Matrix 1> Row2 Coloumn2 <Elements of Matrix2>" << endl;
		return 1;
	}
	try{
		int Position = 1; // This is sort of a pointer/index for argv
		int Rows1 = stoi(argv[Position++]);
		int Cols1 = stoi(argv[Position++]);
		Matrix M1(Rows1, Cols1); // Creating First Matrix and calling the Paramatrized Constructor
		for (int i = 0; i < Rows1; i++){
			for (int j = 0; j < Cols1; j++){
				if(Position >= argc){
					throw runtime_error("Insufficient Arguments for Matrix 1!!");
				}
				M1.SetElements(i,j,stoi(argv[Position++]));
			}
		}

		int Rows2 = stoi(argv[Position++]);
		int Cols2 = stoi(argv[Position++]);
		Matrix M2(Rows2, Cols2); // Creating Second Matrix and calling the Paramatrized Constructor
		for (int i = 0; i < Rows2; i++){
			for (int j = 0; j < Cols2; j++){
				if(Position >= argc){
					throw runtime_error("Insufficient Arguments for Matrix 1!!");
				}
				M2.SetElements(i,j,stoi(argv[Position++]));
			}
		}
		// Add
		cout << "Matrix 1 + Matrix 2:" << endl;
		Matrix* Sum = M1.AddMatrix(M2);
		if (Sum){
			Sum->PrintMatrix();
			delete Sum;
			cout << endl;
		}else{
			cout << "Matrices can't be Added!" << endl;
		}
		// Multiply
		cout << "Matrix 1 * Matrix 2:" << endl;
        Matrix* Product = M1.MultiplyMatrix(M2);
        if (Product) {
            Product->PrintMatrix();
            delete Product;
        } else {
            cout << "Matrices can't be Multiplied!" << endl;
        }
	}catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
	}
	return 0;
}
