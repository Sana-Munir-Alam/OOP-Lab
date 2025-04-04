#include <iostream>
#include <string>
using namespace std;

class Matrix {
    private:
        int Rows;
        int Coloumns;
        int** MatrixArray;
    public:
        Matrix(int Rows, int Coloumns){ // Parametrize Constructor
            this -> Rows = Rows;
            this -> Coloumns = Coloumns;
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
        void Fill (double Value){
			for (int i = 0; i < Rows; i++){
				for (int j = 0; j < Coloumns; j++){
					MatrixArray[i][j] = Value;
				}
			}
		}
        // Add function for adding two matrices that are of same size
        Matrix Add(const Matrix& other){
            if (Rows !=other.Rows && Coloumns != other.Coloumns){
                cout << "Matrix size doesnt match!!" << endl;
                return Matrix(0, 0);
            }
            Matrix Result(Rows, Coloumns); // Creating an new result object
            for (int i = 0; i < Rows; ++i) {
                for (int j = 0; j < Coloumns; ++j) {
                    Result.MatrixArray[i][j] = MatrixArray[i][j] + other.MatrixArray[i][j];
                }
            }
            return Result;
        }
        // Function overloading
        Matrix Add(int scalar) {
            Matrix Result(Rows, Coloumns); // Creating an new result object
            for (int i = 0; i < Rows; ++i) {
                for (int j = 0; j < Coloumns; ++j) {
                    Result.MatrixArray[i][j] = MatrixArray[i][j] + scalar;
                }
            }
            return Result;
        }
        // OPERATOR OVERLOADING
        Matrix operator+(const Matrix& other){
            if (Rows !=other.Rows && Coloumns != other.Coloumns){
                cout << "Matrix size doesnt match!!" << endl;
                return Matrix(0, 0);
            }
            Matrix Result(Rows, Coloumns); // Creating an new result object
            for (int i = 0; i < Rows; ++i) {
                for (int j = 0; j < Coloumns; ++j) {
                    Result.MatrixArray[i][j] = MatrixArray[i][j] + other.MatrixArray[i][j];
                }
            }
            return Result;
        }
        // Display function for matrix
        void display() {
            for (int i = 0; i < Rows; ++i) {
                for (int j = 0; j < Coloumns; ++j) {
                    cout << MatrixArray[i][j] << " ";
                }
                cout << endl;
            }
        }
};

/*
Q)Explain How Template-Based Solutions Compare to Function Overloading in Terms of Design and Maintainability for Matrix Operations
Well when we use Function overloading the coce duplication occurs alot as Overloading requires you to write multiple versions of functions for each combination of data types and operations, which leads to code duplication.
As the number of supported matrix types increases, the number of overloaded methods can become unmanageable, leading to a harder-to-maintain codebase.

WHEREAS Templates in C++ provide a way to write functions or classes that work with generic types. You can create a generic Matrix class that works with any data type, and template specialization can allow different behavior for specific types.

Q)Suppose You Have Both an add(const Matrix&) and add(int scalar) Function. Show Code Demonstrating How the Compiler Decides Which Function to Call, and Discuss Potential Ambiguities That Might Arise
The compiler decidess which function to used based upon the argument being passed to the function
Ambiguity: The compiler getting confused if we stored the scalar value in a variable than passed that variable as an argument. Making compiler confused on whether it to use as an object of Matrix or as an integer value.

Q) If Your Library Must Provide a Version That Does Not Allow Operator Overloading, How Would You Design the Function-Based Approach to Keep the Interface User-Friendly?
Providing well-named functions that convey the operation being performed.
*/

int main() {
    Matrix m1(2, 2);
    Matrix m2(2, 2);
    Matrix m3(2, 2);
    
    m1.Fill(12);
    m2.Fill(3);
    m3.Fill(1);
    // Manually setting matrix values for demonstration
    m1.Add(2).display();  // Adding scalar to matrix
    m3.Add(m2).display();  // Adding another matrix
}
