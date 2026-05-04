#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

class FileWriter {
    private:
        string timestamp;
    public:
        FileWriter(string timestamp) : timestamp(timestamp) {
            ofstream fout("system_log.txt", ios::app);
            if(!fout) {
                throw "Failed to open file!\n";
            }
            fout << "System started: " << timestamp;
            cout << "Data written succesfully\n";

                fout.close();
                cout << "File closed!\n";
        }
};

int main() {
    time_t now = time(0);
    char* dt = ctime(&now);
    try{
    FileWriter f1(dt);
    }
    catch(const char* e) {
        cout << "Exception occured: " << e << endl;
    }
    return 0;
}
