#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
public:
    string title;
    string author;
    string isbn;

    Book(string t, string a, string i) : title(t), author(a), isbn(i) {}

    void displayBookInfo() {
        cout << "Title: " << title << ", Author: " << author << ", ISBN: " << isbn << endl;
    }
};

class Catalog {
public:
    vector<Book*> books;

    void addBook(Book* book) {
        books.push_back(book);
    }

    Book* findBookByISBN(const string& isbn) {
        for (auto& book : books) {
            if (book->isbn == isbn) {
                return book;
            }
        }
        return nullptr;
    }
};

class Library {
private:
    Catalog catalog;

public:
    string name;
    string address;
    vector<Book*> bookCollection;

    Library(string n, string a) : name(n), address(a) {}

    void addBook(Book* book) {
        bookCollection.push_back(book);
        catalog.addBook(book); 
    }

    void removeBook(Book* book) {
        for (auto it = bookCollection.begin(); it != bookCollection.end(); ++it) {
            if (*it == book) {
                bookCollection.erase(it);
                break;
            }
        }

        for (auto it = catalog.books.begin(); it != catalog.books.end(); ++it) {
            if (*it == book) {
                catalog.books.erase(it);
                break;
            }
        }
    }

    Book* findBookInCatalog(const string& isbn) {
        return catalog.findBookByISBN(isbn);
    }

    void showLibraryInfo() {
        cout << "Library Name: " << name << endl;
        cout << "Library Address: " << address << endl;
    }

    void displayAllBooks() {
        cout << "Books in Library:" << endl;
        for (auto& book : bookCollection) {
            book->displayBookInfo();
        }
    }
};

int main() {
    Book book1("Sense and Sensibility", "Jane Austen", "123456");
    Book book2("Jane Eyre", "Charlotte Bronte", "654321");
    Book book3("Hobbit", "Tolkeins", "233445");

    Library library("Central Library", "123 Library St.");

    library.addBook(&book1);
    library.addBook(&book2);
    library.addBook(&book3);

    library.showLibraryInfo();
    library.displayAllBooks();

    string searchIsbn = "654321";
    Book* foundBook = library.findBookInCatalog(searchIsbn);
    if (foundBook) {
        cout << "Found Book: ";
        foundBook->displayBookInfo();
    } else {
        cout << "Book with ISBN " << searchIsbn << " not found in catalog." << endl;
    }

    library.removeBook(&book2);
    cout << "\nAfter removing a book:\n";
    library.displayAllBooks();

    return 0;
}
