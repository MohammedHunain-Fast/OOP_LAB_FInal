#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
    public:
        string name;
        int id;
        float marks;
};

void writetofile() {
    Student s;
    ofstream fout("Students.txt", ios::app);
    if(!fout) {
        cerr << "Unable to open!\n";
        exit(1);
    }
    cout << "Enter Student's Name: ";
    cin.ignore();
    getline(cin, s.name);
    cout << "Enter Student's ID: ";
    cin >> s.id;
    cout  << "Enter Student's Marks: ";
    cin >> s.marks;

    fout << s.name << ", " << s.id << " ," << s.marks << endl;
    cout << "Data written successfully!\n";

    fout.close();
    
}

void readfromfile() {
    ifstream fin("Students.txt", ios::in);
    if(!fin) {
        cerr << "Unable to open file!\n";
        exit(1);
    }
    string line;
    while(getline(fin, line)) {
        cout << line << endl;
    }
    cout << "File read successfully\n";

    fin.close();
}

int main() {
    int ch = 0;
    do{  
        cout << "1. Add Student Record\n"  << "2. View All Records\n" << "3. Exit" << endl;
        cin >> ch;
        switch(ch) {
            case 1: writetofile(); break;
            case 2: readfromfile(); break;
            case 3: cout << "Exiting...\n"; break;
            default: cout << "Invalid input\n"; break;
        }
    } while(ch != 3);

    return 0;
}
