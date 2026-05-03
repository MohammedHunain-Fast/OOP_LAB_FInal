#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

int main() {
    vector <int> arr(5);
    ofstream fout;
    
    cout <<  "Enter input: ";
    for(int i = 0; i < 5; i++) cin >> arr[i];

    fout.open("List.txt");
    
    fout << "Orginal Data: \n";
    for(int i = 0; i < 5; i++) fout << arr[i] << " ";

    sort(arr.begin(), arr.end());

    fout << "\nSorted Data\n";

    for(int i = 0; i < 5; i++) fout << arr[i] << " ";

    fout.close();

    ifstream fin;

    fin.open("List.txt");

    char c;
    c = fin.get();
    while(!fin.eof()) {
        cout << c;
        c = fin.get();
    }
    fin.close();
    return 0;
}
