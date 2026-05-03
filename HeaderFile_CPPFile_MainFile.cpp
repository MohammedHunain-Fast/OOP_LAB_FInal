//bankaccount.h
#pragma once

class BankAccount {
    private:
        int balance;
    public:
         BankAccount(int balance);
        void withdraw(int amount);
        void diposit(int amount);
        void display();
};

//bankaccount.cpp
#include "bankaccount.h"
#include <iostream>
using namespace std;

BankAccount :: BankAccount(int balance) : balance(balance) {}

void BankAccount :: diposit(int amount) {
    balance += amount;
    cout << "Deposited successfully\n";
}

void BankAccount :: withdraw(int amount) {
    balance -= amount;
    cout << "Withdrawed successfully!\n";
}

void BankAccount :: display() {
    cout << "Balance: " << balance << endl;
}
//main.cpp
#include <iostream>
#include "BankAccount.h"
using namespace std;
int main() {
    BankAccount b1(5000);
    b1.diposit(200);
    b1.display();
    b1.withdraw(2500);
    b1.display();

    return 0;
}
