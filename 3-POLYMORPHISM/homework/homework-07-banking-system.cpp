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

        
};


class SavingsAccount : public Account {
    public:
        // Constructor and overridden methods go here

        
};


class CheckingAccount : public Account {
    public:
        // Constructor and overridden methods go here

        
};


int main() {
    // Create instances of SavingsAccount and CheckingAccount
    // Deposit and withdraw funds, display balances
    // Properly clean up objects

    /*
        Erase: 

        // Create SavingsAccount and CheckingAccount instances
        Account* savings = new SavingsAccount(1001, 1000.0, 3.0); // Account Number, Initial Balance, Interest Rate
        Account* checking = new CheckingAccount(2001, 2000.0);     // Account Number, Initial Balance

        // Deposit and withdraw funds from accounts
        

        // Display balances using polymorphism
        

        // Properly clean up objects
        
    */

    return 0;
}
