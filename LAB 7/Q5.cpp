#include <iostream>
#include <vector>
using namespace std;

// Base Class: Media
class Media {
    protected:
        string Title, PublicationDate, UniqueID, Publisher;
        bool isAvailable;
    public:
        Media(string t, string pubDate, string id, string pub) : Title(t), PublicationDate(pubDate), UniqueID(id), Publisher(pub), isAvailable(true) {}

        virtual ~Media() {}

        virtual void DisplayInfo() const {
            cout << "Title: " << Title << endl << "Publication Date: " << PublicationDate << endl << "Unique ID: " << UniqueID << endl << "Publisher: " << Publisher << endl << "Status: " << (isAvailable ? "Available" : "Checked Out") << endl;
        }

        void CheckOut() {
            if (isAvailable) {
                isAvailable = false;
                cout << Title << " has been checked out." << endl;
            } else {
                cout << Title << " is currently unavailable." << endl;
            }
        }

        void ReturnItem() {
            if (!isAvailable) {
                isAvailable = true;
                cout << Title << " has been returned." << endl;
            } else {
                cout << Title << " was not checked out." << endl;
            }
        }

        string getTitle() const { return Title; }
        string getPublicationDate() const { return PublicationDate; }
};

// Derived Class: Book
class Book : public Media {
    private:
        string Author, ISBN;
        int NumberOfPages;
    public:
        Book(string t, string pubDate, string id, string pub, string auth, string isbn, int pages) : Media(t, pubDate, id, pub), Author(auth), ISBN(isbn), NumberOfPages(pages) {}

        void DisplayInfo() const override {
            cout << endl << "[Book Details]" << endl;
            Media::DisplayInfo();
            cout << "Author: " << Author << endl << "ISBN: " << ISBN << endl << "Pages: " << NumberOfPages << endl << "------------------------" << endl;
        }

        string getAuthor() const { return Author; }
};

// Derived Class: DVD
class DVD : public Media {
    private:
        string Director;
        double Duration;
        string Rating;
    public:
        DVD(string t, string pubDate, string id, string pub, string dir, double dur, string rate) : Media(t, pubDate, id, pub), Director(dir), Duration(dur), Rating(rate) {}

        void DisplayInfo() const override {
            cout << endl << "[DVD Details]" << endl;
            Media::DisplayInfo();
            cout << "Director: " << Director << endl << "Duration: " << Duration << " mins" << endl << "Rating: " << Rating << endl << "------------------------" << endl;
        }
};

// Derived Class: CD
class CD : public Media {
    private:
        string Artist, Genre;
        int NumberOfTracks;
    public:
        CD(string t, string pubDate, string id, string pub, string art, int tracks, string gen) : Media(t, pubDate, id, pub), Artist(art), NumberOfTracks(tracks), Genre(gen) {}

        void DisplayInfo() const override {
            cout << endl << "[CD Details]" << endl;
            Media::DisplayInfo();
            cout << "Artist: " << Artist << endl << "Tracks: " << NumberOfTracks << endl << "Genre: " << Genre << endl << "------------------------" << endl;
        }
};

// Derived Class: Magazine
class Magazine : public Media {
    private:
        int IssueNumber, Volume;
    public:
        Magazine(string t, string pubDate, string id, string pub, int issue, int vol) : Media(t, pubDate, id, pub), IssueNumber(issue), Volume(vol) {}

        void DisplayInfo() const override {
            cout << endl << "[Magazine Details]" << endl;
            Media::DisplayInfo();
            cout << "Issue Number: " << IssueNumber << endl << "Volume: " << Volume << endl << "------------------------" << endl;
        }
};

// Library System
class Library {
    private:
        vector<Media*> collection;
    public:
        void addMedia(Media* item) {
            collection.push_back(item);
        }
        // Overloaded Search Functions
        void searchMedia(string Title) {
            cout << endl << "Searching for Title: " << Title << endl;
            bool found = false;
            for (const auto& item : collection) {
                if (item->getTitle() == Title) {
                    item->DisplayInfo();
                    found = true;
                }
            }
            if (!found) {
                cout << "No media found wuth Title: " << Title << endl;
            }
        }

        void searchMediaByYear(string year) {
            cout << endl << "Searching for media published in: " << year << endl;
            bool found = false;
            for (const auto& item : collection) {
                if (item->getPublicationDate() == year) {
                    item->DisplayInfo();
                    found = true;
                }
            }
            if (!found) {
                cout << "No media found from year: " << year << endl;
            }
        }

        void searchMediaByAuthor(string Author) {
            cout << endl << "Searching for books by: " << Author << endl;
            bool found = false;
            for (const auto& item : collection) {
                Book* book = dynamic_cast<Book*>(item);
                if (book && book->getAuthor() == Author) {
                    book->DisplayInfo();
                    found = true;
                }
            }
            if (!found) {
                cout << "No books found by Author: " << Author << endl;
            }
        }

        void displayAllMedia() {
            cout << endl << "Library Collection:" << endl;
            for (const auto& item : collection) {
                item->DisplayInfo();
            }
        }
};

// Main Function
int main() {
    Library library;

    // Creating media objects
    Book* book1 = new Book("The Hobbit", "1937", "B001", "Allen & Unwin", "J.R.R. Tolkien", "978-0-395-07122-3", 310);
    DVD* dvd1 = new DVD("Inception", "2010", "D101", "Warner Bros", "Christopher Nolan", 148, "PG-13");
    CD* cd1 = new CD("Thriller", "1982", "C201", "Epic Records", "Michael Jackson", 9, "Pop");
    Magazine* mag1 = new Magazine("National Geographic", "2024", "M301", "NatGeo", 192, 67);

    // Adding items to the library
    library.addMedia(book1);
    library.addMedia(dvd1);
    library.addMedia(cd1);
    library.addMedia(mag1);

    // Display all media
    library.displayAllMedia();

    // Search by different attributes
    library.searchMedia("The Hobbit");
    library.searchMediaByYear("1982");
    library.searchMediaByAuthor("J.R.R. Tolkien");

    // Check out and return a book
    book1->CheckOut();
    book1->ReturnItem();

    delete book1;
    delete dvd1;
    delete cd1;
    delete mag1;

    return 0;
}
