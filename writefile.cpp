#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream fout;
    fout.open("List.txt");
    fout << "Prepare for OOP Final Exam";
    fout.close();

    return 0;
}
