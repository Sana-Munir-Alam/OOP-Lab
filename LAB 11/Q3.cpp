#include <iostream>
#include <exception>
using namespace std;

// Custom Exception Class
class ArrayIndexOutOfBounds : public exception {
    public:
        const char* what() const noexcept override {
            return "Array Index Out of Bounds Exception!";
        }
};

template<typename T>
class SafeArray {
    private:
        T* arr;
        int size;
    public:
        SafeArray(int s) : size(s) {
            if (size <= 0)
                throw invalid_argument("Size must be positive.");
            arr = new T[size];
        }
        ~SafeArray() {
            delete[] arr;
        }

        // Overloaded subscript operator
        T& operator[](int index) {
            if (index < 0 || index >= size) {
                throw ArrayIndexOutOfBounds();
            }
            return arr[index];
        }
        int getSize() const {
            return size;
        }

        void display() const {
            for (int i = 0; i < size; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main() {
    try {
        SafeArray<int> sa(5);

        for (int i = 0; i < sa.getSize(); ++i) {
            sa[i] = i * 10;
        }
        cout << "Array contents: ";
        sa.display();
      
        cout << "Accessing Valid Index: " << endl;
        cout << sa[2] << endl << endl;

      // Triggering exception
        cout << "Trying to access invalid index 10..." << endl;
        cout << sa[10] << endl; // This will throw

    } catch (const ArrayIndexOutOfBounds& e) {
        cerr << "Caught Exception: " << e.what() << endl;
    } catch (const exception& e) {
        cerr << "Caught General Exception: " << e.what() << endl;
    }
    return 0;
}
