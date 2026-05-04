#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main() {
   try{
    ofstream fout("draft.txt", ios::out | ios::binary);
    if(!fout) throw "File Failed to open";
    fout.seekp(0);
    fout.write("He is teh king!", 15);
    fout.seekp(6, ios::beg);
    fout.write("the", 3);
    fout.close();
    ifstream fin("draft.txt", ios::in | ios::binary);
    if(!fin) throw "File Failed to open";
    char buffer[15] = {0};
    fin.seekg(0);
    fin.read(buffer, 15);
    cout << buffer << endl;
    fin.close();
   }
   catch(const char* e) {
        cout << "Exception occured: " << e << endl;
   }
   
    return 0;
}
