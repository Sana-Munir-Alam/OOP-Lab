#include <iostream>
#include <fstream>
using namespace std;

/*
int main(){
    ofstream file ("Lab10.txt");                                            // Open File for writing
    string Input;
    cout << "Enter the Normal Text: ";
    getline(cin, Input);                                                    // Take Input from User include whitspace
    file << Input << endl;                                                  // Store the text which is to be encrypted
    file.close();                                                           // Close file

    ifstream infile("Lab10.txt");
    if(!infile){                                                            // Check if file opened
        cerr << "Error!! file could not be open for reading" << endl;       // Print Error message
        return 1;                                                           // Exit function with error  
    }
    string Line="";                                                         // Varaible to store each Line of the file
    int pos = 0;
    char ch;
    int n;                                                                  // Varaibel to store Ascii encrypt
    while (infile.get(ch)){                                                 // Reading character by character
        n = pos + int(ch);                                                  // Doing Encryption
        Line += char(n);                                                    // Store encrypted character
        pos++;                                                              // Increase position index
    }
    infile.close();                                                         // Close File   
    ofstream outFile("Lab10.txt", ios:: app);
    outFile << "Encrypted Test: ";
    outFile << Line;
    outFile.close();
}
*/

int main(){
    
}
