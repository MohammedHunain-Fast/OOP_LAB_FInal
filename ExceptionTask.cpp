#include <iostream>
#include <exception>
using namespace std;

class OutofBoundsException : public exception {
    public:
        const char* what() const throw() {
            return "OutOfBoundsException caught: Invalid index access attempted!";
        }
};

template <typename T>
class SmartArray {
    public:
        T *array;
        int n;
        
        SmartArray(int size) : n(size) {
            array = new T[n];
        }
        
        T& operator[](int index) {
            if(index >= n || index < 0) throw OutofBoundsException();
            return array[index];
        }
        
        void setElement(int index, T value) {
            if(index < n && index >= 0)
                array[index] = value;
        }

        ~SmartArray() {
            delete[] array;
        }
};

int main() {
    int n, val;
    cout << "Enter size of array: ";
    cin >> n;
    
    SmartArray<int> Arr(n);
    for(int i = 0; i < n; i++) {
        cout << "Enter Value of array " << i + 1 << ": ";
        cin >> val;
        Arr.setElement(i, val);
    }
    
    try {
        cout << "Value of Array[0]: " << Arr[0] << endl;
        cout << "Accessing invalid index... " << endl;
        cout << Arr[n] << endl; 
    }
    catch(const OutofBoundsException &e) {
        cout << e.what() << endl;
    }
    
    return 0;
}
