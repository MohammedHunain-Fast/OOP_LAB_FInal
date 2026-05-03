#include <iostream>
using namespace std;

template <typename T, typename U>
class Weight {
    private:
        T kg;
        U g;
    public:
        void Setkg(T kg) {
            this -> kg = kg;
        }
        void Setgrams(U g) {
            this -> g = g;
        }

        T getkg() { return kg; }
        U getgrams() { return g; }

};


int main() {
    Weight  <int, double> w1;
    w1.Setkg(5);
    w1.Setgrams(5000.600);
    cout << "KG: " << w1.getkg() << "\n" << "Grams: " << w1.getgrams() << endl;

    return 0;
}
