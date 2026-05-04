#include <iostream>
#include <string>
using namespace std;

class Patient {
    protected:
        int patientID;
        string name;
        int age;
        int severity;
    public:
    Patient(int patientID, string name, int age, int severity) : patientID(patientID), name(name), age(age), severity(severity) {}  
        virtual double calculateBill() = 0;
        virtual void displayInfo() const = 0;
        virtual string getPriority() = 0;
        
        virtual  ~Patient() {}

};

class CardiacPatient : public Patient {
    public:
        int heartRate;
        bool requiresSurgery;
        double Bill;

        CardiacPatient(int patientID, string name, int age, int severity, int heartRate, bool requiresSurgery) : Patient(patientID, name, age, severity), heartRate(heartRate), requiresSurgery(requiresSurgery) {}

        string getPriority() override {
            if(severity >= 4) return "critical";
            else return "High";
        }
        double calculateBill() override {
            Bill = (severity * 15000) + (requiresSurgery ? 50000 : 0);
            return Bill;
        }
        void displayInfo() const override {
            cout << "Patient ID:" << patientID << "\n" << "Name: " << name << "\n" << "Age: " << age << "\n" << "Severity: " << severity << "\n" << "Heart rate: " << heartRate << "\n" << "Requires Surgery: " << requiresSurgery << "\n" << "Bill" << Bill << endl; 
        }
};

class TraumaPatient : public Patient {
    public: 
        string injuryType;
        int bloodUnitsRequired;
        double Bill;

        TraumaPatient(int patientID, string name, int age, int severity, string injuryType, int bloodUnitsRequired) : Patient(patientID, name, age, severity), injuryType(injuryType), bloodUnitsRequired(bloodUnitsRequired) {}

        string getPriority() override {
            if(bloodUnitsRequired > 3) return "Critical";
            else return "High";
        }
         double calculateBill() override {
            Bill = (severity * 8000) + (bloodUnitsRequired * 2500);
            return Bill;
        }

        void displayInfo() const override {
            cout << "Patient ID:" << patientID << "\n" << "Name: " << name << "\n" << "Age: " << age << "\n" << "Severity: " << severity << "\n" << "Injury type: " << injuryType << "\n" << "Blood units Required: " << bloodUnitsRequired << "\n" << "Bill" << Bill << endl; 
        }
};

class BurnPatient : public Patient {
    public:
        double burnPercentage;
        bool RequiresSkinGraft;
        double Bill;

        BurnPatient(int patientID, string name, int age, int severity, double burnPercentage, bool RequiresSkinGraft) :  Patient(patientID, name, age, severity), burnPercentage(burnPercentage), RequiresSkinGraft(RequiresSkinGraft) {}

        string getPriority() override {
            if(burnPercentage > 40.0) return "Critical";
            else return "High";
        }
        double calculateBill() override {
            Bill = (burnPercentage * 3000) + (RequiresSkinGraft ? 75000 : 0);
            return Bill;
        }
        void displayInfo() const override {
             cout << "Patient ID:" << patientID << "\n" << "Name: " << name << "\n" << "Age: " << age << "\n" << "Severity: " << severity << "\n" << "Burn Percentage: " << burnPercentage << "\n" << "Requires Skin Graft: " << RequiresSkinGraft << "\n" << "Bill" << Bill << endl; 
        }
};

class EmergencyWard {
    public:
        Patient** patients;
        int count;

        EmergencyWard() : count(0) {
            patients = new Patient*[10];
        }
        void admitPatient(Patient* p) {
            patients[count++] = p;
        }
        void displayAllPatients() {
            for(int i = 0; i < count; i++) {
                patients[i] -> displayInfo();
            }
        }
        double getTotalBilling() {
            double total = 0;
            for(int i = 0; i < count; i++) total += patients[i] -> calculateBill();
            return total;    
        }
        int getCriticalCount() {
            int criticalCount = 0;
            for(int i = 0; i < count; i++) {
                if (patients[i] -> getPriority() == "Critical") criticalCount++;
            }
            return criticalCount;
        }
        ~EmergencyWard() {
            delete[] patients;
        }

};

int main() {
    CardiacPatient cp(1, "John", 70, 4, 120, 1);
    TraumaPatient tp(2, "Jeff", 35, 4, "Brain", 0);
    BurnPatient bp(3, "Tom", 48, 4, 80, 1);
    EmergencyWard ew;
    ew.admitPatient(&cp);
    ew.admitPatient(&tp);
    ew.admitPatient(&bp);
    ew.displayAllPatients();
    ew.getTotalBilling();
    ew.getCriticalCount();
    return 0;
}
