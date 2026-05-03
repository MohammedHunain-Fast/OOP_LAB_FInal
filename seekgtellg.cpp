#include <iostream>
#include <fstream>
#include <string>
using namespace std;


 int main() {
    ifstream fin("List.txt", ios::binary);
    if(!fin) {
        cerr << "Failed to open file!\n";
        return 1;
    }
    char buffer[6] = {0};
    fin.read(buffer,5);
    cout << "First 5  bytes: " << buffer << endl;
    fin.seekg(10, ios::beg);
    streampos pos = fin.tellg();
    cout << "current position: " << pos << endl;

    fin.read(buffer, 5);
    cout << "Bytes 10-14: " << buffer << endl;

    fin.close();

    return 0;
 }
