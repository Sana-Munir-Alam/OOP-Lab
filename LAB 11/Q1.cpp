#include <iostream>
#include <any>
#include <exception>
using namespace std;

// Custom Exception for Bad Type
class BadTypeException : public exception {
public:
    const char* what() const noexcept override {
        return "Bad Type Exception!!";
    }
};

// Type-Safe Container class
class TypeSafeContainer {
    private:
        std::any AnyTypeVariable;
    public:
        template <typename T>
        void store(const T& value) {
            AnyTypeVariable = value;
        }
        
        template <typename T>
        T get() const {
            try {
                return std::any_cast<T>(AnyTypeVariable);
            }catch (const std::bad_any_cast&) {
                cerr << "Type mismatch in get<T>()." << endl;
                throw BadTypeException();
            }
        }
};

int main() {
    try {
        TypeSafeContainer container;
        
        container.store<int>(42);
        int myInt = container.get<int>();
        cout << "Stored int: " << myInt << endl;

        container.store<string>("Hi, Good Morning!!");
        string Sentence = container.get<string>();
        cout << "Stored string: " << Sentence << endl;

        double myDouble = container.get<double>();  // This will throw a BadTypeException
        cout << "Stored double: " << myDouble << endl;

    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}
