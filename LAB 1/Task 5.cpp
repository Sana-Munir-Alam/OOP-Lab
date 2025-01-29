#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main(int argc, char* argv[]) {
    string MovieName;
    double AdultTicketPrice, ChildTicketPrice;
    int AdultTicketsSold, ChildTicketsSold, TotalTickets;
    double CharityPercentage, GrossAmount, AmountDonated, NetSale;

    cout << "Enter The Movie Name: ";
    getline(cin, MovieName);
    cout << "Enter The Adult Ticket Price: $";
    cin >> AdultTicketPrice;
    cout << "Enter The Child Ticket Price: $";
    cin >> ChildTicketPrice;
    cout << "Enter The Number of Adult Tickets Sold: ";
    cin >> AdultTicketsSold;
    cout << "Enter The Number of Child Tickets Sold: ";
    cin >> ChildTicketsSold;
    cout << "Enter The Percentage of Gross Amount To Be Donated: ";
    cin >> CharityPercentage;

    TotalTickets = AdultTicketsSold + ChildTicketsSold;
    GrossAmount = (AdultTicketsSold * AdultTicketPrice) + (ChildTicketsSold * ChildTicketPrice);
    AmountDonated = GrossAmount * (CharityPercentage / 100);
    NetSale = GrossAmount - AmountDonated;

    cout << fixed << setprecision(2); // Set decimal precision to 2

    cout << "\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
    cout << "Movie Name: .................................... " << MovieName << endl;
    cout << "Number of Tickets Sold: ........................ " << AdultTicketsSold + ChildTicketsSold << endl;
    cout << "Gross Amount: .................................. $ " << GrossAmount << endl;
    cout << "Percentage of Gross Amount Donated: ............ " << CharityPercentage << "%" << endl;
    cout << "Amount Donated: ................................ $ " << AmountDonated << endl;
    cout << "Net Sale: ...................................... $ " << NetSale << endl;
    return 0;
}
