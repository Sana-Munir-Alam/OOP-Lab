#include <iostream>
using namespace std;

class Book{
	private:
		string BookName;
		string AuthorName;
		string Publisher;
		int ISBN;
	public:
		void setBookName(string BookName){
			this->BookName = BookName;
		}
		string GetBookName(){
			return BookName;
		}
		void setAuthorName(string AuthorName){
			this->AuthorName = AuthorName;
		}
		string GetAuthorName(){
			return AuthorName;
		}
		void setPublisher(string Publisher){
			this->Publisher = Publisher;
		}
		string GetPublisher(){
			return Pub;
		}
		void setISBN (int ISBN){
			this->ISBN = ISBN;
		}
		int ISBN (){
			return ISBN;
		}
		void GetBookInfo(){
			
		}
};

int main(int argc, char* argv[]){
	if (argc != 7){
		cout << "Incorrect Data Format Entered!! Kinldy follow this pattern" << endl;
		return 1;
	}
	
	Book BookTest[5];
	for (int i = 0; i < 5; i++){
		string B = "",A = "",P = "";
		int Code;
		cout << "Enter Book Name: ";
		getline(cin, B);
		BookTest[i].setBookName(B);
		cout << "Enter Author Name: ";
		getline(cin, A);
		BookTest[i].setAuthorName(A);
		cout << "Enter Publisher Name: ";
		getline(cin, P);
		BookTest[i].setPublisherName(P);
		cout << "Enter Author Name: ";
		cin << Code;
		BookTest[i].setISBN(Code)
	}
	return 0;
}
