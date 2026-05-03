#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FileHandler {
    private:
        ofstream fout;
        string fileName;
    public:
        FileHandler(string fileName) : fileName(fileName) {
            fout.open(fileName);
             if(!fout) {
                cout << "Error: File could not be created!\n";
                exit(1);
             }
        }
       void writeData(string data) {
        if(fout.is_open()) fout << data << endl;
        cout << "Data written to the file successfully!\n";
       }

       void closeFile() {
        if(fout.is_open()) fout.close();
        cout << "File closed!\n";
       }
        
};

int main() {
    FileHandler f1("List.txt");
    f1.writeData("Hi Hunain!\n");
    f1.closeFile();
    return 0;
}
