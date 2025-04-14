#include <iostream>
#include <string>

using namespace std;

class Doctor;
class Billing;

class PatientRecord {
    private:
        string name;
        string id;
        string dob;

        string medicalHistory;
        string currentTreatment;
        string billingDetails;

        void updateMedicalHistory(const  string& history, const  string& treatment) {
            medicalHistory = history;
            currentTreatment = treatment;
        }
        void addBillingDetails(const  string& billing) { billingDetails = billing; }
    public:
        // Allow access only to Doctor and Billing classes
        friend class Doctor;
        friend class Billing;

        PatientRecord( string n,  string i,  string d) : name(n), id(i), dob(d), medicalHistory("None"), currentTreatment("None"), billingDetails("None") {}

        string getPublicData() const { return "Name: " + name + ", ID: " + id + ", DOB: " + dob; }
        
        // Medical-related access
        string getMedicalData() const { return "Medical History: " + medicalHistory + ", Current Treatment: " + currentTreatment; }
        // Billing-related access
        string getBillingData() const { return "Billing Details: " + billingDetails; }
};

// Doctor class
class Doctor {
    public:
        void viewMedicalData(const PatientRecord& record) const {
            cout << "[Doctor] Viewing Medical Data:\n" << record.getMedicalData() << "\n";
        }
        void updateMedicalRecord(PatientRecord& record, const  string& history, const  string& treatment) {
            cout << endl << "[Doctor] Updating medical record...\n";
            record.updateMedicalHistory(history, treatment);
        }
};

// Billing class
class Billing {
public:
    void viewBillingData(const PatientRecord& record) const {
        cout << "[Billing] Viewing Billing Data:\n" << record.getBillingData() << "\n";
    }

    void updateBillingInfo(PatientRecord& record, const  string& billing) {
        cout << endl << "[Billing] Updating billing information...\n";
        record.addBillingDetails(billing);
    }
};

// Receptionist class — must not access sensitive data
class Receptionist {
public:
    void viewPublicData(const PatientRecord& record) const {
        cout << "[Receptionist] Viewing Public Data:\n" << record.getPublicData() << "\n";
    }

    /*
    // The following would cause compile-time errors if uncommented

    void tryToViewMedicalData(const PatientRecord& record) { out << record.getMedicalData(); }                          // Not allowed! 
    void tryToUpdateMedicalRecord(PatientRecord& record) { record.updateMedicalHistory("Hack!", "Unauthorized"); }      // Not allowed!
    void tryToViewBillingData(const PatientRecord& record) { cout << record.getBillingData(); }                         // Not allowed! 
    */
};

int main() {
    PatientRecord record("CHristopher Brandon", "HOB123", "Sep 22, 1890");

    Doctor doc;
    Billing bill;
    Receptionist reception;

     cout << endl << "=== Receptionist trying to view public data ===\n";
    reception.viewPublicData(record);

     cout << "\n=== Doctor viewing and updating medical data ===\n";
    doc.viewMedicalData(record);
    doc.updateMedicalRecord(record, "Mild fever", "Rest and herbal tea");
    doc.viewMedicalData(record);

     cout << "\n=== Billing staff viewing and updating billing data ===\n";
    bill.viewBillingData(record);
    bill.updateBillingInfo(record, "Invoice #42: 10 gold coins");
    bill.viewBillingData(record);

     cout << "\n=== Receptionist trying to access sensitive data (uncomment to test compile failure) ===\n";
    // Uncommenting the below lines will cause compile-time errors due to access restrictions
    // reception.tryToViewMedicalData(record);
    // reception.tryToUpdateMedicalRecord(record);
    // reception.tryToViewBillingData(record);

    return 0;
}
