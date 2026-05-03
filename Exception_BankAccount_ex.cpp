#include <iostream>
#include <exception>
using namespace std;

class BankAccount {
    private:
        string name;
        int accno;
        double balance;
    public:
        BankAccount(string name, int accno, double balance) : name(name), accno(accno), balance(balance) {}

        void deposit(double amount) {
            if(amount <= 0) throw "Amount should be greater zero!\n";
            balance += amount;
            cout << "Deposited successfully!\n";
        }
        void withdraw(double amount) {
            if(amount > balance) throw "Amount cannot excceed balance!\n";
            balance -= amount;
            cout << "Withdrawed successfully!\n";
        }
        void display() const{
            cout << "Current Balance: " << balance << endl;
        }
} ;

int main() {
  BankAccount b1("Hunain", 1, 5000);
  try{
    b1.deposit(200);
    b1.display();
    b1.withdraw(200);
    b1.display();
  }
  catch(const char* e) {
    cout << "Exception occured: " << e << endl;
  }

    return 0;
}
