#include <iostream>
#include <string>
using namespace std;

class BankAccount {
protected:
    int accNumber;
    string ownerName;
    double balance;

public:
    BankAccount(int accNum, string name, double balik)
        : accountNumber(accNum), ownerName(name), balance(balik) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << ". New Balance: " << balance << endl;
        } else {
            cout << "Invalid!" << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdraw: " << amount << ". New Balance: " << balance << endl;
        } else {
            cout << "Invalid!" << endl;
        }
    }

    void display() const {
        cout << "Account Number: " << accNumber
             << ", Owner: " << ownerName
             << ", Balance: " << balance << endl;
    }
};

class SavingsAccount : public BankAccount {
private:
    double prRate; 
public:
    SavingsAccount(int accNum, string name, double balik, double rate)
        : BankAccount(accNum, name, balik), prRate(rate) {}

    void applyPercents() {
        double percents = balance * (prRate / 100);
        balance += percents;
        cout << "Percents Applied: " << percents << ". New Balance: " << balance << endl;
    }

    void display() const {
        BankAccount::display();
        cout << "Percents Rate: " << prRate << "%" << endl;
    }
};

int main() {
    BankAccount account1(1, "Ridiger Valentin", 500.0);
    account.display();
    account.deposit(200.0);
    account.withdraw(100.0);
    account.display();

    cout << endl;

    SavingsAccount saving(2, "Thomas Shelby", 1000.0, 5.0);
    saving.display();
    saving.deposit(300.0);
    saving.withdraw(500.0);
    saving.applyPercents();
    saving.display();

    return 0;
}
