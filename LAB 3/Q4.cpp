#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Employee{
	private:
		double Salary;
		string FirstName;
		string LastName;
	public:
		void SetFirstName (string First){
            FirstName = First;
        }
        void SetLastName (string Last){
            LastName = Last;
        }
		void SetSalary(double Income){
			if (Income < 0.0){
				Salary = 0.0;
			}else {
				Salary = Income;
			}
		}

        string GetFirstName(){
            return FirstName;
        }
        string GetLastName(){
            return LastName;
        }
        double GetSalary(){
            return Salary;
        }

        double YearlySalary() {
            return Salary * 12;
        }
        void SalaryRaise(){
            Salary = Salary * 1.10;
        }
};

int main(int argc, char* argv[]){
	if (argc != 7){
		cout << "Incorrect Data Format Entered!! Kinldy follow this pattern" << endl;
		cout << "Employee[1].FirstName Employee[1].LastName Employee[1].Salary Employee[2].FirstName Employee[2].LastName Employee[2].Salary";
		return 1;
	}
	Employee EmployeeTest[2]; // Two objects

    for (int i = 0; i < 2; i++){
        EmployeeTest[i].SetFirstName(argv[1 + 3 * i]); // This Picks First Name From argc Location 1 and 4
        EmployeeTest[i].SetLastName(argv[2 + 3 * i]); // This Picks Last Name From argc Location 2 and 5
        EmployeeTest[i].SetSalary(stod(argv[3 + 3 * i]));  // This Picks Salary From argc Location 3 and 6
    }

    cout << fixed << setprecision(2);
	for (int i = 0; i < 2; i++){
        cout << "Employee " << i + 1 << endl;
        cout << "Name: " << EmployeeTest[i].GetFirstName() << " " << EmployeeTest[i].GetLastName() << endl;
        cout << "Yearly Salary: $" << EmployeeTest[i].YearlySalary() << endl << endl;
    }
	
    for (int i = 0; i < 2; i++){
        EmployeeTest[i].SalaryRaise();
    }
	cout << "-----------------------------------"<<endl;
	cout << "After 10% Raise: " << endl;
	for (int i = 0; i < 2; i++){
        cout << "Employee " << i + 1 << endl;
        cout << "Name: " << EmployeeTest[i].GetFirstName() << " " << EmployeeTest[i].GetLastName() << endl;
        cout << "Yearly Salary: $" << EmployeeTest[i].YearlySalary() << endl << endl;
    }
	return 0;
}
