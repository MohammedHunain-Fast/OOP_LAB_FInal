#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin;
    fin.open("List.txt");
    char c;
    // fin >> c;        //Here there will be no space
    c = fin.get();

    while(!fin.eof()) {
        cout << c;
        // fin >> c;    //Here there will be no space
        c = fin.get();
    }

    fin.close();

    return 0;
}
