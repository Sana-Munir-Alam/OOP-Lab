#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Employee {
public:
    int ID;
    string Name;
    string Designation;
    int YOS;

    Employee();

    Employee(int ID, string Name, string Designation, int year) : ID(ID), Name(Name), Designation(Designation), YOS(year) {}

    string toCSV() const {
        return to_string(ID) + "," + Name + "," + Designation + "," + to_string(YOS);
    }

    static Employee fromCSV(const string& line) {
        stringstream ss(line);
        string item;
        vector<string> tokens;
        while (getline(ss, item, ',')) {
            tokens.push_back(item);
        }
        return Employee(stoi(tokens[0]), tokens[1], tokens[2], stoi(tokens[3]));
    }
};

// CRUD Manager handles all operations
class CRUDManager {
    private: 
        string fileName;
    public:
        CRUDManager(const string& file) : fileName(file) {}

        void initializeDummyData() {
            ofstream out(fileName);
            if (!out) {
                cerr << "Error opening file for writing!" << endl;
                return;
            }
            // Dummy Data
            vector<Employee> dummy = {
                {1, "John Doe", "engineer", 3},
                {2, "Jane Smith", "manager", 5},
                {3, "Albert Finch", "analyst", 1},
                {4, "Emily Clark", "manager", 2},
                {5, "Greg Hall", "technician", 1}
            };

            for (const auto& emp : dummy) {
                out << emp.toCSV() << endl;
            }

            out.close();
            cout << "Dummy data initialized.\n";
        }

        vector<Employee> readAll() {
            vector<Employee> employees;
            ifstream in(fileName);
            string line;
            while (getline(in, line)) {
                if (!line.empty()) {
                    employees.push_back(Employee::fromCSV(line));
                }
            }
            in.close();
            return employees;
        }

        void writeAll(const vector<Employee>& employees) {
            ofstream out(fileName);
            for (const auto& emp : employees) {
                out << emp.toCSV() << endl;
            }
            out.close();
        }

        // Query (a): Find managers with >= 2 years service
        vector<Employee> filterManagersWithMinService(int minYears = 2) {
            vector<Employee> filtered;
            vector<Employee> all = readAll();
            for (const auto& emp : all) {
                if (emp.Designation == "manager" && emp.YOS >= minYears) {
                    filtered.push_back(emp);
                }
            }
            return filtered;
        }

        // Query (b): Delete all data except filtered set
        void keepOnly(const vector<Employee>& toKeep) {
            writeAll(toKeep);
            cout << "Filtered data written to file (others deleted).\n";
        }

        // Query (c): Write updated records with incremented ID and years
        void writeWithIncrementedValues(const vector<Employee>& base) {
            vector<Employee> updated;
            int newID = 1;
            for (auto emp : base) {
                emp.ID = newID++;
                emp.YOS += 1;
                updated.push_back(emp);
            }
            writeAll(updated);
            cout << "Updated records with incremented IDs and years written to file.\n";
        }
};

int main() {
    CRUDManager manager("employees.txt");

    // Step 1: Create dummy data
    manager.initializeDummyData();

    // Step 2: Query (a)
    cout << "Query (a): Managers with at least 2 years of service:\n";
    vector<Employee> filtered = manager.filterManagersWithMinService();
    for (const auto& emp : filtered) {
        cout << emp.toCSV() << endl;
    }

    // Step 3: Query (b)
    manager.keepOnly(filtered);

    // Step 4: Query (c)
    manager.writeWithIncrementedValues(filtered);

    return 0;
}
