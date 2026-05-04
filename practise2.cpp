#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class MissionVault {
private:
    string* log_entries;
    int* log_sizes;
    int entry_count = 0;
    int max_capacity;
    int cipher_key;

public:
    MissionVault(int capacity, int key) : max_capacity(capacity), cipher_key(key) {
        log_entries = new string[max_capacity];
        log_sizes = new int[max_capacity]; 
    }

    void storeReport(string report) {
        if (entry_count >= max_capacity) 
            throw runtime_error("Vault is full. Cannot store more reports."); //

        for (int i = 0; i < report.length(); i++) {
            if (isalpha(report[i])) {
                char base = isupper(report[i]) ? 'A' : 'a';
                report[i] = (report[i] - base + cipher_key) % 26 + base;
            }
        }
        
        log_sizes[entry_count] = report.length(); 
        log_entries[entry_count++] = report;
    }

    void removeLastReport() {
        if (entry_count == 0) 
            throw runtime_error("Vault is empty. Nothing to remove."); 
        entry_count--;
    }

    int getEntryCount() const { return entry_count; }

    ~MissionVault() {
        delete[] log_entries;
        delete[] log_sizes; 
    }

    friend class IntelAgent; 
};

class IntelAgent {
private:
    string agentName;
    int clearanceLevel;
    int decryptKey;

public:
    IntelAgent(string name, int level, int key) 
        : agentName(name), clearanceLevel(level), decryptKey(key) {}

    void inspectVault(MissionVault& vault) {
        cout << "\n=== VAULT INSPECTION ===\n";
        cout << "Agent: " << agentName << " | Entries: " << vault.entry_count << endl;
        cout << "Capacity: " << vault.max_capacity << " | Key: " << vault.cipher_key << endl;
        for (int i = 0; i < vault.entry_count; i++) {
            cout << "Entry " << i + 1 << ": " << vault.log_entries[i] << endl;
        }
    }

    void decryptAndRead(MissionVault& vault) {
        cout << "\n=== DECRYPTED REPORTS ===\n";
        for (int i = 0; i < vault.entry_count; i++) {
            string decrypted = vault.log_entries[i];
            for (int k = 0; k < decrypted.length(); k++) {
                if (isalpha(decrypted[k])) {
                    char base = isupper(decrypted[k]) ? 'A' : 'a';
                    decrypted[k] = (decrypted[k] - base - decryptKey + 26) % 26 + base;
                }
            }
            cout << "Report " << i + 1 << ": " << decrypted << endl;
        }
    }

    void submitReport(MissionVault& vault, string report) {
        try {
            if (report.empty()) {
                vault.storeReport("No Activity Logged");
            } else {
                vault.storeReport(report);
            }
            cout << "Report stored successfully." << endl;
        } catch (const runtime_error& e) {
            cout << "EXCEPTION: " << e.what() << endl;
        }
    }
};

int main() {
    try {
        MissionVault mv(3, 3);
        IntelAgent ia("Agent47", 5, 3);

        ia.submitReport(mv, "Operation Alpha");
        ia.submitReport(mv, "Kill Netanyahu");
        ia.submitReport(mv, "Evac Successful");
        ia.submitReport(mv, "Extra Report");

        ia.inspectVault(mv);
        ia.decryptAndRead(mv);

        mv.removeLastReport();
        cout << "Last report removed." << endl;
        
    } catch (const exception& e) {
        cout << "Fatal Error: " << e.what() << endl;
    }
    return 0;
}
