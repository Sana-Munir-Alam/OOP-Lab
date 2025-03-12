#include <iostream>
#include <string>
using namespace std;

//In the question figure they had a getStudentDetail and getMarks function therefore i am not using constructors or seperate setters and getters.

//Base Class
class Student{
    protected:
        int StudentID;
        string StudentName;
    public:
        // Noy
        void getStudentDetail(int ID, const string& Name) {
            StudentID = ID;
            StudentName = Name;
        }
        void DisplayStudentDetails(){
            cout << "~---------Student Details---------~" << endl;
            cout << "Student ID: " << StudentID << endl;
            cout << "Student Name: " << StudentName << endl;
            cout << "~---------------------------------~" << endl;
        }
};

class Marks : public Student{
    protected:
        int PF_Marks, OOP_Marks, DS_Marks, DB_Marks;
    public:
        void getMarks(int PF, int OOP, int DS, int DB){
            PF_Marks = PF;
            OOP_Marks = OOP;
            DS_Marks = DS;
            DB_Marks = DB;
        }
        void DisplayMarks() const {
            cout << "~---------Marks Obtained---------~" << endl;
            cout << "Programming Fundamentals: " << PF_Marks << endl;
            cout << "Object-Oriented Programming: " << OOP_Marks << endl;
            cout << "Data Structures: " << DS_Marks << endl;
            cout << "Database Systems: " << DB_Marks << endl;
            cout << "~---------------------------------~" << endl;
        }
};

class Result: public Marks{
    protected:
        int Total;
        double Average;
    public:
        void CalculateResult(){
            Total = PF_Marks + OOP_Marks + DS_Marks + DB_Marks;
            Average = Total / 4.0;
        }
        void DisplayResult() const{
            cout << "Total Marks: " << Total << endl;
            cout << "Average Marks: " << Average << endl;
        }
        void DisplayAll(){
            DisplayStudentDetails();
            DisplayMarks();
            DisplayResult();
        }
};

int main(){
    Result result;
    result.getStudentDetail(0573, "Richard");
    result.getMarks(85,90,48,88);
    result.CalculateResult();
    result.DisplayAll();
    return 0;
}
