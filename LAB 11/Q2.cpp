#include <iostream>
#include <exception>
using namespace std;

// Custom Exception for Dimension Mismatch
class DimensionMisMatchException : public exception {
public:
    const char* what() const noexcept override {
        return "Dimension Mismatch Exception!!";
    }
};

// Custom Exception for Negative Dimensions
class NegativeDimensionException : public exception {
public:
    const char* what() const noexcept override {
        return "Matrix Dimension Negative Exception!!";
    }
};

template<typename T>
class Matrix {
private:
    int Rows;
    int Columns;
    T** MatrixArray;

public:
    // Default Constructor
    Matrix() : Rows(2), Columns(2) {
        AllocateAndInitialize();
    }

    // Parameterized Constructor
    Matrix(int rows, int columns) : Rows(rows), Columns(columns) {
        if (Rows <= 0 || Columns <= 0) {
            throw NegativeDimensionException();
        }
        AllocateAndInitialize();
    }

    // Destructor
    ~Matrix() {
        for (int i = 0; i < Rows; i++) {
            delete[] MatrixArray[i];
        }
        delete[] MatrixArray;
    }

    // Element Setter with Bounds Checking
    void SetElement(int i, int j, T value) {
        if (i < 0 || i >= Rows || j < 0 || j >= Columns) {
            throw out_of_range("Invalid matrix indices.");
        }
        MatrixArray[i][j] = value;
    }

    // Element Getter with Bounds Checking
    T GetElement(int i, int j) const {
        if (i < 0 || i >= Rows || j < 0 || j >= Columns) {
            throw out_of_range("Invalid matrix indices.");
        }
        return MatrixArray[i][j];
    }

    int GetRows() const { return Rows; }
    int GetColumns() const { return Columns; }

    // Matrix Addition
    Matrix AddMatrix(const Matrix& other) const {
        if (Rows != other.Rows || Columns != other.Columns) {
            throw DimensionMisMatchException();
        }

        Matrix<T> result(Rows, Columns);
        for (int i = 0; i < Rows; i++) {
            for (int j = 0; j < Columns; j++) {
                result.MatrixArray[i][j] = MatrixArray[i][j] + other.MatrixArray[i][j];
            }
        }
        return result;
    }

    // Matrix Multiplication
    Matrix MultiplyMatrix(const Matrix& other) const {
        if (Columns != other.Rows) {
            throw DimensionMisMatchException();
        }

        Matrix<T> result(Rows, other.Columns);
        for (int i = 0; i < Rows; i++) {
            for (int j = 0; j < other.Columns; j++) {
                result.MatrixArray[i][j] = T();
                for (int k = 0; k < Columns; k++) {
                    result.MatrixArray[i][j] += MatrixArray[i][k] * other.MatrixArray[k][j];
                }
            }
        }
        return result;
    }

    // Print Matrix
    void PrintMatrix() const {
        for (int i = 0; i < Rows; i++) {
            for (int j = 0; j < Columns; j++) {
                cout << MatrixArray[i][j] << " ";
            }
            cout << endl;
        }
    }

private:
    // Allocate and initialize the 2D matrix
    void AllocateAndInitialize() {
        MatrixArray = new T*[Rows];
        for (int i = 0; i < Rows; i++) {
            MatrixArray[i] = new T[Columns];
            for (int j = 0; j < Columns; j++) {
                MatrixArray[i][j] = T(); // Default-initialize (e.g., 0 for int)
            }
        }
    }
};

// Test the Matrix class
int main() {
    try {
        // === Valid Test ===
        Matrix<int> A(2, 2);
        Matrix<int> B(2, 2);

        A.SetElement(0, 0, 1);
        A.SetElement(0, 1, 2);
        A.SetElement(1, 0, 3);
        A.SetElement(1, 1, 4);

        B.SetElement(0, 0, 5);
        B.SetElement(0, 1, 6);
        B.SetElement(1, 0, 7);
        B.SetElement(1, 1, 8);

        cout << "Matrix A:" << endl;
        A.PrintMatrix();

        cout << "\nMatrix B:" << endl;
        B.PrintMatrix();

        Matrix<int> C = A.AddMatrix(B);
        cout << "\nA + B:" << endl;
        C.PrintMatrix();

        Matrix<int> D = A.MultiplyMatrix(B);
        cout << "\nA * B:" << endl;
        D.PrintMatrix();

        // === Error 1: Negative Dimension ===
        cout << "\nTrying to create matrix with negative dimensions..." << endl;
        Matrix<int> Invalid(-3, 4); // Will throw NegativeDimensionException

    } catch (const NegativeDimensionException& e) {
        cerr << "Caught NegativeDimensionException: " << e.what() << endl;
    }

    try {
        // === Error 2: Dimension Mismatch in Addition ===
        cout << "\nTrying to add matrices with mismatched dimensions..." << endl;
        Matrix<int> E(3, 3);
        Matrix<int> F(2, 3);
        Matrix<int> G = E.AddMatrix(F); // Will throw DimensionMisMatchException

    } catch (const DimensionMisMatchException& e) {
        cerr << "Caught DimensionMisMatchException: " << e.what() << endl;
    }

    try {
        // === Error 3: Dimension Mismatch in Multiplication ===
        cout << "\nTrying to multiply matrices with incompatible sizes..." << endl;
        Matrix<int> H(2, 3);
        Matrix<int> I(2, 2);
        Matrix<int> J = H.MultiplyMatrix(I); // Will throw DimensionMisMatchException

    } catch (const DimensionMisMatchException& e) {
        cerr << "Caught DimensionMisMatchException: " << e.what() << endl;
    }

    try {
        // === Error 4: Out-of-Bounds Access ===
        cout << "\nTrying to access out-of-bounds element..." << endl;
        Matrix<int> K(2, 2);
        int value = K.GetElement(5, 0); // Will throw out_of_range

    } catch (const out_of_range& e) {
        cerr << "Caught out_of_range exception: " << e.what() << endl;
    }

    try {
        // === Error 5: Out-of-Bounds Set ===
        cout << "\nTrying to set out-of-bounds element..." << endl;
        Matrix<int> L(2, 2);
        L.SetElement(0, 5, 99); // Will throw out_of_range

    } catch (const out_of_range& e) {
        cerr << "Caught out_of_range exception: " << e.what() << endl;
    }

    return 0;
}
