#include <iostream>
#include <string>
using namespace std;

class Book{
	private:
		string BookName;
		string AuthorName;
		string Publisher;
		int ISBN;
	public:
		void SetBookName(string BookName){
			this->BookName = BookName;
		}
		string GetBookName(){
			return BookName;
		}
		void SetAuthorName(string AuthorName){
			this->AuthorName = AuthorName;
		}
		string GetAuthorName(){
			return AuthorName;
		}
		void SetPublisher(string Publisher){
			this->Publisher = Publisher;
		}
		string GetPublisher(){
			return Publisher;
		}
		void SetISBN (int ISBN){
			this->ISBN = ISBN;
		}
		int GetISBN (){
			return ISBN;
		}
		string GetBookInfo(){
			return "Book Name: " + BookName + "\n" +
               "Author Name: " + AuthorName + "\n" +
               "Publisher: " + Publisher + "\n" +
               "ISBN: " + to_string(ISBN) + "\n";
		}
};

int main(int argc, char* argv[]){
    Book BookTest[5];
	for (int i = 0; i < 5; i++){
		string B = "",A = "",P = "";
		int Code;
        cout << "Enter details for Book " << i + 1 << endl;
		cout << "Enter Book Name: ";
		getline(cin, B);
		BookTest[i].SetBookName(B);
		cout << "Enter Author Name: ";
		getline(cin, A);
		BookTest[i].SetAuthorName(A);
		cout << "Enter Publisher Name: ";
		getline(cin, P);
		BookTest[i].SetPublisher(P);
		cout << "Enter ISBN: ";
		cin >> Code;
        cin.ignore();
		BookTest[i].SetISBN(Code);
        cout << endl;
	}
    cout << "-----------------------------------"<<endl;
    cout << "Book Information:\n";
    for (int i = 0; i < 5; i++) {
        cout << "Book " << i + 1 << ":\n";
        cout << BookTest[i].GetBookInfo() << endl;
    }
	return 0;
}
