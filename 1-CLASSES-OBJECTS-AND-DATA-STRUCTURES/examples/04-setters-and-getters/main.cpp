#include <iostream>
#include <math.h>

using namespace std;


/*
    5. Setters and Getters
*/


/*
    Setters and Getters are methods to read or modify member variables of a class.
*/


class Rectangle {
    private:
        int width;
        int height;

    public:
        void setWidth(int w) {
            if (w > 0)
                width = w;
            else
                cout << "Invalid width!" << endl;
        }

        void setHeight(int h) {
            if (h > 0)
                height = h;
            else
                cout << "Invalid height!" << endl;
        }

        int getWidth() {
            return width;
        }

        int getHeight() {
            return height;
        }

        int calculateArea() {
            return width * height;
        }
};


class BankAccount {
    private:
        string accountNumber;
        double balance;

    public:
        void setAccountNumber(const string &accNum) {
            accountNumber = accNum;
        }

        void setBalance(double bal) {
            if (bal >= 0)
                balance = bal;
            else
                cout << "Invalid balance!" << endl;
        }

        string getAccountNumber() const {
            return accountNumber;
        }
        /*
            A constant member function in C++ is a member function of a class 
            that is declared with the "const" keyword. 
            It is a function that promises not to modify the state of the object on which it is called.
            This means that within a constant member function, you cannot modify any non-mutable member variables, 
            nor can you call any non-const member functions (unless they are also marked as mutable).

            1. The const keyword appears after the closing parenthesis of the function declaration, 
            but before the function body. It is part of the function's signature.
            2. Constant member functions are useful when you want to provide read-only access 
            to the object's data or perform operations that do not modify the object's state.

            Note: A constant member function in C++ can only be declared within member functions of a class!
        */

        double getBalance() const {
            return balance;
        }

        void deposit(double amount) {
            if (amount > 0)
                balance += amount;
            else
                cout << "Invalid deposit amount!" << endl;
        }

        void withdraw(double amount) {
            if (amount > 0 && amount <= balance)
                balance -= amount;
            else
                cout << "Invalid withdrawal amount or insufficient balance!" << endl;
        }
};




int main() {

    Rectangle rect;

    rect.setWidth(5);
    rect.setHeight(10);

    cout << "Width:  " << rect.getWidth() << endl;
    cout << "Height: " << rect.getHeight() << endl;
    cout << "Area:   " << rect.calculateArea() << endl << endl;

    /*
        Setters and Getters are methods to read or modify member variables of a class.

        Setters and getters, also known as accessor and mutator methods, 
        exist to provide a controlled way of accessing and modifying the internal state (data members) 
        of an object in object-oriented programming. 
        
        They serve several purposes:

        1. Encapsulation: Setters and getters help encapsulate the internal state of an object by providing 
        a public interface to access and modify private or protected data members. 
        This allows the object to maintain control over its own data and enforce data integrity.

        2. Data Validation: Setters can include validation logic 
        to ensure that only valid data is stored in the object's data members. 
        This helps maintain the consistency and integrity of the object's state 
        by preventing invalid or inappropriate values from being assigned.

        3. Abstraction: Setters and getters abstract away the internal representation of data 
        and provide a simplified interface for interacting with the object. 
        They allow the object to change its internal implementation details without affecting the external code that uses the object.

        4. Access Control: Setters and getters allow fine-grained control over the accessibility of data members. 
        By making the data members private and providing public getters and setters, 
        the object can enforce "read-only" or "write-only" access to specific properties, 
        enabling better control over the object's behavior.

        5. Code Maintenance and Flexibility: 
        By using setters and getters, you can easily add additional logic or functionality 
        in the future without changing the "external interface of the object". 
        This allows for easier maintenance, debugging, and "evolution" of the codebase.
    */


    BankAccount account;

    account.setAccountNumber("1234567890");
    account.setBalance(1000.0);

    cout << "Account Number: " << account.getAccountNumber() << endl;
    cout << "Balance: " << account.getBalance() << endl;

    account.deposit(500.0);
    cout << "New Balance after deposit: " << account.getBalance() << endl;

    account.withdraw(200.0);
    cout << "New Balance after withdrawal: " << account.getBalance() << endl;
}
