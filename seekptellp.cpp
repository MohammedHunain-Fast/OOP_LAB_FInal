#include <iostream>
#include <fstream>
#include <string>
using namespace std;


 int main() {
    ofstream fout("List.txt", ios::binary);
    if(!fout) {
        cerr << "Failed to open file!\n";
        return 1;
    }
    fout.write("Hello", 5);
    streampos pos = fout.tellp();
    cout << "Position after write: " << pos << endl;
    fout.seekp(10, ios::beg);
    fout.write("World!", 6);
    pos = fout.tellp();
    cout << "Position after 2nd write: " << pos << endl;
    fout.close();
    return 0;
 }
