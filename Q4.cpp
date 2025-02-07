#include <iostream>
using namespace std;

class Employee{
	private:
		double Salary;
	public:
		string FirstName;
		string LastName;
		
		double setSalary(double Income){
			if (Income < 0.0){
				Salary = 0.0;
			}else {
				Salary = Income;
			}
			return Salary;
		}
};

int main(int argc, char* argv[]){
	if (argc != 7){
		cout << "Incorrect Data Format Entered!! Kinldy follow this pattern" << endl;
		cout << "Employee[1].FirstName Employee[1].LastName Employee[1].Salary Employee[2].FirstName Employee[2].LastName Employee[2].Salary";
		return 1;
	}
	Employee EmployeeTest[2]; // Two objects
	EmployeeTest[0].FirstName = argv[1];
	EmployeeTest[0].LastName = argv[2];
	EmployeeTest[0].setSalary(stod(argv[3]));
	string FullName1 = EmployeeTest[0].FirstName + " " + EmployeeTest[0].LastName;
	double Salary1 = 12 * (EmployeeTest[0].setSalary(stod(argv[3])));
	
	EmployeeTest[1].FirstName = argv[4];
	EmployeeTest[1].LastName = argv[5];
	EmployeeTest[1].setSalary(stod(argv[6]));
	string FullName2 = EmployeeTest[1].FirstName + " " + EmployeeTest[1].LastName;
	double Salary2 = 12 * (EmployeeTest[0].setSalary(stod(argv[6])));
	
	cout << "Employee 1" << endl;
	cout << "Name: " << FullName1 << endl;
	cout << "Yearly Salary: $" << Salary1 << endl << endl;
	
	cout << "Employee 2" << endl;
	cout << "Name: " << FullName2 << endl;
	cout << "Yearly Salary: $" << Salary2 << endl << endl;
	
	cout << "-----------------------------------"<<endl;
	cout << "10% Bonus" << endl;
	cout << "Employee 1 Bonus Yearly salary: $" << Salary1 + (Salary1 * 0.1) << endl;
	cout << "Employee 2 Bonus Yearly salary: $" << Salary2 + (Salary2 * 0.1) << endl;
	return 0;
}
