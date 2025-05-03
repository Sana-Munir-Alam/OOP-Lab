#include <iostream>
#include <vector>
#include <stdexcept>

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
    int rows, cols;
    vector<vector<T>> data;

public:
    // Default Constructor
    Matrix() : rows(2), cols(2), data(2, vector<T>(2, T())) {}

    // Parameterized Constructor
    Matrix(int r, int c) : rows(r), cols(c) {
        if (rows <= 0 || cols <= 0)
            throw NegativeDimensionException();
        data = vector<vector<T>>(rows, vector<T>(cols, T()));
    }

    // Element Setter with Bounds Checking
    void SetElement(int i, int j, T value) {
        if (i < 0 || i >= rows || j < 0 || j >= cols)
            throw out_of_range("Invalid matrix indices.");
        data[i][j] = value;
    }

    // Element Getter with Bounds Checking
    T GetElement(int i, int j) const {
        if (i < 0 || i >= rows || j < 0 || j >= cols)
            throw out_of_range("Invalid matrix indices.");
        return data[i][j];
    }

    int GetRows() const { return rows; }
    int GetColumns() const { return cols; }

    // Operator+ Overloading for Matrix Addition
    Matrix<T> operator+(const Matrix<T>& other) const {
        if (rows != other.rows || cols != other.cols)
            throw DimensionMisMatchException();

        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result.data[i][j] = data[i][j] + other.data[i][j];

        return result;
    }

    // Operator* Overloading for Matrix Multiplication
    Matrix<T> operator*(const Matrix<T>& other) const {
        if (cols != other.rows)
            throw DimensionMisMatchException();

        Matrix<T> result(rows, other.cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < other.cols; ++j)
                for (int k = 0; k < cols; ++k)
                    result.data[i][j] += data[i][k] * other.data[k][j];

        return result;
    }

    // Print Matrix
    void PrintMatrix() const {
        for (const auto& row : data) {
            for (const auto& val : row)
                cout << val << " ";
            cout << endl;
        }
    }
};

// Test the Matrix class
int main() {
    try {
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

        cout << "Matrix A:\n";
        A.PrintMatrix();

        cout << "\nMatrix B:\n";
        B.PrintMatrix();

        Matrix<int> C = A + B;
        cout << "\nA + B:\n";
        C.PrintMatrix();

        Matrix<int> D = A * B;
        cout << "\nA * B:\n";
        D.PrintMatrix();

        // Negative Dimensions
        cout << "\nTrying to create matrix with negative dimensions...\n";
        Matrix<int> Invalid(-3, 4); // throws

    } catch (const NegativeDimensionException& e) {
        cerr << "Caught NegativeDimensionException: " << e.what() << endl;
    }

    try {
        // Addition dimension mismatch
        cout << "\nTrying to add mismatched matrices...\n";
        Matrix<int> E(3, 3), F(2, 3);
        Matrix<int> G = E + F;

    } catch (const DimensionMisMatchException& e) {
        cerr << "Caught DimensionMisMatchException: " << e.what() << endl;
    }

    try {
        // Multiplication dimension mismatch
        cout << "\nTrying to multiply incompatible matrices...\n";
        Matrix<int> H(2, 3), I(2, 2);
        Matrix<int> J = H * I;

    } catch (const DimensionMisMatchException& e) {
        cerr << "Caught DimensionMisMatchException: " << e.what() << endl;
    }

    try {
        // Out-of-bounds access
        cout << "\nTrying to access out-of-bounds element...\n";
        Matrix<int> K(2, 2);
        int val = K.GetElement(5, 0);

    } catch (const out_of_range& e) {
        cerr << "Caught out_of_range exception: " << e.what() << endl;
    }

    try {
        // Out-of-bounds set
        cout << "\nTrying to set out-of-bounds element...\n";
        Matrix<int> L(2, 2);
        L.SetElement(0, 5, 99);

    } catch (const out_of_range& e) {
        cerr << "Caught out_of_range exception: " << e.what() << endl;
    }

    return 0;
}
