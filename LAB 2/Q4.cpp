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
	if (argc < 2){
		cout << "Insufficent Data Enters!!. Pls enter Organization Name/Number/ Employee ID/Name/Salary.";
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
