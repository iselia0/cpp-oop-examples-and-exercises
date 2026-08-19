#include <iostream>
#include <string>

using namespace std;

/*
    Exercise: Implement a Banking System

    In this exercise, you will create a basic banking system with the following classes:

    1. Account (Base Class):
        Create a base class called Account with the following attributes and methods:
        - accountNumber (integer)
        - balance (double)
        - Account(const int accountNumber, const double balance) constructor.
        - A virtual destructor for proper resource cleanup.
        - virtual void deposit(double amount) method to deposit funds into the account.
        - virtual void withdraw(double amount) method to withdraw funds from the account.
        - virtual void displayBalance() method to display the current balance.

    2. SavingsAccount (Derived Class):
        Create a derived class called SavingsAccount that inherits from Account. This class should include:
         - A constructor that takes an account number, initial balance, and an interest rate (e.g., 3%).
         - An overridden displayBalance() method that displays the current balance along with the interest rate.
         - An overridden withdraw() method that checks if the withdrawal amount is less than the balance and, if so, 
           processes the withdrawal. If the withdrawal amount exceeds the balance, display an error message.
    3.  CheckingAccount (Derived Class):
         - Create another derived class called CheckingAccount that inherits from Account. This class should include:
         - A constructor that takes an account number and initial balance.
         - An overridden displayBalance() method that displays the current balance along with a message indicating it's a checking account.
         - An overridden withdraw() method that checks if the withdrawal amount is less than the balance and, if so, 
           processes the withdrawal. If the withdrawal amount exceeds the balance, display an error message.
    4. Main Function:
        - In the main() function, create instances of both SavingsAccount and CheckingAccount. 
        - Deposit and withdraw funds from these accounts, and display their balances to demonstrate polymorphism.
    
    5. Proper Cleanup:
     - Make sure to delete the account objects at the end of the main() function to ensure that their destructors are called.
*/


class Account {
    public:
        // Constructor, virtual destructor, and methods go here
        Account(const int accountNumber, const double balance) : accountNumber_(accountNumber), balance_(balance) {}

        virtual ~Account() {
            cout << "Account " << accountNumber_ << " is being closed." << endl;
        }

        virtual void deposit(double amount) {
            balance_ += amount;
            cout << "Deposited $" << amount << " into Account " << accountNumber_ << endl;
        }

        virtual void withdraw(double amount) {
            if (amount <= balance_) {
                balance_ -= amount;
                cout << "Withdrawn $" << amount << " from Account " << accountNumber_ << endl;
            } else {
                cout << "Insufficient funds in Account " << accountNumber_ << endl;
            }
        }

        virtual void displayBalance() {
            cout << "Account " << accountNumber_ << " Balance: $" << balance_ << endl;
        }

    private:
        int accountNumber_;
        double balance_;
};


class SavingsAccount : public Account {
    public:
        // Constructor and overridden methods go here
        SavingsAccount(const int accountNumber, const double balance, double interestRate)
            : Account(accountNumber, balance), interestRate_(interestRate) {}

        void displayBalance() override {
            cout << " (Interest Rate: " << interestRate_ << "%)" << endl;
        }

    private:
        double interestRate_;
};


class CheckingAccount : public Account {
    public:
        // Constructor and overridden methods go here

        CheckingAccount(const int accountNumber, const double balance) : Account(accountNumber, balance) {}

        void displayBalance() override {
            cout << "Checking Account..." << endl;
        }
};


int main() {
    // Create instances of SavingsAccount and CheckingAccount
    // Deposit and withdraw funds, display balances
    // Properly clean up objects

    
    // Erase: 
    // Create SavingsAccount and CheckingAccount instances
    Account* savings = new SavingsAccount(1001, 1000.0, 3.0);  // Account Number, Initial Balance, Interest Rate
    Account* checking = new CheckingAccount(2001, 2000.0);     // Account Number, Initial Balance

    // Deposit and withdraw funds from accounts
    savings->deposit(500.0);
    checking->deposit(300.0);
    savings->withdraw(200.0);
    checking->withdraw(1000.0);

    // Display balances using polymorphism
    savings->displayBalance();
    checking->displayBalance();

    // Properly clean up objects
    delete savings;
    delete checking;

    return 0;
}
