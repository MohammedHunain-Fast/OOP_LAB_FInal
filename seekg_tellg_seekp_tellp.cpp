#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string quote = "Knowledge is power";
    fstream file("List.txt", ios::in | ios::out | ios::trunc | ios::binary);
    if(!file) {
        cerr <<  "File cannot be opened!\n";
        return 1;
    }
    file.write(quote.c_str(), quote.size());
    file.seekg(0);
    char buffer[6] = {0};
    file.read(buffer, 5);
    cout << "First 5 bytes :" << buffer << endl;
    file.seekp(13, ios::beg);
    file.write("POWER", 5);

    file.seekg(0);
    string content;
    getline(file, content, '\0');

    cout << "Final content: " << content << endl;

    file.close();

    return 0;
}
