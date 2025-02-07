#include <iostream>
using namespace std;

class Date{
	int Month;
	int Day;
	int Year;
	public:
		void setDay(int day){
			Day = day;
		}
		void setMonth(int month){
			Month = month;
		}
		void setYear(int year){
			Year = year;
		}
		void DisplayDate(){
			cout << Month << "/" << Day << "/" << Year;
		}
};

int main(int argc, char* argv[]){
	if (argc != 4){
		cout << "Incorrect data Entered!!" << endl << "Kindly type in Month Day Year";
		return 1;
	}
	Date DateTest;
	DateTest.setMonth(stoi(argv[1]));
	DateTest.setDay(stoi(argv[2]));
	DateTest.setYear(stoi(argv[3]));
	DateTest.DisplayDate();
	return 0;
}
