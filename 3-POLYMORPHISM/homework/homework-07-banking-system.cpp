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
        Account(const int accountNumber, const double balance)
            : accountNumber(accountNumber), balance(balance){}

        virtual ~Account(){}

        virtual void deposit(double amount){
            balance+=amount;
            cout<<"Deposited "<<amount<<" into Account "<<accountNumber<< " New balance: "<<balance<<endl;
        }

        virtual void withdraw(double amount){
            if(amount<=balance){
                balance-=amount;
                cout<<"Withdrew "<<amount<<" from Account "<<accountNumber<<" New balance: "<<balance<<endl;
            } 
            else{
                cout<<"Error - Insufficient funds in Account "<<accountNumber<<endl;
            }
        }

        virtual void displayBalance(){
            cout<<"Account "<<accountNumber<<" Balance: "<<balance<<endl;
        }

    protected:
        int accountNumber;
        double balance;

        
};


class SavingsAccount : public Account {
    public:
        // Constructor and overridden methods go here
        SavingsAccount(const int accountNumber, const double balance, const double interestRate)
            : Account(accountNumber, balance), interestRate(interestRate){}

        void displayBalance() override{
            cout<<"Savings Account "<<accountNumber<<" Balance: "<<balance<<" Interest Rate: " <<interestRate<<endl;
        }

        void withdraw(double amount) override{
            if(amount<balance){
                balance-=amount;
                cout<<"Withdrew "<<amount<<" from Savings Account "<<accountNumber<<" New balance: "<<balance<<endl;
            } 
            else{
                cout<<"Error: Withdrawal amount exceeds balance in Savings Account "<<accountNumber<<endl;
            }
        }

    private:
        double interestRate;

        
};


class CheckingAccount : public Account {
    public:
        // Constructor and overridden methods go here
        CheckingAccount(const int accountNumber, const double balance)
            : Account(accountNumber, balance){}

        void displayBalance() override{
            cout<<"Checking Account "<<accountNumber<<" Balance: "<<balance<<" This is a checking account"<<endl;
        }

        void withdraw(double amount) override{
            if(amount<balance){
                balance-=amount;
                cout<<"Withdrew "<<amount<<" from Checking Account "<<accountNumber<< " New balance: "<<balance<<endl;
            } 
            else{
                cout<<"Error- Withdrawal amount exceeds balance in Checking Account "<<accountNumber<<endl;
            }
        }
        
};


int main() {
    // Create instances of SavingsAccount and 
    // Deposit and withdraw funds, display balances
    // Properly clean up objects
    Account* savings=new SavingsAccount(1001, 1000.0, 3.0); 
    Account* checking=new CheckingAccount(2001, 2000.0); 

    savings->deposit(500.0);
    savings->withdraw(200.0);
    savings->withdraw(5000.0);

    checking->deposit(300.0);
    checking->withdraw(1000.0);
    checking->withdraw(10000.0);

    savings->displayBalance();
    checking->displayBalance();

    delete savings;
    delete checking;

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
