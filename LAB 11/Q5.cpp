#include <iostream>
#include <vector>
#include <exception>
using namespace std;

// Custom Exception Class for Stack Underflow
class StackUnderflowException : public exception {
public:
    const char* what() const noexcept override {
        return "Stack Underflow Exception: Stack is empty!";
    }
};

// Templated Stack Class
template <typename T>
class Stack {
    private:
        vector<T> data;
    public:
        // Push an element onto the stack
        void push(const T& value) {
            data.push_back(value);
        }
        // Pop the top element
        void pop() {
            if (data.empty()) {
                throw StackUnderflowException();
            }
            data.pop_back();
        }

        // Return the top element
        T top() const {
            if (data.empty()) {
                throw StackUnderflowException();
            }
            return data.back();
        }
        // Check if the stack is empty
        bool isEmpty() const {
            return data.empty();
        }

        // Print all elements (top to bottom)
        void printStack() const {
            cout << "Stack (top to bottom): ";
            for (auto it = data.rbegin(); it != data.rend(); ++it) {
                cout << *it << " ";
            }
            cout << endl;
        }
};

int main() {
    Stack<int> intStack;

    try {
        cout << "Pushing elements onto the stack..." << endl;
        intStack.push(10);
        intStack.push(20);
        intStack.push(30);

        intStack.printStack();

        cout << "Top of stack: " << intStack.top() << endl;

        cout << "Popping elements..." << endl;
        intStack.pop();
        intStack.pop();

        intStack.printStack();
        cout << "Top of stack: " << intStack.top() << endl;

        cout << "Popping last element..." << endl;
        intStack.pop();

        cout << "\nAttempting to pop from empty stack..." << endl;
        intStack.pop(); // Should throw exception

    } catch (const StackUnderflowException& e) {
        cerr << "Caught Exception: " << e.what() << endl;
    }

    try {
        cout << "\nTrying to access top from empty stack..." << endl;
        cout << "Top: " << intStack.top() << endl; // Should throw exception
    } catch (const StackUnderflowException& e) {
        cerr << "Caught Exception: " << e.what() << endl;
    }

    return 0;
}
