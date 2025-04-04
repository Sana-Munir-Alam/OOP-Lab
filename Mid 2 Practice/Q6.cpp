#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Base Class
class PaymentMethod {
    public:
        virtual void Pay() const = 0;  // Example of method that would be overridden by subclasses
};
// Derived Class of Payment method
class CreditCard : public PaymentMethod {
    public:
        void Pay() const override {
            cout << "Paid via Credit Card." << std::endl;
        }
};
class DebitCard : public PaymentMethod {
    public:
        void Pay() const override {
            cout << "Paid via Debit Card." << std::endl;
        }
};

/*
Q)The Guest class contains a list of PaymentMethods (credit card, debit card, etc.). Is this composition or aggregation? Provide the reasoning based on lifecycle.

PaymentMethod objects may need to exist beyond the lifetime of the Guest. For example, a payment method (like a credit card) could be used by multiple guests or even be updated separately by external services. Hence, it makes sense to store them as pointers
*/

class Guest{
    private:
        string GuestName;
        vector<PaymentMethod*> Payment; //Agggregation
    public:
        // Parametrized constructor
        Guest(string Name) : GuestName(Name) {}

        void addPaymentMethod(PaymentMethod* Method) {
            Payment.push_back(Method);
        }
    
        void makePayment() const {
            for (auto Method : Payment) {
                Method->Pay();
            }
        }
        string GetName() const {return GuestName;}
};

class Room{
    private:
        string RoomNumber;
    public:
        Room(string Num) : RoomNumber(Num) {
            // Paramatrized Constructor
        }
        string getRoomNumber() const { return RoomNumber; }

};

/*
Q)Explain how you would allow for one-to-many relationships between Reservation and Room. Would you store these Room objects by value, pointer, or reference? Why?

The Reservation owns the Room objects. When the Reservation is created, it should also create the Room objects, and when the Reservation is destroyed, the Room objects should be destroyed as well. This is a form of composition.
Since the Room objects are small and doesn't require DMA.  we can store them directly by value in the Reservation
*/

class Reservation{
    private:
        Guest guest;         // Composition
        vector<Room> rooms;  // Composition
    public:
        Reservation(const Guest& g) : guest(g) {}  // Guest object is composed into the Reservation

        void AddRoom(const Room& room) {
            rooms.push_back(room);  // Add rooms to the reservation
        }

        void ShowReservationDetails() const {
            cout << "Reservation for guest: " << guest.GetName() << endl;
            for (const auto& room : rooms) {
                cout << "Room number: " << room.getRoomNumber() << endl;
            }
        }
        ~Reservation(){
            cout << "Reservation destroyed. Guest and all rooms are destroyed." << endl;
        }
};

int main() {
    // Create a Guest object
    Guest guest("John Doe");

    // Create PaymentMethod objects
    CreditCard creditCard;
    DebitCard debitCard;
    guest.addPaymentMethod(&creditCard);
    guest.addPaymentMethod(&debitCard);

    // Create a Reservation with the Guest object
    Reservation reservation(guest);

    // Add multiple rooms to the reservation
    reservation.AddRoom(Room("101"));
    reservation.AddRoom(Room("102"));

    // Show reservation details
    reservation.ShowReservationDetails();

    // Guest makes a payment
    guest.makePayment();

    // Reservation is automatically destroyed when it goes out of scope
    return 0;
}
