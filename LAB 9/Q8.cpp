#include <iostream>
#include <string>

using namespace std;

// Abstract Base Class
class Student {
public:
    virtual double GetTuition(const string& StudentStatus, int CreditHours) = 0;
    virtual ~Student() {}
};

// Derived Class: GraduateStudent
class GraduateStudent : public Student {
    private:
        string ResearchTopic;
    public:
        // Setter and Getter
        void SetResearchTopic(const string& Topic) { ResearchTopic = Topic; }
        string GetResearchTopic() const { return ResearchTopic; }

        double GetTuition(const string& StudentStatus, int CreditHours) override {
            double RatePerHour = 0;
            if (StudentStatus == "undergraduate") {
                RatePerHour = 200;
            } else if (StudentStatus == "graduate") {
                RatePerHour = 300;
            } else if (StudentStatus == "doctoral") {
                RatePerHour = 400;
            } else {
                cout << "Invalid student status!" << endl;
                return 0.0;
            }
            return RatePerHour * CreditHours;
        }
};

int main() {
    GraduateStudent GradStudent;

    string Status;
    int CreditHours;
    string Topic;

    cout << "--- Graduate Student Tuition Calculator ---" << endl;

    cout << "Enter Student Status (undergraduate / graduate / doctoral): ";
    getline(cin, Status);

    cout << "Enter Number of Credit Hours: ";
    cin >> CreditHours;
    cin.ignore(); // Clear newline character

    cout << "Enter Research Topic: ";
    getline(cin, Topic);

    GradStudent.SetResearchTopic(Topic);

    double Tuition = GradStudent.GetTuition(Status, CreditHours);

    cout << "\n--- Tuition Summary ---" << endl;
    cout << "Research Topic: " << GradStudent.GetResearchTopic() << endl;
    cout << "Student Status: " << Status << endl;
    cout << "Credit Hours: " << CreditHours << endl;
    cout << "Total Tuition: $" << Tuition << endl;

    return 0;
}
