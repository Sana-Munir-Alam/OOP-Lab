#include <iostream>
#include <string>
using namespace std;

class Student{
    private:
        const int RollNum;
        string StudentName;
    public:
        Student(int ID, string Name) : RollNum(ID), StudentName(Name) {
            // Paramatrized Constructor
        }
        void Display() const{
            cout << "Student ID: " << RollNum <<endl;
            cout << "Student Name: " << StudentName <<endl;
        }

};

int main() {
    int ID;
    string Name;
    cout << "Enter Student Name: ";
    getline(cin, Name);
    cout << "Enter Roll Number: ";
    cin >> ID;

    Student Student1(ID, Name);

    // Displaying details
    cout << endl << "Student Details:" << endl;
    Student1.Display();

    return 0;
}
