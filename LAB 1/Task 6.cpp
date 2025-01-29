#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 7){
        cout << "Insufficient Data Entered. Make sure you write full name of student!!";
        return 1;
    }
    string FirstName, LastName;
    double Score[5], Average = 0.00, Sum = 0.00;
    
    FirstName = argv[1];
    LastName = argv[2];
    for (int i = 3; i < argc; i ++){
        Score[i-3] = stod(argv[i]);
    }
    for (int i = 0; i < 5; i++){
        Sum = Sum + Score[i];
    }
    Average = Sum / 5;

    cout << fixed << setprecision(2); 
    cout << "Student Name: " << FirstName << " " << LastName << endl;
    cout << "Test Scores: ";
    for (int i = 0; i < 5; i++){
        cout << Score[i] << " ";
    }
    cout << endl;
    cout << "Average Test Score: " << Average << endl;
    return 0;
}
