#include <iostream>

using namespace std;

class Number{
    private:
        int Value;
    public:
        Number(int Num) : Value (Num){} // Paramatrized COnstructor

        // Overloading prefix decrement (--Num)
        Number& operator--(){
            Value *= 4;
            return *this;
        }
        // Overloading postfix decrement (Num--)
        Number operator--(int){
            Number temp = *this;
            Value /= 4;
            return temp;
        }
        void display() const {
            cout << "Value: " << Value << endl;
        }
};

int main() {
    Number Num(16);

    cout << "Original: ";
    Num.display();

    --Num; // Prefix: Multiply by 4
    cout << "After Prefix (--Num): ";
    Num.display();

    Num--; // Postfix: Divide by 4
    cout << "After Postfix (Num--): ";
    Num.display();

    return 0;
}
