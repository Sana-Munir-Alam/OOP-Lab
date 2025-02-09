#include <iostream>
#include <string>
using namespace std;

class User{
	public:
		int Age;
		string Name;
};

int main(int argc, char* argv[]){
	if(argc != 3){
		cout << "Incorrect Data Entered!! Enter First Name and Age Only Respectiveley!!";
		return 1;
	}
	User Info;
	Info.Name = argv[1];
	Info.Age = stoi(argv[2]);
	cout << "My name is " << Info.Name << " and I'm " << Info.Age << " years old.";
	return 0;
}
