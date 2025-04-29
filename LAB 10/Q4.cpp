#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

const string baseFile = "log.txt";
const size_t maxFileSize = 1 * 1024 * 1024; // 1 MB

// Check size and rotate if needed
void rotateLogs() {
    if (fs::exists(baseFile) && fs::file_size(baseFile) >= maxFileSize) {
        int index = 1;
        string newFile;

        do {
            newFile = "log" + to_string(index++) + ".txt";
        } while (fs::exists(newFile));

        fs::rename(baseFile, newFile);
    }
}

// Write a single log line
void writeLog(const string& message) {
    rotateLogs();

    ofstream outFile(baseFile, ios::app);
    if (!outFile) {
        cerr << "Failed to open log file.\n";
        return;
    }

    outFile << message << endl;
    outFile.close();
}

int main() {
    for (int i = 0; i < 200000; ++i) {                      // Writing this many number in files creates total of 5 log files.
        writeLog("Log entry number: " + to_string(i));
    }

    cout << "Logging complete.\n";
    return 0;
}
