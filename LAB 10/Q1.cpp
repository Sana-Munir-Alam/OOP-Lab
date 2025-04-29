#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Abstract Class
class IFlight {
    public:
        virtual bool BookSeat(int) = 0;
        virtual bool CancelSeat(int passengerID) = 0;
        virtual bool UpgradeSeat(int passengerID) = 0;
};


class Flight : public IFlight{
    private:
        string flightNumber;
        string departure;
        string arrival;
        int capacity;
        int bookedSeats;
        vector<int> passengerIDs; // stores IDs of booked passengers
    public:
        Flight(string fn, string dep, string arr, int cap) : flightNumber(fn), departure(dep), arrival(arr), capacity(cap), bookedSeats(0) {
            // Paramatrized Constructor
        }

        bool BookSeat(int passengerID) override {
            if (bookedSeats >= capacity) {
                cout << "[Booking Failed] Flight " << flightNumber << " is fully booked." << endl;
                return false;
            }
            // Check if passenger is already booked on the flight
            for (int ID : passengerIDs) {
                if (ID == passengerID) {
                    cout << "[Booking Failed] Passenger already booked this flight.\n";
                    return false;
                }
            }
            passengerIDs.push_back(passengerID);
            bookedSeats++;
            cout << "[Booking Success] Passenger " << passengerID << " booked on flight " << flightNumber << "." << endl;
            return true;
        }

        bool CancelSeat(int passengerID) override {
            for (size_t i = 0; i < passengerIDs.size(); ++i) {
                if (passengerIDs[i] == passengerID) {
                    passengerIDs.erase(passengerIDs.begin() + i);
                    bookedSeats--;
                    cout << "[Cancellation Success] Passenger " << passengerID << " removed from flight " << flightNumber << ".\n";
                    return true;
                }
            }
            cout << "[Cancellation Failed] Passenger " << passengerID << " not found on flight " << flightNumber << ".\n";
            return false;
        }

        bool UpgradeSeat(int passengerID) override {
            for (int ID : passengerIDs) {
                if (ID == passengerID) {
                    cout << "[Upgrade Success] Passenger " << passengerID << " upgraded on flight " << flightNumber << "." << endl;
                    return true;
                }
            }
            cout << "[Upgrade Failed] Passenger not booked." << endl;
            return false;
        }

        void displayFlightDetails() const {
            cout << "Flight: " << flightNumber << " | From: " << departure
                << " | To: " << arrival << " | Capacity: " << capacity
                << " | Booked Seats: " << bookedSeats << "\n";
        }
};

class Passenger {
    private:
        int ID;
        string name;
    public:
        Passenger(int pID, string pname) : ID(pID), name(pname) {
            // Paramatrized Constrcutor
        }

        bool requestBooking(Flight &flight) { return flight.BookSeat(ID); }
        bool requestCancel(Flight &flight) { return flight.CancelSeat(ID); }
        bool requestUpgrade(Flight &flight) { return flight.UpgradeSeat(ID); }

        void displayInfo() const { cout << "Passenger: " << name << " (ID: " << ID << ")" << endl; }
};

int main() {
    Flight f1("AI101", "New York", "London", 2);
    Flight f2("BA202", "Paris", "Tokyo", 1);

    Passenger p1(101, "Christopher");
    Passenger p2(102, "Richard");
    Passenger p3(103, "Edward");

    f1.displayFlightDetails();
    f2.displayFlightDetails();
    cout << endl;

    p1.requestBooking(f1);
    p2.requestBooking(f1);
    p3.requestBooking(f1); // Should fail (flight full)

    p2.requestCancel(f1);
    p3.requestBooking(f1); // Now should succeed
    p3.requestUpgrade(f1); // Should succeed

    cout << "\nFinal Flight States:\n";
    f1.displayFlightDetails();
    f2.displayFlightDetails();

    //Uncommenting below lines would cause compiler error.
    // f1.capacity--;
    // f1.bookedSeats++;

    return 0;
}