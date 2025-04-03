#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Person {
    protected:
        string Name, ID, Address, PhoneNumber, Email;
    public:
        Person(string n, string i, string a, string p, string e) 
            : Name(n), ID(i), Address(a), PhoneNumber(p), Email(e) {}

        virtual void DisplayInfo() {
            cout << "Name: " << Name << endl << "ID: " << ID 
                 << endl << "Address: " << Address << endl << "Phone: " << PhoneNumber 
                 << endl << "Email: " << Email << endl;
        }
        virtual void UpdateInfo(string a, string p, string e) {
            Address = a;
            PhoneNumber = p;
            Email = e;
        }
        string GetID() const { return ID; }
        string GetName() const { return Name; }
        virtual ~Person() {}
};

class Student : public Person {
    private:
        vector<string> CoursesEnrolled;
        double GPA;
        int EnrollmentYear;
    public:
        Student(string n, string i, string a, string p, string e, double g, int y) 
            : Person(n, i, a, p, e), GPA(g), EnrollmentYear(y) {}

        void EnrollCourse(const string& course) { 
            CoursesEnrolled.push_back(course); 
        }

        void DisplayInfo() override {
            Person::DisplayInfo();
            cout << "Enrollment Year: " << EnrollmentYear << endl << "GPA: " << GPA 
                 << endl << "Courses Enrolled: ";
            for (const auto& course : CoursesEnrolled) cout << course << " ";
            cout << endl;
        }
};

class Professor : public Person {
    private:
        string Department;
        vector<string> CoursesTaught;
        double Salary;
    public:
        Professor(string n, string i, string a, string p, string e, string d, double s) 
            : Person(n, i, a, p, e), Department(d), Salary(s) {}

        void AddCourse(const string& course) { 
            CoursesTaught.push_back(course); 
        }

        void DisplayInfo() override {
            Person::DisplayInfo();
            cout << "Department: " << Department << endl << "Salary: " << Salary 
                 << endl << "Courses Taught: ";
            for (const auto& course : CoursesTaught) cout << course << " ";
            cout << endl;
        }
};

class Staff : public Person {
    private:
        string Department, Position;
        double Salary;
    public:
        Staff(string n, string i, string a, string p, string e, string d, string pos, double s) 
            : Person(n, i, a, p, e), Department(d), Position(pos), Salary(s) {}

        void DisplayInfo() override {
            Person::DisplayInfo();
            cout << "Department: " << Department << endl << "Position: " << Position 
                 << endl << "Salary: " << Salary << endl;
        }
};

class Course {
    private:
        string CourseID, CourseName, Schedule;
        int Credits;
        Professor* Instructor;
        vector<Student*> Students;
    public:
        Course(string id, string name, int c, string sched, Professor* prof) 
            : CourseID(id), CourseName(name), Credits(c), Schedule(sched), Instructor(prof) {
            Instructor->AddCourse(CourseID);  // Auto-add course to professor's list
        }

        void RegisterStudent(Student* student) { 
            Students.push_back(student);
            student->EnrollCourse(CourseID);  // Auto-enroll student
        }

        void DisplayCourseInfo() {
            cout << "Course ID: " << CourseID << endl << "Course Name: " << CourseName 
                 << endl << "Credits: " << Credits << endl << "Schedule: " << Schedule 
                 << endl << "Instructor:" << endl << endl;
            Instructor->DisplayInfo();
        }

        void CalculateGrades() {
            cout << "Calculating grades for " << CourseName << ":" << endl;
            for (auto student : Students) {
                cout << "Assigned grade to " << student->GetName() << endl;
            }
        }
};

int main() {
    Professor prof("Dr. Smith", "P1001", "Faculty Housing", "123-456-7890", "smith@uni.edu", "Computer Science", 90000);
    Student stu("Alice Johnson", "S2001", "Dorm A", "987-654-3210", "alice@uni.edu", 3.8, 2023);
    Course cs101("CS101", "Intro to Programming", 3, "MWF 10-11 AM", &prof);

    cs101.RegisterStudent(&stu);  // Now handles both registration and enrollment

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
