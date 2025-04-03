#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Base class: Person
class Person {
    protected:
        string Name, ID, Address, PhoneNumber, Email;
    public:
        Person(string n, string i, string a, string p, string e) : Name(n), ID(i), Address(a), PhoneNumber(p), Email(e) {
            // Parameterized Constructor
        }

        virtual void DisplayInfo() {
            cout << "Name: " << Name << endl << "ID: " << ID << endl << "Address: " << Address << endl << "Phone: " << PhoneNumber << endl << "Email: " << Email << endl;
        }
        void UpdateInfo(string a, string p, string e) {
            Address = a;
            PhoneNumber = p;
            Email = e;
        }
        string GetName(){ return Name;}
        virtual ~Person() {}
};

// Derived class: Student
class Student : public Person {
    private:
        vector<string> CoursesEnrolled;
        double GPA;
        int EnrollmentYear;
    public:
        Student(string n, string i, string a, string p, string e, double g, int y) : Person(n, i, a, p, e), GPA(g), EnrollmentYear(y) {
            // Parameterized Constructor
        }
        
        void EnrollCourse(string course) { 
            CoursesEnrolled.push_back(course); 
        }

        void DisplayInfo() override {
            Person::DisplayInfo();
            cout << "Enrollment Year: " << EnrollmentYear << endl << "GPA: " << GPA << endl << "Courses Enrolled: ";
            for (const string& course : CoursesEnrolled) cout << course << " ";
            cout << endl;
        }
};

// Derived class: Professor
class Professor : public Person {
    private:
        string Department;
        vector<string> CoursesTaught;
        double Salary;
    public:
        Professor(string n, string i, string a, string p, string e, string d, double s) : Person(n, i, a, p, e), Department(d), Salary(s) {
            // Parameterized Constructor
        }
        void addCourse(string course) { 
            CoursesTaught.push_back(course); 
        }
        void DisplayInfo() override {
            Person::DisplayInfo();
            cout << "Department: " << Department << endl << "Salary: " << Salary << endl << "Courses Taught: ";
            for (const string& course : CoursesTaught) cout << course << " ";
            cout << endl;
        }
};

// Derived class: Staff
class Staff : public Person {
    private:
        string Department, Position;
        double Salary;
    public:
        Staff(string n, string i, string a, string p, string e, string d, string pos, double s) : Person(n, i, a, p, e), Department(d), Position(pos), Salary(s) {
            // Paramatrrized Constructor
        }
        void DisplayInfo() override {
            Person::DisplayInfo();
            cout << "Department: " << Department << endl << "Position: " << Position << endl << "Salary: " << Salary << endl;
        }
};

// Course class
class Course {
    private:
        string CourseID, CourseName, Schedule;
        int Credits;
        Professor* Instructor;
        vector<Student*> students;
    public:
        Course(string ID, string Name, int c, string sched, Professor* prof) : CourseID(ID), CourseName(Name), Credits(c), Schedule(sched), Instructor(prof) {
            // Parameterized Constructor
        }
        void RegisterStudent(Student* student) { 
            students.push_back(student); 
        }
        void DisplayCourseInfo() {
            cout << "Course ID: " << CourseID << endl << "Course Name: " << CourseName << endl << "Credits: " << Credits << endl << "Schedule: " << Schedule << endl << endl << "Instructor:" << endl;
            Instructor->DisplayInfo();  // Calling Professor Display Function
        }
        void CalculateGrades() {
            cout << "Calculating grades for course: " << CourseName << endl;
            for (auto student : students) {
                cout << "Assigning grades for " << student->GetName() << endl;
            }
        }
        ~Course() {
            students.clear();  // Clear students vector (does not delete actual students)
        }
};

int main() {
    Professor prof("Dr. Smith", "P1001", "Faculty Housing", "123-456-7890", "smith@uni.edu", "Computer Science", 90000);
    Student stu("Alice Johnson", "S2001", "Dorm A", "987-654-3210", "alice@uni.edu", 3.8, 2023);
    Course cs101("CS101", "Introduction to Programming", 3, "MWF 10-11 AM", &prof);

    cs101.RegisterStudent(&stu);
    prof.addCourse("CS101");
    stu.EnrollCourse("CS101");
    

    cout << "--- Professor Info ---" << endl;
    prof.DisplayInfo();
    cout << endl << "--- Student Info ---" << endl;
    stu.DisplayInfo();
    cout << endl << "--- Course Info ---" << endl;
    cs101.DisplayCourseInfo();
    cout << endl << "--- Calculating Grades ---" << endl;
    cs101.CalculateGrades();

    return 0;
}
