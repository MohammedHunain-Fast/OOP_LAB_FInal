#include <iostream>
using namespace std;

    template <typename T> 
    T add(T x, T y) {
        return x  + y;
    }

int main() {
    cout << add<int>(2, 3) << endl;
    cout << add<float>(3.5f, 6.7f) << endl;

    return 0;
}
