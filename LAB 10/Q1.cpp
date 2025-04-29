#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to encrypt the input string
string encrypt(const string& input) {
    string encrypted = input;
    for (size_t i = 0; i < input.length(); ++i) {
        encrypted[i] = input[i] + (i + 1);
    }
    return encrypted;
}

// Function to decrypt the encrypted string
string decrypt(const string& encrypted) {
    string decrypted = encrypted;
    for (size_t i = 0; i < encrypted.length(); ++i) {
        decrypted[i] = encrypted[i] - (i + 1);
    }
    return decrypted;
}

int main() {
    string input;
    cout << "Enter String: ";
    getline(cin, input);
    string encrypted = encrypt(input);

    // Write encrypted text to file
    ofstream outFile("encrypted.txt");
    if (!outFile) {
        cerr << "Error creating file!" << endl;
        return 1;
    }
    outFile << encrypted;
    outFile.close();

    cout << "\nNormal Text:= " << input << endl;
    cout << "Encrypted text inserted in file: " << encrypted << endl;

    // Open the encrypted text file for reading
    ifstream inFile("encrypted.txt");
    if (!inFile) {
        cerr << "Error reading file!" << endl;
        return 1;
    }

    string fileEncrypted;           // Variable to store in the content of the file
    getline(inFile, fileEncrypted); // Read the entire line
    inFile.close();

    string decrypted = decrypt(fileEncrypted);
    cout << "Decrypted text Read then decoded from file: " << decrypted << endl;

    return 0;
}
