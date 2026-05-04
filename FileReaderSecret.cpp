#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

class FileReader {
    private:
        char ch;
        int uppercase;
        public:
        FileReader(string filename) : uppercase(0) {
            ifstream fin(filename);
            if(!fin) throw "File failed to open!\n";
            while(fin.get(ch)) {
                if(isupper(ch)) uppercase++;
            }
            cout << "File read successfully!\n";
            fin.close();
            cout << "File closed!\n";
        }

        int getUpperCase() const{
            return uppercase;
        }
};

int main() {
    try {
    FileReader f1("secret.txt");
    cout << "Signal: " << f1.getUpperCase();
    }
    catch(const char* e)  {
        cout << "Exception occured: " << e <<  endl;
    }
    return 0;
}
