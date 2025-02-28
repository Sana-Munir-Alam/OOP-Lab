#include <iostream>
using namespace std;

class Book{
	private:
		string Title;
		string Author;
		bool CheckAvailability;
	public:
		Book(){ // default
			Title = " ";
			Author = " ";
			CheckAvailability = true;
		}
		Book(string TName, string AName, bool Available) : Title(TName), Author(AName), CheckAvailability(Available){
			// Paramatrized Constructor
		}
		void SetTitle(string TName){ Title = TName; }
		void SetAuthor(string AName){ Author = AName; }
		void SetCheckAvailability(int Num){
			if (Num == 1){
				CheckAvailability = true;
			}else{
				CheckAvailability = false;
			}
		}
		string GetTitle() const {return Title;}
		string GetAuthor() const {return Author;}
		bool GetCheckAvailability() const {return CheckAvailability;}
		
		bool AvailableCheck(string BTitle, string BAuthor){
			if (Title == BTitle && Author == BAuthor){
				if (CheckAvailability){
					cout << "Book is Available" << endl;
					return CheckAvailability;
				}else{
					cout << "Book is not Available" << endl;
					return CheckAvailability;
				}
			}else {
				cout << "Sorry this book doesn't match our record" << endl;
			}
		}
		void Display(){
			cout << "Book Title: " << Title << endl;
			cout << "Book Author: " << Author << endl;
		}
		
		
};
class Member{
	private:
		int ID;
		string Name;
		Book *List;
		int BookCount;
	public:
		Member(){
			ID = 0;
			Name = " ";
			BookCount = 0;
			List = new Book[BookCount];
		}
		void BorrowBook(string BTitle, string BAuthor){
			if (List->AvailableCheck(BTitle, BAuthor)){ //if true
				List->SetCheckAvailability(0); // Set Book status to not available now
				cout << "Book Borrowed Successfully" <<endl;
				BookCount++;
			}else{
				cout << "As book is not avialble we can't' give it to you!";
			}
		}
		void ReturnBook(string BTitle){
			if (List->GetCheckAvailability()){ //if true
				List->SetCheckAvailability(1); // Set Book status to available now
				cout << "Book Returned Successfully" <<endl;
				BookCount--;
			}else{
				cout << "As book is not avialble we can give it to you!";
			}
		}
		void DisplayList(){
			for (int i = 0; i < BookCount l; i++){
				cout << "Book Title: " List->GetTitle() << endl;
				cout << "Book Author: " List->GetAuthor() << endl;
			}
		}
		
};

class Library{
	private:
		Book *BList;
		Member *MList;
		int BookCount;
		int MemberCount;
	public:
		
};
