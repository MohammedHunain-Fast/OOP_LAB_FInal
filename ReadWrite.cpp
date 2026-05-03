#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

int main() {
    ofstream fout;
    fout.open("List.txt");

    fout << "Hello Hunain!\n";
    fout << "Hello Zain!\n";
    fout << "Hello Rania!\n";

    fout.close();

    ifstream fin;
    fin.open("List.txt");
    string line;
    while(getline(fin,line)) {
        cout << line << endl;
    }
    
    fin.close();

    return 0;
}
