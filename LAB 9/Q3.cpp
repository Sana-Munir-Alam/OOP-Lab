#include <iostream>
#include <string>

using namespace std;

// PatientRecord class
class PatientRecord {
    private:
        string PatientName;
        string PatientID;
        string DateOfBirth;
        string MedicalHistory;
        string CurrentTreatments = "None";
        string BillingDetails;

        // Private method for updating sensitive medical information (Doctor role only)
        void updateMedicalHistory(const string& history) { MedicalHistory = history; }
        
        // Private method for adding billing details (Billing staff role only)
        void addBillingDetails(const string& billing) { BillingDetails = billing; }

    public:
        PatientRecord(const string& name, const string& id, const string& dob) : PatientName(name), PatientID(id), DateOfBirth(dob) {
            // Parameterized constructor
        }

        // Public method to get minimal data (accessible to anyone)
        string getPublicData() const {
            return "Name: " + PatientName + "\nID: " + PatientID + "\nDOB: " + DateOfBirth;
        }

        // Public method to get medical data (Doctor role only)
        string getMedicalData() const { return "Medical History: " + MedicalHistory + "\nCurrent Treatments: " + CurrentTreatments; }

        // Public method to get billing data (Billing staff role only)
        string getBillingData() const { return "Billing History: " + BillingDetails; }

        // Friend classes for authorized roles (Doctor and Billing staff)
        friend class Doctor;
        friend class Billing;
};

    // Doctor class - Has permission to modify and view sensitive medical data
class Doctor {
    public:
        // Method for doctor to update medical history
        void updateMedicalHistory(PatientRecord& record, const string& newHistory) {
            record.updateMedicalHistory(newHistory);
        }

        // Method for doctor to view sensitive medical data
        string getMedicalData(const PatientRecord& record) {
            return record.getMedicalData();
        }
};

    // Billing class - Has permission to update billing details and display billing info
class Billing {
    public:
        // Method for billing staff to add billing details
        void addBillingDetails(PatientRecord& record, const string& billingInfo) { record.addBillingDetails(billingInfo); }

        // Method for billing staff to view minimal public data
        string getPublicData(const PatientRecord& record) { return record.getPublicData(); }

        // Method for billing staff to view sensitive billing data
        string getBillingData(const PatientRecord& record) { return record.getBillingData(); }

        // Method to display the formatted billing data
        void displayBillingData(const PatientRecord& record) {
            string billing = record.getBillingData();
            cout << "\nBilling Details:\n";
            cout << billing << endl;
        }
};

// Receptionist class - Only has access to public data
class Receptionist {
    public:
        // Method for receptionist to view public data (no access to sensitive info)
        string getPublicData(const PatientRecord& record) { return record.getPublicData(); }

        // This would be prevented as the Receptionist class cannot access sensitive medical data
        void tryToAccessMedicalData(const PatientRecord& record) { cout << "Access Denied: Receptionist cannot access medical data." << endl; }

        // This would be prevented as the Receptionist class cannot access sensitive billing data
        void tryToAccessBillingData(const PatientRecord& record) { cout << "Access Denied: Receptionist cannot access billing data." << endl; }
};

// Access Control class to check role and limit access
class AccessControl {
public:
    // Function to control access based on role
    static void checkAccess(const string& role, const string& request) {
        if (role == "Doctor") {
            if (request == "MedicalData") {
                cout << "\nAccess granted: Doctor can view medical data.";
            } else {
                cout << "\nAccess granted: Doctor can view public data.";
            }
        } else if (role == "Billing") {
            if (request == "BillingData") {
                cout << "\nAccess granted: Billing Staff can view billing data.";
            } else {
                cout << "\nAccess granted: Billing Staff can view public data.";
            }
        } else if (role == "Receptionist") {
            if (request == "PublicData") {
                cout << "\nAccess granted: Receptionist can view public data.";
            } else {
                cout << "\nAccess Denied: Receptionist cannot access " << request << ".";
            }
        } else {
            cout << "\nAccess Denied: Role not recognized.";
        }
    }
};

int main() {
    PatientRecord patient("Richard Armitage", "123456", "1990-01-25");

    Doctor doctor;
    Billing billingStaff;
    Receptionist receptionist;

    // Test Doctor access to medical data
    AccessControl::checkAccess("Doctor", "MedicalData");
    doctor.updateMedicalHistory(patient, "Patient diagnosed with hypertension.");
    cout << "\nDoctor's View of Medical Data:\n" << doctor.getMedicalData(patient) << endl;

    // Test Billing Staff access to billing data
    AccessControl::checkAccess("Billing", "BillingData");
    billingStaff.addBillingDetails(patient, "Billing for January 2023: $500");
    billingStaff.displayBillingData(patient);

    // Test Receptionist access to various data
    AccessControl::checkAccess("Receptionist", "PublicData");
    cout << "\nReceptionist's View of Public Data:\n" << receptionist.getPublicData(patient) << endl;
    receptionist.tryToAccessMedicalData(patient);  // This should be denied
    receptionist.tryToAccessBillingData(patient);  // This should be denied

    return 0;
}
