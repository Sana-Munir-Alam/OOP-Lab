#include <iostream>
#include <string>
using namespace std;

// Base Class
class Books{
    protected:
        string BookGenre;
    public:
        Books(string Genre) : BookGenre(Genre){
            // Paramatrized Constructor
        }
        virtual void Display(){
            cout << "Genre: " << BookGenre << endl;
        }
};

// Derived Class 1:
class Mystery : public Books{
    private:
        string Title;
        string Author;
    public:
        Mystery(string TName, string AName) : Books("Mystery"), Title(TName), Author(AName){
            // Paramatrized Constructor that calls Parent Constructir
        }
        void Display() override{
            cout << "-------------------------" << endl;
            Books::Display(); // Calling Parent Display
            cout << "Title: " << Title << endl;
            cout << "Author: " << Author << endl;
            cout << "-------------------------" << endl;
        }
};
// Derived Class 2:
class Fantasy : public Books{
    private:
        string Title;
        string Author;
    public:
        Fantasy(string TName, string AName) : Books("Fantasy"), Title(TName), Author(AName){
            // Paramatrized Constructor that calls Parent Constructir
        }
        void Display() override{
            cout << "-------------------------" << endl;
            Books::Display(); // Calling Parent Display
            cout << "Title: " << Title << endl;
            cout << "Author: " << Author << endl;
            cout << "-------------------------" << endl;
        }
};

int main(){
    Mystery Book1("The Broken Date", "R.L.Stine");
    Fantasy Book2("The Hobbit", "J.R.R Tolkein");

    Book1.Display();
    Book2.Display();
    return 0;
}
