#include <iostream>
using namespace std;

    template <typename T>

    T divide(T a, T b) {
        try {
            if(!b) throw b;
        }
        catch(T b) {
            cout << "Can't divide by zero!\n";
        }
        return a / b;
    }

int main() {
    cout << "Result: " << divide<int>(12, 0) << endl;

    return 0;
}
