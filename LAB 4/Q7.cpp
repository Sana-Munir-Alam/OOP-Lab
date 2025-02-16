#include <iostream>
#include <string>
using namespace std;

class Book {
	private:
		string Author;
		string Title;
		string Publisher;
		double Price;
		int Stock;

	public:
		// Default Constructor
		Book(){
			Author = "";
			Title = "";
			Publisher = "";
			Price = 0.0;
			Stock = 0;
		}
		// Paramatrized Constructor
		Book(string Author, string Title, string Publisher, double Price, int Stock){
				this->Author = Author;
				this->Title = Title;
				this->Publisher = Publisher;
				this->Price = Price;
				this->Stock = Stock;
			}
		string GetAuthor() const {
			return Author;
		}
		string GetTitle() const {
			return Title;
		}
		string GetPublisher() const {
			return Publisher;
		}
		double GetPrice() const {
			return Price;
		}
		int GetStock() const {
			return Stock;
		}

		void CheckAvailability(int RequiredCopies) const {
			if (Stock >= RequiredCopies) {
				double TotalCost = Price * RequiredCopies;
				cout << "Book is available!" << endl;
				cout << "Total cost for " << RequiredCopies << " copies: $" << TotalCost << endl;
			} else {
				cout << "Required copies not in stock." << endl;
			}
		}
};

int main() {
    Book Inventory[] = {
        Book("J.K. Rowling", "Harry Potter and the Half Blood Prince", "Bloomsbury", 15.99, 10),
        Book("Charlotte Brontë", "Jane Eyre", "Smith, Elder & Co.", 12.50, 5),
        Book("Jane Austen", "Sense and Sensibility", "Thomas Egerton, Military Library (Whitehall, London)", 10.99, 3),
        Book("J.R.R. Tolkien", "The Hobbit", "Allen & Unwin", 14.95, 7)
    };

    int NumBooks = sizeof(Inventory) / sizeof(Inventory[0]);
	char Choice;
	do {
		string SearchTitle, SearchAuthor;
		cout << "Enter The Title of The Book: ";
		getline(cin, SearchTitle);
		cout << "Enter The Author of The Book: ";
		getline(cin, SearchAuthor);

		bool found = false;
		for (int i = 0; i < NumBooks; ++i) {
			if (Inventory[i].GetTitle() == SearchTitle && Inventory[i].GetAuthor() == SearchAuthor) {
				found = true;
				cout << "\nBook found!" << endl;
				cout << "Title: " << Inventory[i].GetTitle() << endl;
				cout << "Author: " << Inventory[i].GetAuthor() << endl;
				cout << "Publisher: " << Inventory[i].GetPublisher() << endl;
				cout << "Price: $" << Inventory[i].GetPrice() << endl;
				cout << "Stock: " << Inventory[i].GetStock() << endl;

				int RequiredCopies;
				cout << "\nEnter The Number of Copies Required: ";
				cin >> RequiredCopies;

				Inventory[i].CheckAvailability(RequiredCopies);
				break;
			}
		}
		if (!found) {
			cout << "Book not found in the inventory." << endl;
		}
		cin.ignore();

        cout << "\nDo you want to search for another book? (y/n): ";
        cin >> Choice;
        cin.ignore();
    } while (Choice == 'y' || Choice == 'Y');

    cout << "Thank You For Using The Bookshop System." << endl;
    return 0;
}
