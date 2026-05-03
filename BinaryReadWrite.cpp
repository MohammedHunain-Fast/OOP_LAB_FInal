#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
    public:
        string name;
        int id;
};

int main() {
    Student s1 = {"Hunain", 68};
    ofstream fout("Student.dat", ios::binary);
    fout.write((char*)&s1, sizeof(s1));
    fout.close();
    Student s2;
    ifstream fin("Student.dat", ios::binary);
    fin.read((char*)&s2, sizeof(s2));
    fin.close();

    cout << s2.name << "\n" << s2.id << endl;
    return 0;
}
