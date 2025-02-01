#include <iostream>
#include <vector>
using namespace std;

struct Person {
    int ID;
    string Name;
};

void SortID(vector<Person>&People){
	int Size = People.size();
	for (int i = 0; i < Size - 1; i++){
		for (int j = 0; j < Size - i - 1; j++){
			if(People[j].ID > People[j+1].ID){
				Person Temp = People[j];
				People[j] = People[j+1];
				People[j+1] = Temp;
			}
		}
	}

}
void SortName(vector<Person>&People){
	int Size = People.size();
	for (int i = 0; i < Size - 1; i++){
		for (int j = 0; j < Size - i - 1; j++){
			if(People[j].Name[0] > People[j+1].Name[0]){
				Person Temp = People[j];
				People[j] = People[j+1];
				People[j+1] = Temp;
			}
		}
	}
}

int main(int argc, char* argv[]) {
    int N = stoi(argv[1]);

    if (argc != (2 + 2 * N)) {
        cout << "Invalid Number of Arguments Programs Expects " << 2 + 2 * N << " Arguments." << endl;
        return 1;
    }

    // Vector to store the structure data (it expands based on user input)
    vector<Person> People;

    for (int i = 0; i < N; i++) {
        Person Info;
        Info.ID = stoi(argv[2 + 2 * i]);
        Info.Name = argv[2 + 2 * i + 1];
        People.push_back(Info); //This will push in one person Info in to the stack(eg) at each iteration.
    }

    // Sort by ID
    SortID(People);
    cout << "Sorted by ID:" << endl;
    for (const auto& Info : People) {
        cout << "ID: " << Info.ID << ", Name: " << Info.Name << endl;
    }

	// Sort by Name
    SortName(People);
    cout << "\nSorted By The First Character of The Name:" << endl;
    for (const auto& Info : People) {
        cout << "ID: " << Info.ID << ", Name: " << Info.Name << endl;
    }
    return 0;
}
