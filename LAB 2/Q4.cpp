#include <iostream>
#include <string>
using namespace std;

struct Employees{
	int EmployeeID;
	string EmployeeName;
	double Salary;
};

struct Organization{
	string OrganizationName;
	string OrganizationNumber;
	Employees Emp;
};

int main(int argc, char* argv[]){
	if (argc < 7) {
        cout << "Insufficient Data Entered!!" << endl;
        cout << "Please provide the following arguments:" << endl;
        cout << "1. Organization Name" << endl;
        cout << "2. Organization Number" << endl;
        cout << "3. Employee ID" << endl;
        cout << "4. Employee First Name" << endl;
        cout << "5. Employee Last Name" << endl;
        cout << "6. Employee Salary" << endl;
        return 1;
    }
	Organization Org;
	Org.OrganizationName = argv[1];
	Org.OrganizationNumber = argv[2];
	Org.Emp.EmployeeID = stoi(argv[3]);
	string First = argv[4];
	string Last = argv[5];
	Org.Emp.EmployeeName = First + " " + Last;
	Org.Emp.Salary = stoi(argv[6]);
	
	cout << "The size of Outer Structure [Organization] is: " << sizeof(Organization) << endl;
 	cout << "Organisation Name: " << Org.OrganizationName << endl;
	cout << "Organisation Number: " << Org.OrganizationNumber << endl;
	
	cout << "Employee id: " << Org.Emp.EmployeeID << endl;
	cout << "Employee name: " << Org.Emp.EmployeeName << endl;
	cout << "Employee Salary: " << Org.Emp.Salary << endl;
	return 0;	
}
