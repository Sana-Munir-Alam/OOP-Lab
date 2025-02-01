#include <iostream>
#include <vector>
using namespace std;

struct Subject{
    string Name;
};
struct Student {
    int ID;
    Subject Sub[3];
};



int main(int argc, char* argv[]) {
    if (argc < 2){
        cout << "Insuffcient Data Entered!!";
    }

    int NumOfStudents = stoi(argv[1]);
    vector<Student> Info(NumOfStudents);
    for (int i = 0; i < NumOfStudents; i++){
        Info[i].ID = i+1;
        Info[i].Sub[0].Name = "English";
        Info[i].Sub[1].Name = "Urdu";
        Info[i].Sub[2].Name = "Math";
    }
    for (const auto& i : Info) {
        cout << "Student ID: " << i.ID << endl;
        for (int j = 0; j < 3; j++){
            cout << "Subject" << j + 1 << ": " << i.Sub[j].Name << endl;
        }
    }
    return 0;
}
