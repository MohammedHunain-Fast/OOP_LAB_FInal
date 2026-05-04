#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Student {
    char name[50]; 
    int id;
    float gpa;
};

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student* s = new Student[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter Name for Student " << i + 1 << ": ";
        cin.ignore();
        cin.getline(s[i].name, 50);
        cout << "Enter ID: ";
        cin >> s[i].id;
        cout << "Enter GPA: ";
        cin >> s[i].gpa;
    }

    try {
        ofstream fout("students.dat", ios::binary);
        if (!fout) throw "File failed to open for writing!";
        
        for (int i = 0; i < n; i++) {
            fout.write((char*)&s[i], sizeof(Student));
        }
        fout.close();

      
        ifstream fin("students.dat", ios::binary);
        if (!fin) throw "File failed to open for reading!";

        cout << "\n--- Student Records ---\n";
        Student temp;
        while (fin.read((char*)&temp, sizeof(Student))) {
            cout << "Name: " << temp.name << " | ID: " << temp.id << " | GPA: " << temp.gpa << endl;
        }
        fin.close();

    } catch (const char* e) {
        cout << "Exception occurred: " << e << endl;
    }

    delete[] s; 
    return 0;
}
