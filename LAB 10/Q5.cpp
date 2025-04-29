#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

const string filename = "tasks.txt";

// Load all tasks into memory
vector<string> loadTasks() {
    vector<string> tasks;
    ifstream inFile(filename);
    string line;

    while (getline(inFile, line)) {
        tasks.push_back(line);
    }

    inFile.close();
    return tasks;
}

// Display all tasks
void viewTasks() {
    vector<string> tasks = loadTasks();

    if (tasks.empty()) {
        cout << "No tasks available." << endl;
        return;
    }

    cout << "\nYour Tasks:" << endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i] << "" << endl;
    }
    cout << endl;
}

// Add a new task
void addTask(const string& task) {
    ofstream outFile(filename, ios::app);
    if (!outFile) {
        cerr << "Error opening file." << endl;
        return;
    }
    outFile << "[ ] " << task << "" << endl;
    outFile.close();
    cout << "Task added." << endl;
}

// Mark a task as done
void markDone(int taskNumber) {
    vector<string> tasks = loadTasks();

    if (taskNumber < 1 || taskNumber > (int)tasks.size()) {
        cout << "Invalid task number." << endl;
        return;
    }

    // Replace '[ ]' with '[x]'
    if (tasks[taskNumber - 1].substr(0, 3) == "[ ]") {
        tasks[taskNumber - 1].replace(0, 3, "[x]");
    } else {
        cout << "Task is already marked as done." << endl;
        return;
    }

    // Overwrite file
    ofstream outFile(filename);
    for (const string& t : tasks) {
        outFile << t << "" << endl;
    }

    cout << "Task marked as done." << endl;
}


int main() {
    int choice;
    string task;
    int taskNumber;

    do {
        cout << "====== To-Do List Menu ======" << endl;
        cout << "1. View Tasks" << endl;
        cout << "2. Add Task" << endl;
        cout << "3. Mark Task as Done" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear newline after int input

        switch (choice) {
            case 1:
                viewTasks();
                break;
            case 2:
                cout << "Enter task description: ";
                getline(cin, task);
                addTask(task);
                break;
            case 3:
                viewTasks();
                cout << "Enter task number to mark as done: ";
                cin >> taskNumber;
                markDone(taskNumber);
                break;
            case 0:
                cout << "Exiting." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 0);

    return 0;
}
